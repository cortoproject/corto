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
    corto_setref(&corto_mount(this)->mount, root_o);
    corto_mount(this)->mask = CORTO_ON_TREE;
    corto_mount(this)->attr = 0;
    corto_mount(this)->kind = CORTO_SINK;
    corto_setstr(&corto_mount(this)->type, "/corto/core/package");
    return corto_mount_construct(this);
/* $end */
}

corto_void _corto_loader_destruct(
    corto_loader this)
{
/* $begin(corto/core/loader/destruct) */
    corto_mount_destruct(this);
/* $end */
}

/* $header(corto/core/loader/onRequest) */
void corto_loader_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;

    /* Delete data from request */
    corto_resultListClear(data->list);
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
    corto_string expr)
{
    corto_ll dirs = corto_opendir(path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_llIter(dirs);

        while (corto_iterHasNext(&iter)) {
            corto_string f = corto_iterNext(&iter);

            if (!fnmatch(expr, f, 0) && !corto_loader_checkIfAdded(list, f)) {
                struct stat attr;

                /* Build full path to file from current directory */
                corto_id fpath; sprintf(fpath, "%s/%s", path, f);

                /* Stat file to determine whether it's a directory */
                if (stat(fpath, &attr) < 0) {
                    corto_error("failed to stat '%s' (%s)\n",
                        fpath,
                        strerror(errno));
                }

                if (S_ISDIR(attr.st_mode)) {
                    corto_resultAssign(
                        corto_resultListAppendAlloc(list),
                        f, /* Name */
                        NULL,
                        ".", /* Parent */
                        "/corto/core/package",
                        0
                    );
                }
            }
        }

        /* Free up resources of opendir */
        corto_closedir(dirs);
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

    corto_loader_addDir(data, localPath, request->expr);
    corto_loader_addDir(data, globalPath, request->expr);

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_llIterAlloc(data);
    result.release = corto_loader_iterRelease;

    return result;
/* $end */
}

corto_object _corto_loader_onResume_v(
    corto_loader this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/loader/onResume) */
    CORTO_UNUSED(this);

    if (!o) {
        corto_id path;
        sprintf(path, "%s/%s", parent, name);
        corto_cleanpath(path, path);
        if (!corto_load(path, 0, NULL)) {
            o = corto_lookup(NULL, path);
        }
    } else {
        o = NULL;
    }

    return o;
/* $end */
}
