/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

static corto_int32 constructOnce;

int16_t corto_loader_construct(
    corto_loader this)
{
    if (corto_ainc(&constructOnce) == 1) {
        corto_query *q = &corto_subscriber(this)->query;
        corto_set_str(&q->select, "//*");
        corto_set_str(&q->from, "/");
        corto_set_str(&q->type, "package");
        corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
        if (safe_corto_mount_setContentType(this, "text/json")) {
            return -1;
        }
        corto_mount(this)->filter_results = false;

        return safe_corto_mount_construct(this);
    } else {
        corto_throw("cannot create multiple instances of vstore/loader");
        return -1;
    }
}

void corto_loader_destruct(
    corto_loader this)
{
    corto_assert(
        corto_adec(&constructOnce) >= 0, "loader destructed too many times");
    safe_corto_mount_destruct(this);
}

static
void corto_loader_iterRelease(
    corto_iter *iter)
{
    corto_ll_iter_s *data = iter->ctx;

    /* Delete data from request */
    corto_iter it = corto_ll_iter(data->list);
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_ptr_deinit(r, corto_result_o);
        corto_dealloc(r);
    }
    corto_ll_free(data->list);

    /* Call iter release function that was overridden by this function */
    corto_ll_iterRelease(iter);
}

static
bool corto_loader_checkIfAdded(
    corto_ll list,
    corto_string name)
{
    corto_iter it = corto_ll_iter(list);
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        if (!stricmp(r->id, name)) {
            return TRUE;
        }
    }
    return FALSE;
}

static
void corto_loader_addDir(
    corto_ll list,
    const char* path,
    corto_query *q)
{
    char *package_path = (char*)path;

    if (q->from[0] != '.') {
        package_path = corto_asprintf("%s/%s", path, q->from);
    }
    corto_ll dirs = corto_opendir(package_path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_ll_iter(dirs);

        while (corto_iter_hasNext(&iter)) {
            corto_string f = corto_iter_next(&iter);

            if (!corto_loader_checkIfAdded(list, f) &&
                corto_idmatch(q->select, f))
            {
                struct stat attr;

                corto_id fpath;
                sprintf(fpath, "%s/%s", package_path, f);
                if (!corto_file_test(fpath)) {
                    continue;
                }

                /* Stat file to determine whether it's a directory */
                if (stat(fpath, &attr) < 0) {
                    corto_throw("failed to stat '%s' (%s)\n",
                        fpath,
                        strerror(errno));
                }

                if (!S_ISDIR(attr.st_mode)) {
                    /* Ignore files */
                    continue;
                }

                corto_id package;
                sprintf(package, "%s/%s", q->from, f);
                corto_path_clean(package, package);

                corto_result *result = corto_calloc(sizeof(corto_result));

                corto_id packageFile;
                sprintf(packageFile, "%s/project.json", fpath);
                if (corto_file_test(packageFile)) {
                    char *json = corto_file_load(packageFile);
                    corto_result_fromcontent(result, "text/json", json);
                } else {
                    result->id = corto_strdup(f);
                    result->type = corto_strdup("package");
                    result->value = (uintptr_t)strdup("{}");
                }

                corto_set_str(&result->parent, q->from);

                /* because the corto object is not persistent, but because the
                 * mount does have objects under the corto scope, hide the corto
                 * object from the mount for the user, but let corto_select know
                 * that more objects may be available. */
                if (!strcmp(package, "corto")) {
                    result->flags = CORTO_RESULT_HIDDEN;
                } else {
                    result->flags = 0;
                }

                corto_ll_append(list, result);
            }
        }

        /* Free up resources of opendir */
        corto_closedir(dirs);
    } else {
        /* Catch error logged by corto_opendir */
        corto_catch();
    }

    if (package_path != path) {
        free(package_path);
    }
}

corto_resultIter corto_loader_on_query_v(
    corto_loader this,
    corto_query *query)
{
    corto_ll data = corto_ll_new(); /* Will contain result of request */
    corto_iter result;
    const char *targetPath = corto_load_targetMetaPath();
    const char *homePath = corto_load_homeMetaPath();

    corto_log_push_dbg("vstore-loader");

    CORTO_UNUSED(this);

    corto_loader_addDir(data, targetPath, query);

    if (strcmp(targetPath, homePath)) {
        corto_loader_addDir(data, homePath, query);
    }

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_ll_iterAlloc(data);
    result.release = corto_loader_iterRelease;

    corto_log_pop_dbg();

    return result;
}

static
corto_object corto_loader_create_package(
    corto_loader this,
    corto_object o,
    const char *id,
    const char *path)
{
    char *project_file = corto_asprintf("%s/project.json", path);
    if (corto_file_test(project_file) == 1) {
        char *json = corto_file_load(project_file);
        if (corto_deserialize(&o, "text/json", json)) {
            free(json);
            goto error;
        }
        free(json);
    }

    free (project_file);
    return o;
error:
    free (project_file);
    return NULL;
}

int16_t corto_loader_on_resume(
    corto_loader this,
    const char *parent,
    const char *id,
    corto_object *object)
{
    corto_log_push_dbg("vstore-loader:resume");

    /* The loader may be asked to resume objects that are not packages, but live
     * inside a package. Therefore it will attempt to load all objects in the
     * 'parent/id' expression until the object has been found. */
    corto_id full_id;
    corto_path_combine(full_id, parent, id);
    char *obj_id = NULL, *package_id = NULL;
    corto_object o = *object;

    /* Step 1: try to find package */
    const char *pkg = corto_locate(full_id, NULL, CORTO_LOCATE_PACKAGE);
    if (pkg) {
        package_id = full_id;
    } else {
        /* If package was not found, try to find package in parents */
        char *next_ptr;
        do {
            next_ptr = corto_path_tok(&obj_id, &package_id, full_id);
            if (package_id[0] != '/' || package_id[1]) {
                pkg = corto_locate(package_id, NULL, CORTO_LOCATE_PACKAGE);
            } else {
                pkg = NULL;
            }
        } while (next_ptr && !pkg);
        if (!pkg) {
            package_id = NULL;
            if (obj_id) {
                obj_id[-1] = '/';
            }
        }
    }

    /* Step 2: load package if found */
    bool proceed = false;
    if (package_id) {
        corto_debug("package '%s' located while looking for '%s/%s'",
            package_id, package_id, obj_id);

        /* Test if package is already loaded. If it is, but the object could not
         * be found in the store (which is why corto attempts to resume it), it
         * does not exist. */
        corto_object package_object = corto(CORTO_LOOKUP, {
            .parent = root_o, .id = package_id
        });

        if (package_object) {
            corto_release(package_object);
            /* Package is already loaded, but object doesn't exist */
        } else {
            /* Only load package if it is a library */
            if (corto_locate(package_id, NULL, CORTO_LOCATE_LIB)) {
                /* Package wasn't found in store, try load it now */
                if (corto_use(package_id, 0, NULL)) {
                    goto error;
                }
            }
            proceed = true;
        }
    }

    if (proceed) {
        /* Step 3: find or create package object or object inside package */
        if (o) {
            /* If an object was provided to this function, check if it has been
             * defined by loading the package */
            if (!corto_check_state(o, CORTO_VALID)) {
                /* If requesting object inside package, it wasn't created */
                if (obj_id) {
                    /* Object was not loaded by this package */
                    corto_debug("object '%s' not found in package '%s'",
                        obj_id, package_id);
                    *object = NULL;
                } else {
                    /* If the package has been loaded and we're not requesting
                     * an object inside the package but the package object
                     * itself, the package is likely unmanaged and does not
                     * create its own package object. In that case, create one
                     * from the project.json (which should be available). */
                    if (!corto_loader_create_package(this, o, package_id, pkg)){
                        /* If package was loaded successfully, but value of the
                         * package object could not be loaded from the project
                         * file, that's an error. */
                        goto error;
                    }
                }
            } /* else object already points to resumed object */
        } else {
            /* Restore full id */
            if (obj_id) {
                obj_id[-1] = '/';
            }

            /* Check if object was loaded by package */
            o = corto(CORTO_LOOKUP, {
                .parent = root_o, /* package loader is always mounted on root */
                .id = full_id
            });

            /* If object was loaded by package, return it */
            if (o) {
                *object = o;
                corto_debug("object '%s' found", full_id);
            } else {
                /* If package has been loaded and requesting the package object
                 * but it wasn't created by the package loader, create it (see
                 * above). */
                if (!obj_id) {
                    o = corto_loader_create_package(this, o, package_id, pkg);
                    if (!o) {
                        /* If package was loaded successfully, but value of the
                         * package object could not be loaded from the project
                         * file, that's an error. */
                        goto error;
                    }
                    *object = o;
                    corto_debug("object created for package '%s'", full_id);
                } else {
                    corto_debug("object '%s' not found in package '%s'",
                        obj_id, package_id);
                }
            }
        }
    }  else {
        corto_debug("no package found while searching for '%s'", full_id);
    }

    corto_log_pop_dbg();
    return 0;
error:
    corto_log_pop_dbg();
    return -1;
}
