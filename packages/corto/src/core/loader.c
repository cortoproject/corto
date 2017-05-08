/* $CORTO_GENERATED
 *
 * loader.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_loader_construct(
    corto_loader this)
{
/* $begin(corto/core/loader/construct) */
    static corto_int32 constructOnce;

    if (corto_ainc(&constructOnce) == 1) {
        corto_setref(&corto_mount(this)->mount, root_o);
        corto_observer(this)->mask = CORTO_ON_TREE;
        corto_mount(this)->kind = CORTO_SINK;
        corto_setstr(&corto_observer(this)->type, "/corto/core/package");
        corto_setstr(&corto_subscriber(this)->contentType, "text/json");
        return corto_mount_construct(this);
    } else {
        return -1;
    }

/* $end */
}

void _corto_loader_destruct(
    corto_loader this)
{
/* $begin(corto/core/loader/destruct) */
    corto_mount_destruct(this);
/* $end */
}

/* $header(corto/core/loader/onRequest) */
void corto_loader_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->udata;

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
    corto_request *r)
{
    corto_ll dirs = corto_opendir(path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_ll_iter(dirs);

        while (corto_iter_hasNext(&iter)) {
            corto_string f = corto_iter_next(&iter);

            if (!corto_loader_checkIfAdded(list, f) && corto_match(r->expr, f)) {
                struct stat attr;
                corto_string content = NULL;

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
                sprintf(package, "%s/%s", r->parent, f);
                corto_cleanpath(package, package);

                if (!strcmp(package, "corto")) {
                    continue;
                }

                corto_string env = corto_locate(package, NULL, CORTO_LOCATION_ENV);

                if (!env) {
                    corto_lasterr();
                    //continue;
                }

                /* Built-in packages use corto version */
                if (!strcmp(package, "corto") ||
                    !strcmp(package, "corto/lang") ||
                    !strcmp(package, "corto/core") ||
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

                if (r->content) {
                    if (strcmp(r->parent, ".")) {
                        corto_asprintf(
                            &content,
                            "{\"url\":\"http://www.corto.io/doc/%s/%s\",\"env\":\"%s\"}",
                            r->parent,
                            f,
                            env
                        );
                    } else {
                        corto_asprintf(
                            &content,
                            "{\"url\":\"http://www.corto.io/doc/%s\",\"env\":\"%s\"}",
                            f,
                            env
                        );
                    }
                }

                corto_dealloc(env);

                corto_result *r = corto_calloc(sizeof(corto_result));
                r->id = corto_strdup(f);
                r->parent = corto_strdup(".");
                r->type = corto_strdup("/corto/core/package");
                r->value = (corto_word)content;
                corto_ll_append(list, r);
            }
        }

        /* Free up resources of opendir */
        corto_closedir(dirs);
    } else {
        /* Catch error */
        corto_lasterr();
    }
}
/* $end */
corto_resultIter _corto_loader_onRequest_v(
    corto_loader this,
    corto_request *request)
{
/* $begin(corto/core/loader/onRequest) */
    corto_ll data = corto_ll_new(); /* Will contain result of request */
    corto_iter result;

    CORTO_UNUSED(this);

    corto_string targetPath, homePath, globalPath;
    targetPath = corto_envparse("$CORTO_TARGET/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      request->parent);
    corto_cleanpath(targetPath, targetPath);

    homePath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      request->parent);
    corto_cleanpath(homePath, homePath);

    globalPath = corto_envparse("/usr/local/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      request->parent);
    corto_cleanpath(globalPath, globalPath);

    corto_loader_addDir(data, targetPath, request);

    if (strcmp(targetPath, homePath)) {
        corto_loader_addDir(data, homePath, request);
    }
    
    if (strcmp(targetPath, globalPath) && strcmp(homePath, globalPath)) {
        corto_loader_addDir(data, globalPath, request);
    }

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_ll_iterAlloc(data);
    result.release = corto_loader_iterRelease;

    corto_dealloc(targetPath);
    corto_dealloc(homePath);
    corto_dealloc(globalPath);

    return result;
/* $end */
}
