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

cx_object md_resolve(int level, cx_string name, md_Doc *header_out, md_parseData* data) {
    cx_assert(level >= 1 && level <= 6, "Level must be between 1 and 6");

    cx_object previous = NULL;
    if (level == 1) {
        previous = root_o;
    } else {
        cx_uint32 i = level - 1;
        while (i && !(previous = md_Doc(data->headers[i]))) {
            i--;
        }
        previous = data->headers[i];
    }
    if (previous == NULL) {
        goto notFound;
    }

    if (header_out) {
        if (cx_instanceof(md_Doc_o, previous)) {
            *header_out = previous;
        }
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
        data->headers[i] = NULL;
    } while (i-- > level);

    return o;
notFound:
    return NULL;
}
