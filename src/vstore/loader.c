/* This is a managed file. Do not delete this comment. */

#include <corto>

static corto_int32 constructOnce;

int16_t corto_loader_construct(
    corto_loader this)
{
    if (ut_ainc(&constructOnce) == 1) {
        corto_query *q = &corto_subscriber(this)->query;
        corto_set_str(&q->select, "//*");
        corto_set_str(&q->from, "/");
        corto_set_str(&q->type, "package");
        corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
        if (safe_corto_mount_set_format(this, "text/json")) {
            return -1;
        }
        corto_mount(this)->filter_records = false;

        return safe_corto_mount_construct(this);
    } else {
        ut_throw("cannot create multiple instances of vstore/loader");
        return -1;
    }
}

void corto_loader_destruct(
    corto_loader this)
{
    ut_assert(
        ut_adec(&constructOnce) >= 0, "loader destructed too many times");
    safe_corto_mount_destruct(this);
}

static
void corto_loader_iterRelease(
    ut_iter *iter)
{
    ut_ll_iter_s *data = iter->ctx;

    /* Delete data from request */
    ut_iter it = ut_ll_iter(data->list);
    while (ut_iter_hasNext(&it)) {
        corto_record *r = ut_iter_next(&it);
        corto_ptr_deinit(r, corto_record_o);
        corto_dealloc(r);
    }
    ut_ll_free(data->list);

    /* Call iter release function that was overridden by this function */
    ut_ll_iterRelease(iter);
}

static
bool corto_loader_checkIfAdded(
    ut_ll list,
    corto_string name)
{
    ut_iter it = ut_ll_iter(list);
    while (ut_iter_hasNext(&it)) {
        corto_record *r = ut_iter_next(&it);

        if (!stricmp(r->id, name)) {
            return TRUE;
        }
    }
    return FALSE;
}

static
void corto_loader_addDir(
    ut_ll list,
    const char* path,
    corto_query *q)
{
    ut_ll dirs = ut_opendir(path);

    corto_id from;
    strcpy(from, q->from);
    char *ptr, ch;
    for (ptr = from; (ch = *ptr); ptr ++) {
        if (ch == '/') {
            *ptr = '.';
        }
    }

    if (!strcmp(from, ".")) {
        from[0] = '\0';
    }

    uint32_t from_len = strlen(from);

    /* Walk files, add files to result */
    if (dirs) {
        ut_iter iter = ut_ll_iter(dirs);

        while (ut_iter_hasNext(&iter)) {
            corto_string f = ut_iter_next(&iter);

            if (!corto_loader_checkIfAdded(list, f))
            {
                corto_id fpath, ftest;

                if (from_len && strncmp(f, from, from_len)) {
                    continue;
                }

                if (!f[from_len]) {
                    continue;
                }

                char *elem = NULL;
                strcpy(ftest, f);
                if ((elem = strchr(&ftest[from_len + 1], '.'))) {
                    strcpy(ftest, f);
                    elem[0] = '\0';

                    char *id;
                    if (from_len) {
                        id = &ftest[from_len + 1];
                    } else {
                        id = ftest;
                    }

                    if (!ut_expr(q->select, id)) {
                        continue;
                    }

                    if (!corto_loader_checkIfAdded(list, id)) {
                        corto_record *precord = corto_calloc(sizeof(corto_record));
                        precord->id = ut_strdup(id);
                        precord->type = ut_strdup("package");
                        precord->value = (uintptr_t)strdup("{}");
                        corto_set_str(&precord->parent, q->from);
                        ut_ll_append(list, precord);
                    }
                    continue;
                } else {
                    if (!ut_expr(q->select, &ftest[from_len + 1])) {
                        continue;
                    }
                }

                sprintf(fpath, "%s/%s", path, f);
                if (!ut_isdir(fpath)) {
                    continue;
                }

                corto_record *result = corto_calloc(sizeof(corto_record));

                corto_id packageFile;
                sprintf(packageFile, "%s/project.json", fpath);
                if (ut_file_test(packageFile)) {
                    char *json = ut_file_load(packageFile);
                    corto_record_fromcontent(result, "text/json", json);
                }

                corto_set_str(&result->parent, q->from);

                /* because the corto object is not persistent, but because the
                 * mount does have objects under the corto scope, hide the corto
                 * object from the mount for the user, but let corto_select know
                 * that more objects may be available. */
                if (!strcmp(f, "corto")) {
                    result->flags = CORTO_RECORD_HIDDEN;
                } else {
                    result->flags = 0;
                }

                ut_ll_append(list, result);
            }
        }

        /* Free up resources of opendir */
        ut_closedir(dirs);
    } else {
        /* Catch error logged by ut_opendir */
        ut_catch();
    }
}

corto_recordIter corto_loader_on_query_v(
    corto_loader this,
    corto_query *query)
{
    ut_ll data = ut_ll_new(); /* Will contain result of request */
    ut_iter result;
    const char *targetPath = ut_load_targetMetaPath();
    const char *homePath = ut_load_homeMetaPath();

    ut_log_push_dbg("vstore-loader");

    CORTO_UNUSED(this);

    corto_loader_addDir(data, targetPath, query);

    if (strcmp(targetPath, homePath)) {
        corto_loader_addDir(data, homePath, query);
    }

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = ut_ll_iterAlloc(data);
    result.release = corto_loader_iterRelease;

    ut_log_pop_dbg();

    return result;
}

static
corto_object corto_loader_create_package(
    corto_loader this,
    corto_object o,
    const char *id,
    const char *path)
{
    char *project_file = ut_asprintf("%s/project.json", path);
    if (ut_file_test(project_file) == 1) {
        char *json = ut_file_load(project_file);
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
    ut_log_push_dbg(strarg("vstore-loader:resume:%s,%s", parent, id));

    /* The loader may be asked to resume objects that are not packages, but live
     * inside a package. Therefore it will attempt to load all objects in the
     * 'parent/id' expression until the object has been found. */
    corto_id full_id;
    ut_path_combine(full_id, parent, id);
    char *obj_id = NULL, *package_id = NULL;
    corto_object o = *object;

    char *ptr, ch;
    for (ptr = full_id; (ch = *ptr); ptr ++) {
        if (ch == '/') {
            *ptr = '.';
        }
    }

    /* Step 1: try to find package */
    const char *pkg = ut_locate(full_id, NULL, UT_LOCATE_PROJECT);
    if (pkg) {
        package_id = full_id;
    } else {
        /* If package was not found, try to find package in parents */
        char *next_ptr;
        do {
            next_ptr = ut_path_tok(&obj_id, &package_id, full_id);
            if ((package_id[0] != '/' || package_id[1])) {
                pkg = ut_locate(package_id, NULL, UT_LOCATE_PROJECT);
            } else {
                pkg = NULL;
            }
        } while (next_ptr && !pkg);
        if (!pkg) {
            package_id = NULL;
            if (obj_id) {
                obj_id[-1] = '.';
            }
        }
    }

    /* Step 2: load package if found */
    bool proceed = false;
    bool package_object_found = false;
    if (package_id) {
        ut_debug("package '%s' located while looking for object '%s/%s'",
            package_id, package_id, obj_id);

        /* Test if package is already loaded. If it is, but the object could not
         * be found in the store (which is why corto attempts to resume it), it
         * does not exist. */
        corto_object package_object = corto(CORTO_LOOKUP, {
            .parent = root_o, .id = package_id
        });

        if (package_object) {
            package_object_found = true;
            corto_release(package_object);
            /* Package is already loaded, but object doesn't exist */
        } else {
            /* Only load package if it is a library */
            if (ut_locate(package_id, NULL, UT_LOCATE_LIB)) {
                /* Package wasn't found in store, try load it now */
                if (ut_use(package_id, 0, NULL)) {
                    goto error;
                }
            } else {
                ut_trace("package '%s' is not a library, cannot load",
                    package_id);
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
                    ut_debug("object '%s' not found in package '%s'",
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
                obj_id[-1] = '.';
            }

            /* Check if object was loaded by package */
            o = corto(CORTO_LOOKUP, {
                .parent = root_o, /* package loader is always mounted on root */
                .id = full_id
            });

            /* If object was loaded by package, return it */
            if (o) {
                *object = o;
                ut_debug("object '%s' found", full_id);
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
                    ut_debug("object created for package '%s'", full_id);
                } else {
                    obj_id[-1] = '\0';
                    ut_debug("object '%s' not found in package '%s'",
                        obj_id, package_id);
                }
            }
        }
    }  else {
        if (!package_object_found) {
            ut_debug("no package found while searching for '%s/%s'", parent, id);
        } else {
            ut_debug("object '%s/%s' not found in package '%s'", parent, id, package_id);
        }
    }

    ut_log_pop_dbg();
    return 0;
error:
    ut_log_pop_dbg();
    return -1;
}
