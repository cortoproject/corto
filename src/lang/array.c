/* This is a managed file. Do not delete this comment. */

#include <corto>

int16_t corto_array_construct(
    corto_array this)
{
    corto_uint32 element_typeSize;
    corto_type element_type;

    /* Copy array element_type to collection, transfer ownership of reference. */
    if (this->element_type) {
        if (!corto_collection(this)->element_type) {
            corto_set_ref(
                &corto_collection(this)->element_type, this->element_type);
        }
    } else if (corto_collection(this)->element_type) {
        if (!this->element_type) {
            corto_set_ref(
                &this->element_type, corto_collection(this)->element_type);

        }
    } else {
        ut_throw("no element_type provided for array");
        goto error;
    }

    /* Arrays can only be defined when their element_type is also defined. */
   if (!corto_check_state((corto_collection(this)->element_type), CORTO_VALID)) {
       if (!(corto_instanceof(
           corto_type(corto_type_o), corto_collection(this)->element_type) &&
           corto_type(corto_collection(this)->element_type)->reference))
       {
            ut_throw(
                "element_type '%s' is not defined",
                corto_fullpath(NULL, corto_collection(this)->element_type));
            goto error;
       }
   }

   element_type = corto_collection(this)->element_type;

   /* Calculate the size of the array */
    element_typeSize = corto_type_sizeof(element_type);
    if (element_typeSize) {
        if (corto_collection(this)->max) {
            corto_type(this)->size = element_typeSize * corto_collection(this)->max;
            corto_type(this)->alignment = corto_type_alignmentof(element_type);
        } else {
            ut_throw("array has size 0",
                corto_fullpath(NULL, this));
            goto error;
        }
    } else {
        ut_throw("element_type '%s' has size 0",
            corto_fullpath(NULL, element_type), corto_fullpath(NULL, this));
        goto error;
    }

    if (element_type->flags & CORTO_TYPE_HAS_RESOURCES) {
        corto_type(this)->flags |= CORTO_TYPE_HAS_RESOURCES;
    }
    if (element_type->flags & CORTO_TYPE_HAS_REFERENCES ||
        element_type->reference)
    {
        corto_type(this)->flags |= CORTO_TYPE_HAS_REFERENCES;
    }
    if (element_type->flags & CORTO_TYPE_NEEDS_INIT) {
        corto_type(this)->flags |= CORTO_TYPE_NEEDS_INIT;
    }

    return corto_type_construct(corto_type(this));
error:
    return -1;
}

void corto_array_destruct(
    corto_array this)
{
    corto_release(this->element_type);
    this->element_type = NULL;
    corto_release(corto_collection(this)->element_type);
    corto_collection(this)->element_type = NULL;
    corto_type_destruct(corto_type(this));
}

int16_t corto_array_init(
    corto_array this)
{
    corto_collection(this)->kind = CORTO_ARRAY;
    return corto_collection_init(corto_collection(this));
}
