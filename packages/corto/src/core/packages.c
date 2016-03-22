/* $CORTO_GENERATED
 *
 * packages.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/core/core.h"

corto_int16 _corto_packages_construct(
    corto_packages this)
{
/* $begin(corto/core/packages/construct) */
    corto_setref(&corto_replicator(this)->mount, root_o);
    corto_replicator(this)->mask = CORTO_ON_TREE;
    corto_replicator(this)->kind = CORTO_SINK;
    corto_setref(&corto_replicator(this)->type, corto_package_o);
    return corto_replicator_construct(this);
/* $end */
}

corto_void _corto_packages_destruct(
    corto_packages this)
{
/* $begin(corto/core/packages/destruct) */
    corto_replicator_destruct(this);
/* $end */
}

/* $header(corto/core/packages/onRequest) */
void corto_packages_iterRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;

    /* Delete data from request */
    corto_resultListClear(data->list);
    corto_llFree(data->list);

    /* Call iter release function that was overridden by this function */
    corto_llIterRelease(iter);
}

corto_bool corto_packages_checkIfAdded(corto_ll list, corto_string name) {
    corto_iter it = corto_llIter(list);
    while (corto_iterHasNext(&it)) {
        corto_result *r = corto_iterNext(&it);
        if (!strcmp(r->id, name)) {
            return TRUE;
        }
    }
    return FALSE;
}

void corto_packages_addDir(corto_ll list, corto_string path) {
    corto_ll dirs = corto_opendir(path);

    /* Walk files, add files to result */
    if (dirs) {
        corto_iter iter = corto_llIter(dirs);

        while (corto_iterHasNext(&iter)) {
            corto_string f = corto_iterNext(&iter);

            if (!corto_packages_checkIfAdded(list, f)) {
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
                    corto_resultSet(
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
corto_resultIter _corto_packages_onRequest_v(
    corto_packages this,
    corto_request *request)
{
/* $begin(corto/core/packages/onRequest) */
    corto_ll data = corto_llNew(); /* Will contain result of request */
    corto_iter result;

    CORTO_UNUSED(this);

    corto_string localPath, globalPath;
    localPath = corto_envparse("$CORTO_HOME/lib/corto/$CORTO_VERSION/%s", request->parent);
    corto_cleanpath(localPath);
    globalPath = corto_envparse("/usr/local/lib/corto/$CORTO_VERSION/%s", request->parent);
    corto_cleanpath(globalPath);

    corto_packages_addDir(data, localPath);
    corto_packages_addDir(data, globalPath);

    /* Allocate persistent iterator. Set a custom release function so that the
     * returned list is cleaned up after select is done iterating. */
    result = corto_llIterAlloc(data);
    result.release = corto_packages_iterRelease;

    return result;
/* $end */
}

corto_object _corto_packages_onResume_v(
    corto_packages this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/packages/onResume) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(o);
    return NULL;
/* $end */
}
