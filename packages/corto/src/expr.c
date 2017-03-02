
#include <src/_object.h>

static corto_int16 ___ (*_corto_expr_compb)(
    ext_corto_expr *out, 
    ext_corto_expr_opt *opt, 
    char *expr, 
    char **types);

static corto_int16 ___ (*_corto_expr_runb)(
    ext_corto_expr *expr, 
    corto_value *out, 
    void **args);

static corto_int16 ___ (*_corto_expr_free)(
    ext_corto_expr *expr);

static corto_int16 ext_corto_expr_load() {

    if (!_corto_expr_free) {
        corto_string package = corto_locate("corto/expr", CORTO_LOCATION_LIB);
        if (!package) {
            corto_seterr("package 'corto/expr' not found: %s", corto_lasterr());
            goto error;
        }
        corto_dl dl;
        if ((dl = corto_loadValidLibrary(package, NULL))) {

            /* Load package */
            if (corto_loadFromDl(dl, package, 0, NULL)) {
                goto error;
            }

            corto_dealloc(package);

            _corto_expr_compb = (corto_int16 ___ (*)(ext_corto_expr*,ext_corto_expr_opt*,char*,char**))corto_dlProc(dl, "corto_expr_compb");
            if (!_corto_expr_compb) {
                corto_seterr("corto_expr_compb not found in corto/expr");
                goto error;
            }
            _corto_expr_runb = (corto_int16 ___ (*)(ext_corto_expr*,corto_value*,void**))corto_dlProc(dl, "corto_expr_runb");
            if (!_corto_expr_runb) {
                corto_seterr("corto_expr_runb not found in corto/expr");
                goto error;
            }

            _corto_expr_free = (corto_int16 ___ (*)(ext_corto_expr*))corto_dlProc(dl, "corto_expr_free");
            if (!_corto_expr_free) {
                corto_seterr("corto_expr_free not found in corto/expr");
                goto error;
            }
        } else {
            corto_seterr("package 'corto/expr' not loaded: %s", corto_lasterr());
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

ext_corto_expr* ext_corto_expr_alloc(void) {
    return corto_calloc(sizeof(ext_corto_expr));
}

corto_int16 ext_corto_expr_compb(
    ext_corto_expr *out, 
    ext_corto_expr_opt *opt, 
    char *expr, 
    char **types) 
{
    if (ext_corto_expr_load()) {
        goto error;
    }

    return _corto_expr_compb(out, opt, expr, types);
error:
    return -1;
}

corto_int16 ext_corto_expr_runb(
    ext_corto_expr *expr, 
    corto_value *out, 
    void **args) 
{
    if (ext_corto_expr_load()) {
        goto error;
    }

    return _corto_expr_runb(expr, out, args);
error:
    return -1;
}

corto_int16 ext_corto_expr_free(ext_corto_expr *expr) {
    if (ext_corto_expr_load()) {
        goto error;
    }

    _corto_expr_free(expr);

    return 0;
error:
    return -1;
}
