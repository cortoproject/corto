#include "_md_renderers.h"

/*
 * Recursively creates the objects hierarchy specified by the name atop the
 * 'parent' object. **Assumes that the name is well-formed.**
 */
static int md_createChildRecursive(cx_object parent, cx_string fullname, cx_type type) {
    char *p = fullname[0] == ':' ? fullname + 2 : fullname;
    size_t parentheses = 0;
    while (*p) {
        switch (*p) {
        case '(':
            parentheses += 1;
        case ')':
            if (parentheses) {
                parentheses -= 1;
            } else {
                goto error;
            }
        case ':':
            if (!parentheses) {
                break;
            }
            goto error;
        }
        p += 1;
    }
    cx_id simpleName;
    size_t simpleNameLen = p - fullname - 2;
    strncpy(simpleName, fullname + 2, simpleNameLen);
    simpleName[simpleNameLen] = '\0';
    cx_object o = cx_createChild(parent, simpleName, type);
    cx_print("created %s on %s", simpleName, cx_nameof(parent));
    if (o == NULL) {
        goto error;
    }

    /* If there is more of the fully-scoped name yet to parse */
    if (*p) {
        md_createChildRecursive(o, p, type);
    }
    return 0;
error:
    return 1;
}

int md_renderPackage(cx_string name, md_parseData* data) {
    /* TODO validate that the name is well-formed */
    if (md_createChildRecursive(data->destination, name, cx_type(md_PackageDoc_o))) {
        goto error;
    }
    return 0;
error:
    return 1;
}

int md_renderType(cx_string name, md_parseData* data) {
    data->lastScope = md_TypeDocCreateChild(data->lastScope, name);
    return 0;
}

int md_renderProcedure(cx_string name, md_parseData* data) {
    data->lastScope = md_ProcedureDocCreateChild(data->lastScope, name);
    return 0;
}

int md_renderArgument(cx_string name, md_parseData* data) {
    cx_assertType(data->lastScope, md_ProcedureDoc_o);
    data->lastScope = md_ParameterDocCreateChild(data->lastScope, name);
    return 0;
}
