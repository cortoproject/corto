/* $CORTO_GENERATED
 *
 * loader.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

corto_int16 _corto_loader_construct(
    corto_loader this)
{
/* $begin(corto/core/loader/construct) */
    static corto_int32 constructOnce;

    if (corto_ainc(&constructOnce) == 1) {
        corto_setref(&corto_mount(this)->mount, root_o);
        corto_observer(this)->mask = CORTO_ON_TREE;
        corto_mount(this)->attr = 0;
        corto_mount(this)->kind = CORTO_SINK;
        corto_setstr(&corto_observer(this)->type, "/corto/core/package");
        corto_setstr(&corto_subscriber(this)->contentType, "text/json");
        return corto_mount_construct(this);
    } else {
        return 0;
    }
/* $end */
}

corto_void _corto_loader_destruct(
    corto_loader this)
{
/* $begin(corto/core/loader/destruct) */
    corto_mount_destruct(this);
/* $end */
}

corto_void _corto_loader_onDeclare_v(
    corto_loader this,
    corto_object observable)
{
/* $begin(corto/core/loader/onDeclare) */
    corto_id path;
    corto_string localPath;
    corto_path(path, corto_mount(this)->mount, observable, "/");
    localPath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      path);
    corto_cleanpath(localPath, localPath);
    corto_mkdir(localPath);
    corto_dealloc(localPath);
/* $end */
}

/* $header(corto/core/loader/onRequest) */
void corto_loader_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;

    /* Delete data from request */
    corto_iter it = corto_llIter(data->list);
    while (corto_iterHasNext(&it)) {
        corto_result *r = corto_iterNext(&it);
        corto_deinitp(r, corto_result_o);
        corto_dealloc(r);
    }
    corto_llFree(data->list);

    /* Call iter release function that was overridden by this function */
    corto_llIterRelease(iter);
}

corto_bool corto_loader_checkIfAdded(corto_ll list, corto_string name) {
    corto_iter it = corto_llIter(list);
    while (corto_iterHasNext(&it)) {
        corto_result *r = corto_iterNext(&it);
        if (!strcmp(r->id, name)) {
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
        corto_iter iter = corto_llIter(dirs);

        while (corto_iterHasNext(&iter)) {
            corto_string f = corto_iterNext(&iter);

            if (!corto_loader_checkIfAdded(list, f) && corto_match(r->expr, f)) {
                struct stat attr;
                corto_string content = NULL;
                corto_id package;
                sprintf(package, "%s/%s", r->parent, f);
                corto_cleanpath(package, package);

                corto_id fpath;
                sprintf(fpath, "%s/%s", path, f);
                corto_string version = NULL;
                corto_string env = corto_locate(package, CORTO_LOCATION_ENV);
                if (!env) corto_lasterr(); /* Catch error */

                /* Built-in packages use corto version */
                if (!strcmp(package, "corto") ||
                    !strcmp(package, "corto/lang") ||
                    !strcmp(package, "corto/core") ||
                    !strcmp(package, "corto/native") ||
                    !strcmp(package, "corto/secure"))
                {
                    version = corto_strdup(CORTO_VERSION);
                    if (!env) {
                        env = corto_locate("corto", CORTO_LOCATION_ENV);
                        if (!env) corto_lasterr(); /* Catch error */
                    }
                } else {
                    corto_id versionFile;
                    sprintf(versionFile, "%s/version.txt", fpath);
                    version = corto_fileLoad(versionFile);
                    if (!version) corto_lasterr(); /* Catch error */

                    if (version) {
                        char *newline = strchr(version, '\n');
                        if (newline) {
                            *newline = '\0';
                        }
                    } else if (env) {
                        version = corto_strdup("0.0.0");
                    } else {
                        version = corto_strdup("");
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
                            "{\"url\":\"http://www.corto.io/doc/%s/%s\",\"version\":\"%s\",\"env\":\"%s\"}",
                            r->parent,
                            f,
                            version,
                            env
                        );
                    } else {
                        corto_asprintf(
                            &content,
                            "{\"url\":\"http://www.corto.io/doc/%s\",\"version\":\"%s\",\"env\":\"%s\"}",
                            f,
                            version,
                            env
                        );
                    }
                }

                corto_dealloc(version);
                corto_dealloc(env);

                /* Stat file to determine whether it's a directory */
                if (stat(fpath, &attr) < 0) {
                    corto_seterr("failed to stat '%s' (%s)\n",
                        fpath,
                        strerror(errno));
                }

                if (S_ISDIR(attr.st_mode)) {
                    corto_result *r = corto_calloc(sizeof(corto_result));
                    r->id = corto_strdup(f);
                    r->parent = corto_strdup(".");
                    r->type = corto_strdup("/corto/core/package");
                    r->value = (corto_word)content;
                    corto_llAppend(list, r);
                }
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
    corto_ll data = corto_llNew(); /* Will contain result of request */
    corto_iter result;

    CORTO_UNUSED(this);

    corto_string localPath, globalPath;
    localPath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      request->parent);
    corto_cleanpath(localPath, localPath);
    globalPath = corto_envparse("/usr/local/lib/corto/%s.%s/%s",
      CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
      request->parent);
    corto_cleanpath(globalPath, globalPath);

    corto_loader_addDir(data, localPath, request);
    corto_loader_addDir(data, globalPath, request);

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_llIterAlloc(data);
    result.release = corto_loader_iterRelease;

    corto_dealloc(localPath);
    corto_dealloc(globalPath);

    return result;
/* $end */
}
