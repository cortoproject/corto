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
        corto_query *q = &corto_subscriber(this)->query;
        corto_ptr_setstr(&q->select, "//*");
        corto_ptr_setstr(&q->from, "/");
        corto_ptr_setstr(&q->type, "/corto/core/package");
        corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
        if (corto_mount_setContentType(this, "text/json")) {
            return -1;;
        }
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

/* $header(corto/core/loader/onQuery) */
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
    corto_query *q)
{
    corto_ll dirs = corto_opendir(path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_ll_iter(dirs);

        while (corto_iter_hasNext(&iter)) {
            corto_string f = corto_iter_next(&iter);

            if (!corto_loader_checkIfAdded(list, f) && corto_match(q->select, f)) {
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
                sprintf(package, "%s/%s", q->from, f);
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

                if (q->content) {
                    if (strcmp(q->from, ".")) {
                        corto_asprintf(
                            &content,
                            "{\"url\":\"http://www.corto.io/doc/%s/%s\",\"env\":\"%s\"}",
                            q->from,
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

                corto_result *result = corto_calloc(sizeof(corto_result));
                result->id = corto_strdup(f);
                result->parent = corto_strdup(q->from);
                result->type = corto_strdup("/corto/core/package");
                result->value = (corto_word)content;
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
/* $end */
corto_resultIter _corto_loader_onQuery_v(
    corto_loader this,
    corto_query *query)
{
/* $begin(corto/core/loader/onQuery) */
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
/* $end */
}
