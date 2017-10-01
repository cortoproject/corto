/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

static corto_int32 constructOnce;

int16_t corto_loader_construct(
    corto_loader this)
{
    if (corto_ainc(&constructOnce) == 1) {
        corto_query *q = &corto_subscriber(this)->query;
        corto_ptr_setstr(&q->select, "//*");
        corto_ptr_setstr(&q->from, "/");
        corto_ptr_setstr(&q->type, "/corto/vstore/package");
        corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
        if (safe_corto_mount_setContentType(this, "text/json")) {
            return -1;
        }
        corto_mount(this)->policy.filterResults = false;

        return safe_corto_mount_construct(this);
    } else {
        corto_seterr("cannot create multiple instances of vstore/loader");
        return -1;
    }
}

void corto_loader_destruct(
    corto_loader this)
{
    corto_assert(corto_adec(&constructOnce) >= 0, "loader destructed too many times");
    safe_corto_mount_destruct(this);
}


void corto_loader_iterRelease(corto_iter *iter) {
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

corto_bool corto_loader_checkIfAdded(corto_ll list, corto_string name) {
    corto_iter it = corto_ll_iter(list);
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        if (!stricmp(r->id, name)) {
            return TRUE;
        }
    }
    return FALSE;
}

void corto_loader_addDir(
    corto_ll list,
    corto_string path,
    corto_query *q)
{
    corto_ll dirs = corto_opendir(path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_ll_iter(dirs);

        while (corto_iter_hasNext(&iter)) {
            corto_string f = corto_iter_next(&iter);

            if (!corto_loader_checkIfAdded(list, f) && corto_idmatch(q->select, f)) {
                struct stat attr;

                corto_id fpath;
                sprintf(fpath, "%s/%s", path, f);

                /* Stat file to determine whether it's a directory */
                if (stat(fpath, &attr) < 0) {
                    corto_seterr("failed to stat '%s' (%s)\n",
                        fpath,
                        strerror(errno));
                }

                if (!S_ISDIR(attr.st_mode)) {
                    continue;
                }

                corto_id package;
                sprintf(package, "%s/%s", q->from, f);
                corto_cleanpath(package, package);

                corto_string env = corto_locate(package, NULL, CORTO_LOCATION_ENV);

                if (!env) {
                    corto_lasterr();
                    //continue;
                }

                /* Built-in packages use corto version */
                if (!strcmp(package, "corto") ||
                    !strcmp(package, "corto/lang") ||
                    !strcmp(package, "corto/vstore") ||
                    !strcmp(package, "corto/native") ||
                    !strcmp(package, "corto/secure"))
                {
                    if (!env) {
                        env = corto_locate("corto", NULL, CORTO_LOCATION_ENV);
                        if (!env) corto_lasterr(); /* Catch error */
                    }
                }

                /* If no event was found by corto_locate, this is not a loadable
                 * package, but a directory that contains packages. */
                if (!env) {
                    env = corto_strdup("");
                }

                corto_result *result = corto_calloc(sizeof(corto_result));

                corto_id packageFile;
                sprintf(packageFile, "%s/project.json", fpath);
                if (corto_fileTest(packageFile)) {
                    char *json = corto_fileLoad(packageFile);
                    corto_result_fromcontent(result, "text/json", json);
                } else {
                    result->id = corto_strdup(f);
                    result->type = corto_strdup("/corto/vstore/package");
                    result->value = (uintptr_t)strdup("{}");
                }

                corto_ptr_setstr(&result->parent, q->from);

                corto_dealloc(env);

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
        /* Catch error */
        corto_lasterr();
    }
}

corto_resultIter corto_loader_onQuery_v(
    corto_loader this,
    corto_query *query)
{
    corto_ll data = corto_ll_new(); /* Will contain result of request */
    corto_iter result;

    CORTO_UNUSED(this);

    corto_string targetPath, homePath, globalPath;
    targetPath = corto_envparse("$CORTO_TARGET/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      query->from);
    corto_cleanpath(targetPath, targetPath);

    homePath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      query->from);
    corto_cleanpath(homePath, homePath);

    globalPath = corto_envparse("/usr/local/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      query->from);
    corto_cleanpath(globalPath, globalPath);

    corto_loader_addDir(data, targetPath, query);

    if (strcmp(targetPath, homePath)) {
        corto_loader_addDir(data, homePath, query);
    }
    
    if (strcmp(targetPath, globalPath) && strcmp(homePath, globalPath)) {
        corto_loader_addDir(data, globalPath, query);
    }

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_ll_iterAlloc(data);
    result.release = corto_loader_iterRelease;

    corto_dealloc(targetPath);
    corto_dealloc(homePath);
    corto_dealloc(globalPath);

    return result;
}

