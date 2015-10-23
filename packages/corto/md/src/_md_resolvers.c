#include "_md_resolvers.h"

/*
 * Returns TRUE if `ancestor` is recursively a parent of `o`, except if
 * `ancestor` is root_o.
 */
static corto_bool md_isAncestor(corto_object ancestor, corto_object o) {
    corto_bool isAncestor = FALSE;
    corto_object p = o;
    while (p && !isAncestor) {
        p = corto_parentof(p);
        if (p == ancestor) {
            isAncestor = TRUE;
        }
    }
    return isAncestor;
}

corto_object md_resolve(int level, corto_string name, corto_object *parent, md_parseData* data) {
    corto_assert(level >= 1 && level <= 6, "Level must be between 1 and 6");
    corto_object o = NULL, current = NULL;

    corto_object previous = NULL;
    if (level == 1) {
        previous = data->destination;
    } else {
        corto_uint32 i = level - 1;
        while (i && !(previous = md_Doc(data->headers[i]))) {
            i--;
        }
        previous = data->headers[i];
    }
    if (previous == NULL) {
        goto notFound;
    }

    if (corto_instanceof(md_Doc_o, previous)) {
        current = md_Doc(previous)->o;
    }

    if (parent) {
        *parent = previous;
    }

    if (current || (level == 1)) {
        o = corto_resolve(current, name);
        if (o == NULL) {
            goto notFound;
        }
        if (!md_isAncestor(current, o)) {
            o = NULL;
        }
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
