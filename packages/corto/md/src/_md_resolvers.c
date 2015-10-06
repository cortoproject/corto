#include "_md_resolvers.h"

/*
 * Returns TRUE if `ancestor` is recursively a parent of `o`, except if
 * `ancestor` is root_o.
 */
static cx_bool md_isAncestor(cx_object ancestor, cx_object o) {
    cx_bool isAncestor = FALSE;
    cx_object p = o;
    while (!isAncestor) {
        p = cx_parentof(p);
        if (p == ancestor) {
            isAncestor = TRUE;
        }
    }
    return isAncestor;
}

cx_object md_resolve(int level, cx_string name, md_parseData* data) {
    cx_assert(level >= 1 && level <= 6, "Level must be between 1 and 6");
    cx_object previous = level == 1 ? root_o : md_Doc(data->headers[level - 1])->o;
    if (previous == NULL) {
        goto notFound;
    }

    cx_object o = cx_resolve(previous, name);
    if (o == NULL) {
        goto notFound;
    }
    if (!md_isAncestor(previous, o)) {
        o = NULL;
    }
    
    /* Clean up the lower levels of the doc hierarchy */
    int i = 6;
    do {
        md_Doc childHeader = data->headers[i];
        if (childHeader) {
            // cx_release(childHeader);
        }
        data->headers[i] = NULL;
    } while (i-- == level);

    return o;
notFound:
    return NULL;
}
