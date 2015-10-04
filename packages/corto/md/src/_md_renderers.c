#include "_md_renderers.h"

/* Returns a pointer that must be in turn freed. */
static char* md_makeDocName(cx_object o) {
    cx_string docName;
    cx_type type = cx_typeof(o);
    if (type->kind == CX_COMPOSITE && cx_interface(type)->kind == CX_PROCEDURE) {
        cx_id signatureName;
        cx_signatureName(cx_nameof(o), signatureName);
        cx_asprintf(&docName, "%s", signatureName);
    } else {
        cx_asprintf(&docName, "%s", cx_nameof(o));
    }
    return docName;
}

/*
 * Gets the propriate type of the documentation object of `o`. E.g. if
 * `o` is a `package`, then returns `PackageDoc`; if `o` is a `class` then
 * returns `TypeDoc`.
 */
static cx_type md_getDocType(cx_object o) {
    cx_object type = NULL;
    if (cx_instanceof(cx_type(cx_package_o), o)) {
        type = md_PackageDoc_o;
    } else if (cx_instanceof(cx_type(cx_type_o), o)) {
        type = md_TypeDoc_o;
    } else if (cx_instanceof(cx_type(cx_function_o), o)) {
        type = md_MethodDoc_o;
    }
    return type;
}

static int md_createDocTree(cx_object o, md_parseData* data) {
    if (o == root_o) {
        goto finish;
    }
    if (md_createDocTree(cx_parentof(o), data)) {
        goto error;   
    }
    
    cx_string docName = md_makeDocName(o);
    {
        cx_object p = cx_lookup(data->lastScope, cx_nameof(o));
        if (p) {
            cx_release(p);
            data->lastScope = p;
            cx_dealloc(docName);
            goto finish;
        }
    }
    
    cx_type docType = md_getDocType(o);
    if (docType == NULL) {
        cx_id fullname;
        cx_fullname(o, fullname);
        cx_seterr("could not find type of doc for %s", fullname);
        goto error;
    }
    
    /* TODO change for createChild when alias is ready */
    
    md_PackageDoc doc = cx_declareChild(data->lastScope, docName, docType);
    if (doc == NULL) {
        cx_dealloc(docName);
        goto error;
    }
    if (!cx_checkState(doc, CX_DEFINED)) {
        cx_setref(&md_Doc(doc)->o, o);
        if (cx_define(doc)) {
            cx_seterr("could not define %s", cx_nameof(o));
            goto error;
        }
        data->lastScope = doc;
    }
finish:
    return 0;
error:
    return 1;
}

int md_renderPackage(cx_object o, md_parseData* data) {
    data->lastScope = data->destination;
    if (md_createDocTree(o, data)) {
        goto error;
    }
    return 0;
error:
    return 1;
}

int md_renderType(cx_object o, md_parseData* data) {
    data->lastScope = data->destination;
    if (md_createDocTree(o, data)) {
        goto error;
    }
    return 0;
error:
    return 1;
}

int md_renderMethod(cx_object o, md_parseData* data) {
    data->lastScope = data->destination;
    if (md_createDocTree(o, data)) {
        goto error;
    }
    return 0;
error:
    return 1;
}

int md_renderArgument(cx_object o, md_parseData* data) {
    CX_UNUSED(o);
    CX_UNUSED(data);
    return 0;
}
