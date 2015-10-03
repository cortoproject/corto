#include "_md_renderers.h"

static int md_createPackageDocRecursively(cx_object o, md_parseData* data) {
    if (o == root_o) {
        goto finish;
    }
    if (md_createPackageDocRecursively(cx_parentof(o), data)) {
        goto error;   
    }
    cx_string docName;
    cx_type type = cx_typeof(o);
    if (type->kind == CX_COMPOSITE && cx_interface(type)->kind == CX_PROCEDURE) {
        cx_id signatureName;
        cx_signatureName(cx_nameof(o), signatureName);
        docName = signatureName;
    } else {
        docName = cx_nameof(o);
    }
    /* TODO change for createChild when alias is ready */
    md_PackageDoc packageDoc = md_PackageDocDeclareChild(data->lastScope, docName);
    if (!packageDoc) {
        goto error;
    }
    cx_setref(&md_Doc(packageDoc)->o, o);
    cx_define(packageDoc);
    data->lastScope = packageDoc;
finish:
    return 0;
error:
    return 1;
}

int md_renderPackage(cx_object o, md_parseData* data) {
    data->lastScope = data->destination;
    if (md_createPackageDocRecursively(o, data)) {
        goto error;
    }
    cx_release(o);
    return 0;
error:
    return 1;
}

int md_renderType(cx_object o, md_parseData* data) {
    md_PackageDoc packageDoc = md_PackageDoc(data->lastScope);
    /* TODO change for createChild when alias is ready */
    cx_object typeDoc = md_TypeDocCreateChild(packageDoc, cx_nameof(o));
    if (!typeDoc) {
        goto error;
    }
    cx_setref(&md_Doc(typeDoc)->o, o);
    cx_define(typeDoc);
    data->lastScope = typeDoc;
    return 0;
error:
    return 1;
}

int md_renderMethod(cx_object o, md_parseData* data) {
    md_TypeDoc typeDoc = md_TypeDoc(data->lastScope);
    cx_object methodDoc = md_MethodDocCreateChild(typeDoc, cx_nameof(o));
    if (!methodDoc) {
        goto error;
    }
    cx_setref(&md_Doc(methodDoc)->o, o);
    cx_define(methodDoc);
    data->lastScope = methodDoc;
    return 0;
error:
    return 1;
}

int md_renderArgument(cx_object o, md_parseData* data) {
    CX_UNUSED(o);
    CX_UNUSED(data);
    return 0;
}
