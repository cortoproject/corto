/* $CORTO_GENERATED
 *
 * table.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_table_construct(
    corto_table this)
{
/* $begin(corto/lang/table/construct) */

    if (corto_class_construct(this)) {
        goto error;
    }

    if (this->keylist.length != 0) {
        /* If a keylist was provided, test if members have been added to the table
         * type, and ensure the KEY modifier is enabled */
        corto_int32 i;
        for (i = 0; i < this->keylist.length; i++) {
            corto_object o = corto_lookup(this, this->keylist.buffer[i]);
            if (!o) {
                corto_seterr("no member with name '%s' found for table '%s'",
                    this->keylist.buffer[i],
                    corto_fullpath(NULL, this));
                goto error;
            }

            if (!corto_instanceof(corto_member_o, o)) {
                corto_seterr("object '%s' in table '%s' is not a member",
                    corto_fullpath(NULL, o),
                    corto_fullpath(NULL, this));
                goto error;
            }

            corto_member m = corto_member(o);
            m->modifiers |= CORTO_KEY;

            this->keycache.buffer = 
                corto_realloc(this->keycache.buffer, 
                    sizeof(corto_object) * (this->keycache.length + 1));
            this->keycache.buffer[this->keycache.length] = m;
            corto_claim(m);
            this->keycache.length ++;

            corto_release(o);
        }
    } else {
        /* If no keylist was provided, walk over members and add keys to the
         * list automatically based on order of occurrence. */
        corto_int32 i;
        corto_interface interface = corto_interface(this);
        for (i = 0; i < interface->members.length; i ++) {
            corto_member m = interface->members.buffer[i];
            if (m->modifiers & CORTO_KEY) {
                this->keylist.buffer = 
                    corto_realloc(this->keylist.buffer, 
                        sizeof(char*) * (this->keylist.length + 1));
                this->keylist.buffer[this->keylist.length] = 
                    corto_strdup(corto_idof(m));
                this->keylist.length ++;

                this->keycache.buffer = 
                    corto_realloc(this->keycache.buffer, 
                        sizeof(corto_object) * (this->keycache.length + 1));
                this->keycache.buffer[this->keycache.length] = m;
                corto_claim(m);
                this->keycache.length ++;   
            }
        }
    }

    corto_setref(&corto_type(this)->options.parentType, corto_tablescope_o);

    return 0;
error:
    return -1;
/* $end */
}
