#include "_md_resolvers.h"

cx_object md_resolvePackage(cx_string name, md_parseData* data) {
    CX_UNUSED(data);
    cx_string fullnameNoRoot = NULL;
    if (name[0] == ':') {
        fullnameNoRoot = name + 2;
    } else {
        fullnameNoRoot = name;
    }
    cx_object o = cx_resolve(root_o, fullnameNoRoot);
    /* TODO double check that the name is effectively in root */
    if (!o) {
        cx_error("Cannot find %s", fullnameNoRoot);
        goto error;
    }
    if (!cx_instanceof(cx_package_o, o)) {
        cx_error("%s is not a package", fullnameNoRoot);
        goto error;
    }
    return o;
error:
    return NULL;
}

cx_object md_resolveType(cx_string name, md_parseData* data) {
    if (!cx_instanceof(md_PackageDoc_o, data->lastScope)) {
        cx_error("%s not in the scope of a PackageDoc");
        goto error;
    }

    cx_package package = cx_package(md_Doc(data->lastScope)->o);
    cx_object o = cx_resolve(package, name);
    /*
     * TODO This checks if cx_resolve did not resolve from special scopes
     * like ::corto::lang and ::corto
     */
    if (!o || cx_parentof(o) != package) {
        cx_id packageFullname;
        cx_fullname(package, packageFullname);
        cx_seterr("cannot find %s::%s", packageFullname, name);
        goto error;
    }
    if (!cx_instanceof(cx_type_o, o)) {
        cx_id fullname;
        cx_fullname(o, fullname);
        cx_seterr("%s is not a type", fullname);
        goto error;
    }
    return o;
error:
    return NULL;
}

cx_object md_resolveMethod(cx_string name, md_parseData* data) {
    if (!cx_instanceof(md_TypeDoc_o, data->lastScope)) {
        cx_seterr("%s not in the scope of a TypeDoc");
        goto error;
    }
    
    cx_type type = cx_type(md_Doc(data->lastScope)->o);
    cx_object o = cx_resolve(type, name);
    if (!o || cx_parentof(o) != type) {
        cx_id typeFullname;
        cx_fullname(type, typeFullname);
        cx_seterr("cannot find %s::%s", typeFullname, name);
        goto error;
    }
    if (!cx_instanceof(cx_method_o, o)) {
        cx_id fullname;
        cx_fullname(o, fullname);
        cx_seterr("%s is not a method", fullname);
        goto error;
    }
    return o;
error:
    return NULL;
}
