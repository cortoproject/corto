/* $CORTO_GENERATED
 *
 * type.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
#include "_interface.h"

corto_int16 corto_type_bindMetaprocedure(corto_type this, corto_metaprocedure procedure) {
    corto_function* f;
    corto_int32 d = 0;

    /* Check if function is overloaded */
    if ((f = corto_vtableLookup(&this->metaprocedures, corto_idof(procedure), &d))) {
        if (d) {
            corto_function(*f)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            corto_function(procedure)->overloaded = TRUE;
        } else {
            if (*f != corto_function(procedure)) {
                /* Overriding metaprocedures is not allowed. */
                corto_seterr(
                  "definition of metaprocedure '%s' conflicts with existing '%s'",
                  corto_fullpath(NULL, *f),
                  corto_fullpath(NULL, procedure));
                goto error;
            }
        }
    }

    if (corto_vtableInsert(&this->metaprocedures, corto_function(procedure))) {
        corto_claim(procedure);
    }
    return 0;
error:
    return -1;
}
/* $end */

corto_uint16 _corto_type_alignmentof(
    corto_type this)
{
/* $begin(corto/lang/type/alignmentof) */
    corto_uint16 alignment;

    if (this->reference) {
        alignment = CORTO_ALIGNMENT(corto_object);
    } else {
        alignment = this->alignment;
    }
    return alignment;
/* $end */
}

corto_bool _corto_type_castable_v(
    corto_type this,
    corto_type type)
{
/* $begin(corto/lang/type/castable) */
    corto_bool result = FALSE;

    if (this->kind == CORTO_VOID) { /* A void reference can be casted to any reference type */
        if (this->reference && type->reference) {
            return TRUE;
        }
    }

    if (!result) {
        result = corto_type_compatible_v(this, type);
    }

    return result;
/* $end */
}

corto_bool _corto_type_checkAttr(corto_any this,
    corto_attr attributes)
{
/* $begin(corto/lang/type/checkAttr) */
    return corto_checkAttr(this.value, attributes);
/* $end */
}

corto_bool _corto_type_checkState(corto_any this,
    corto_state state)
{
/* $begin(corto/lang/type/checkState) */
    return corto_checkState(this.value, state);
/* $end */
}

corto_equalityKind _corto_type_compare(corto_any this,
    corto_any value)
{
/* $begin(corto/lang/type/compare) */
    corto_compare_ser_t data;
    struct corto_serializer_s s;
    corto_value v1;

    v1 = corto_value_value(corto_type(this.type), this.value);
    data.value = corto_value_value(corto_type(value.type), value.value);

    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);

    corto_serializeValue(&s, &v1, &data);

    return data.result;
/* $end */
}

corto_bool _corto_type_compatible_v(
    corto_type this,
    corto_type type)
{
/* $begin(corto/lang/type/compatible) */
    corto_bool result;

    result = FALSE;

    if (this != type) {
        if (this->kind == CORTO_ANY) {
            result = TRUE;
        } else if (this->reference == type->reference) {
            if (type->reference) {
                if (this->kind == CORTO_VOID) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

corto_int16 _corto_type_construct(
    corto_type this)
{
/* $begin(corto/lang/type/construct) */
    switch(this->kind) {
    case CORTO_ANY:
        this->size = sizeof(corto_any);
        this->alignment = CORTO_ALIGNMENT(corto_any);
        break;
    case CORTO_VOID:
        this->size = this->reference ? sizeof(void*) : 0;
        this->alignment = CORTO_ALIGNMENT(void*);
    default:
        break;
    }
    return 0;
/* $end */
}

corto_int16 _corto_type_copy(corto_any this,
    corto_any value)
{
/* $begin(corto/lang/type/copy) */
    corto_copy_ser_t data;
    struct corto_serializer_s s;
    corto_value v1;
    corto_int16 result;

    if (this.type->reference || value.type->reference) {
        data.value = corto_value_object(this.value, NULL);
        v1 = corto_value_object(value.value, NULL);
    } else {
        data.value = corto_value_value(corto_type(this.type), this.value);
        v1 = corto_value_value(corto_type(value.type), value.value);
    }

    s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);

    if ((result = corto_serializeValue(&s, &v1, &data))) {
        corto_seterr(
          "type/copy: failed to copy value of type '%s' to value of type '%s'",
          corto_fullpath(NULL, this.type), corto_fullpath(NULL, value.type));
    }

    return result;
/* $end */
}

corto_object _corto_type_declare(corto_any this,
    corto_string name,
    corto_type type)
{
/* $begin(corto/lang/type/declare) */
    corto_object result = corto_declareChild(this.value, name, type);
    corto_claim(result);
    return result;
/* $end */
}

corto_int16 _corto_type_define(corto_any this)
{
/* $begin(corto/lang/type/define) */
    return corto_define(this.value);
/* $end */
}

corto_void _corto_type_delete(corto_any this)
{
/* $begin(corto/lang/type/delete) */
    corto_delete(this.value);
/* $end */
}

corto_void _corto_type_destruct(
    corto_type this)
{
/* $begin(corto/lang/type/destruct) */
    corto_uint32 i;

    /* Free methods */
    for(i=0; i<this->metaprocedures.length; i++) {
        corto_release(this->metaprocedures.buffer[i]);
    }

    if (this->metaprocedures.buffer) {
        corto_dealloc(this->metaprocedures.buffer);
        this->metaprocedures.buffer = NULL;
    }
/* $end */
}

corto_string _corto_type_fullpath(corto_any this)
{
/* $begin(corto/lang/type/fullpath) */
    corto_string result = NULL;

    if (this.value) {
        corto_id id;
        result = corto_strdup(corto_fullpath(id, this.value));
    } else {
        result = corto_strdup("null");
    }

    return result;
/* $end */
}

corto_int16 _corto_type_init(
    corto_type this)
{
/* $begin(corto/lang/type/init) */
    if (!this->parentState) {
        this->parentState = CORTO_DECLARED | CORTO_DEFINED;
    }
    return 0;
/* $end */
}

corto_bool _corto_type_instanceof(corto_any this,
    corto_type type)
{
/* $begin(corto/lang/type/instanceof) */
    return corto_instanceof(type, this.value);
/* $end */
}

corto_void _corto_type_invalidate(corto_any this)
{
/* $begin(corto/lang/type/invalidate) */
    corto_invalidate(this.value);
/* $end */
}

corto_object _corto_type_lookup(corto_any this,
    corto_string name)
{
/* $begin(corto/lang/type/lookup) */
    return corto_lookup(this.value, name);
/* $end */
}

corto_string _corto_type_name(corto_any this)
{
/* $begin(corto/lang/type/name) */
    corto_string result = NULL;

    if (this.value) {
        result = corto_idof(this.value);
        if(result) {
            result = corto_strdup(result);
        }
    } else {
        result = corto_strdup("null");
    }

    return result;
/* $end */
}

corto_object _corto_type_parent(corto_any this)
{
/* $begin(corto/lang/type/parent) */
    corto_string result = NULL;

   if (corto_checkAttr(this.value, CORTO_ATTR_SCOPED)) {
       result = corto_parentof(this.value);
   } else {
       corto_error("cannot get parent from non-scoped object of type '%s'",
          corto_fullpath(NULL, corto_typeof(this.value)));
   }

   if (result) {
       corto_claim(result);
   }

   return result;
/* $end */
}

corto_string _corto_type_path(corto_any this,
    corto_object from)
{
/* $begin(corto/lang/type/path) */
    corto_string result = NULL;
    corto_id id;

    if (this.value) {
        result = corto_strdup(corto_path(id, from, this.value, "/"));
    } else {
        result = corto_strdup("null");
    }

    return result;
/* $end */
}

corto_object _corto_type_resolve(corto_any this,
    corto_string name)
{
/* $begin(corto/lang/type/resolve) */
    return corto_resolve(this.value, name);
/* $end */
}

corto_function _corto_type_resolveProcedure(
    corto_type this,
    corto_string name)
{
/* $begin(corto/lang/type/resolveProcedure) */
    corto_function result = NULL;

    /* If type is an interface, try first to resolve a method on the interface */
    if (corto_instanceof((corto_type)corto_interface_o, this)) {
        result = (corto_function)corto_interface_resolveMethod(corto_interface(this), name);
    }

    /* If no method is found or type is not an interface, resolve metaprocedure */
    if (!result) {
        corto_function *f;
        corto_int32 d = 0, prevD = 9999;
        corto_class metaclass = corto_class(corto_typeof(this));

        /* Walk inheritance of metaclass to find metaprocedure */
        do {
            if ((f = corto_vtableLookup(&corto_type(metaclass)->metaprocedures, name, &d))) {
                if (d < prevD) {
                    result = *f;
                    prevD = d;
                }
            }
            metaclass = corto_class(corto_interface(metaclass)->base);
        }while(metaclass && !result);
    }

    return result;
/* $end */
}

corto_uint32 _corto_type_sizeof(
    corto_type this)
{
/* $begin(corto/lang/type/sizeof) */
    corto_uint32 size;
    if (this->reference) {
        size = sizeof(corto_object);
    } else {
        size = this->size;
    }
    return size;
/* $end */
}

corto_string _corto_type_str(corto_any this)
{
/* $begin(corto/lang/type/str) */
    corto_value value;
    corto_string result;

    if (this.value) {
        if (this.type->reference) {
            value = corto_value_object(this.value, NULL);
        } else {
            value = corto_value_value(this.type, this.value);
        }
        result = corto_strv(&value, 0);
    } else {
        result = corto_strdup("null");
    }

    return result;
/* $end */
}

corto_type _corto_type_type(corto_any this)
{
/* $begin(corto/lang/type/type) */
    corto_type result = NULL;

    result = this.type;

    if (result) {
        corto_claim(result);
    }

    return result;
/* $end */
}
