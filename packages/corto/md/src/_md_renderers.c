#include "_md_renderers.h"

static int md_createPackageDocRecursively(cx_object* scope, cx_object o) {
    if (o == root_o) {
        goto finish;
    }
    md_createPackageDocRecursively(scope, cx_parentof(o));
    cx_string docName;
    if (cx_typeof(o)->kind == CX_PROCEDURE) {
        cx_id signatureName;
        cx_signatureName(cx_nameof(o), signatureName);
        docName = signatureName;
    } else {
        docName = cx_nameof(o);
    }
    md_PackageDoc packageDoc = cx_declareChild(*scope, docName, md_PackageDoc_o);
    if (!packageDoc) {
        goto error;
    }
    cx_setref(&md_Doc(packageDoc)->o, o);
    cx_define(packageDoc);
    *scope = packageDoc;
finish:
    return 0;
error:
    return 1;
}

/*
 *
 */
int md_renderPackage(cx_string name, md_parseData* data) {
    /*
     * TODO, shoudn't do resolve but lookup.
     * but lookup doesn't accept scoped::names
     */
    cx_id fullname;
    fullname[0] = fullname[1] = ':';
    strcpy(fullname + 2, name);
    cx_object o = cx_resolve(root_o, fullname);
    if (!o) {
        cx_error("Cannot find %s", name);
        goto error;
    }
    cx_object scope = data->destination;
    if (md_createPackageDocRecursively(&scope, o)) {
        goto error;
    }
    cx_release(o);
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
