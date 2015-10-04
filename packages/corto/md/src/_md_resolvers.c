#include "_md_resolvers.h"

cx_object md_resolvePackage(cx_string name, md_parseData* data) {
    CX_UNUSED(data);
    cx_string fullnameNoRoot = NULL;
    if (name[0] == ':') {
        fullnameNoRoot = name + 2;
    } else {
        fullnameNoRoot = name;
    }
    cx_object o = cx_resolve(NULL, fullnameNoRoot);
    /* TODO double check that the name is effectively in root */
    if (!o) {
        puts("COULDN'T FIND IT");
        puts(cx_nameof(o));
        cx_seterr("could not find %s", fullnameNoRoot);
        goto error;
    }
    if (!cx_instanceof(cx_package_o, o)) {
        cx_seterr("%s is not a package", fullnameNoRoot);
        goto error;
    }
    return o;
error:
    return NULL;
}

cx_object md_resolveType(cx_string name, md_parseData* data) {
    /*
     * Traverse the tree until previous package is found or the documentation
     * root scope is reached.
     */
    cx_object lastScope = md_Doc(data->lastScope);
    
    while (!cx_instanceof(md_PackageDoc_o, lastScope)) {
        if (lastScope == data->destination) {
            cx_seterr("could not find enclosing package for %s", name);
            goto error;
        }
        lastScope = cx_parentof(lastScope);
    }
    data->lastScope = lastScope;

    cx_package package = cx_package(md_Doc(lastScope)->o);
    cx_object o = cx_resolve(package, name);
    /*
     * TODO This checks if cx_resolve did not resolve from special scopes
     * like ::corto::lang and ::corto
     */
    if (!o || cx_parentof(o) != package) {
        cx_id packageFullname;
        cx_fullname(package, packageFullname);
        cx_seterr("could not find %s::%s", packageFullname, name);
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
    /*
     * Traverse the tree until previous type is found or the documentation
     * root scope is reached.
     */
    cx_object lastScope = md_Doc(data->lastScope);
    while (!cx_instanceof(md_TypeDoc_o, lastScope)) {
        if (lastScope == data->destination) {
            cx_seterr("could not find enclosing type for %s", name);
            goto error;
        }
        lastScope = md_Doc(cx_parentof(lastScope));
    }
    
    cx_type type = cx_type(md_Doc(lastScope)->o);
    cx_object o = cx_resolve(type, name);
    if (!o || cx_parentof(o) != type) {
        cx_id typeFullname;
        cx_fullname(type, typeFullname);
        cx_seterr("could not find %s::%s", typeFullname, name);
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
