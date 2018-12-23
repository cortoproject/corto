/* This is a managed file. Do not delete this comment. */

#include <corto>

#include "src/store/object.h"

void corto_package_define(
    corto_package this)
{
    if (this->_public &&
        !corto_isbuiltin(this) &&
        corto_check_attr(this, CORTO_ATTR_NAMED))
    {
        corto_object owner = corto_sourceof(this);

        /* If owner is a mount, object is being resumed */
        if (owner && corto_instanceof(corto_loader_o, owner)) {
            if (corto_loader(owner)->autoLoad) {
                corto_id id;
                corto_fullpath(id, this);
                if (ut_locate(id, NULL, UT_LOCATE_LIB)) {
                    if (ut_load_intern(
                        id,
                        0, /* No arguments */
                        NULL,
                        true, /* Ignore error thrown by recursive load */
                        false) /* Only load package once */
                    ) {
                        ut_throw("unable to auto-load package '%s'", id);
                        ut_raise();
                    }
                }
            }
        }
    }
}

int16_t corto_package_init(
    corto_package this)
{
    this->_public = true;

    char *ptr = corto_idof(this), ch;
    if (ptr) {
        for (; (ch = *ptr); ptr ++) {
            if (isupper(ch)) {
                ut_throw(
                  "invalid identifier '%s': package identifiers must be all lowercase",
                  corto_idof(this));
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}
