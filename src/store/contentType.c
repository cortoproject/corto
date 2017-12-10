/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>
#include "object.h"
#include "memory_ser.h"
#include "init_ser.h"

extern corto_mutex_s corto_adminLock;

static corto_ll contentTypes = NULL;

static
corto_word corto_contentType_ptr_fromValue(
    corto_value *v)
{
    corto_type t = corto_value_typeof(v);
    void *ptr = corto_mem_new(t);
    corto_value dst = corto_value_mem(ptr, t);
    if (t->flags & CORTO_TYPE_NEEDS_INIT) {
        corto_walk_opt s =
            corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
        if (corto_walk_value(&s, &dst, NULL)) {
            goto error;
        }
    }

    if (t->flags & CORTO_TYPE_HAS_RESOURCES) {
        if (corto_value_copy(&dst, v)) {
            return 0;
        }
    } else {
        memcpy(ptr, corto_value_ptrof(v), t->size);
    }

    return (corto_word)ptr;
error:
    return 0;
}

static
corto_int16 corto_contentType_ptr_toValue(
    corto_value *v,
    corto_word ptr)
{
    corto_type t = corto_type(*(corto_type*)CORTO_OFFSET(ptr, -sizeof(corto_type)));
    *v = corto_value_mem((void*)ptr, t);
    return 0;
}

static
void corto_contentType_ptr_release(
    corto_word ptr)
{
    if (ptr) {
        corto_mem_free((void*)ptr);
    }
}

static
corto_word corto_contentType_ptr_copy(
    corto_word src)
{
    corto_type t = corto_mem_typeof((void*)src);
    corto_value srcValue = corto_value_mem((void*)src, t);
    return corto_contentType_ptr_fromValue(&srcValue);
}

static
corto_word corto_contentType_str_fromValue(
    corto_value *v)
{
    return (corto_word)corto_value_str(v, 0);
}

static
corto_int16 corto_contentType_str_toValue(
    corto_value *v,
    corto_word str)
{
    return corto_value_fromStr(v, (char*)str);
}

static
corto_word corto_contentType_strColor_fromValue(
    corto_value *v)
{
    corto_string_ser_t sdata;
    corto_walk_opt s = corto_string_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    memset(&sdata, 0, sizeof(corto_string_ser_t));
    sdata.enableColors = TRUE;
    s.access = CORTO_PRIVATE;
    s.accessKind = CORTO_NOT;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;
    corto_walk_value(&s, v, &sdata);
    return (corto_word)corto_buffer_str(&sdata.buffer);
}

static
corto_contentType corto_findContentType(
    bool isBinary,
    corto_string contentType)
{
    corto_contentType result = NULL;
    if (contentTypes) {
        corto_iter it = corto_ll_iter(contentTypes);
        while (corto_iter_hasNext(&it)) {
            corto_contentType ct = corto_iter_next(&it);
            if (!strcmp(ct->name, contentType) && (ct->isBinary == isBinary)) {
                result = ct;
                break;
            }
        }
    } else {
        contentTypes = corto_ll_new();
    }

    if (!result && !strcmp(contentType, "corto") && !isBinary) {
        result = corto_alloc(sizeof(struct corto_contentType_s));
        result->name = corto_strdup("corto");
        result->isBinary = isBinary;
        result->toValue = corto_contentType_str_toValue;
        result->fromValue = corto_contentType_str_fromValue;
        result->release = (void ___ (*)(corto_word))corto_dealloc;
        result->copy = (corto_word ___ (*)(corto_word)) corto_strdup;
        corto_ll_append(contentTypes, result);

    } else if (!result && !strcmp(contentType, "corto-color") && !isBinary) {
        result = corto_alloc(sizeof(struct corto_contentType_s));
        result->name = corto_strdup("corto-color");
        result->isBinary = isBinary;
        result->toValue = NULL;
        result->fromValue = corto_contentType_strColor_fromValue;
        result->release = (void ___ (*)(corto_word))corto_dealloc;
        result->copy = (corto_word ___ (*)(corto_word)) corto_strdup;
        corto_ll_append(contentTypes, result);

    } else if (!result && !strcmp(contentType, "corto") && isBinary) {
        result = corto_alloc(sizeof(struct corto_contentType_s));
        result->name = corto_strdup("corto");
        result->isBinary = isBinary;
        result->toValue = corto_contentType_ptr_toValue;
        result->fromValue = corto_contentType_ptr_fromValue;
        result->release = corto_contentType_ptr_release;
        result->copy = corto_contentType_ptr_copy;
        corto_ll_append(contentTypes, result);
    }

    return result;
}

corto_contentType
corto_load_contentType(
    corto_string contentType)
{
    corto_contentType result = NULL;
    bool isBinary = true;

    /* Built-in Corto string serializer */
    char *packagePtr = strchr(contentType, '/');
    if (!packagePtr) {
        corto_throw("invalid content type %s (expected '/')", contentType);
        goto error;
    }

    if (!memcmp(contentType, "text", packagePtr - contentType)) {
        isBinary = false;
    }

    packagePtr ++;

    /* Find content type in admin */
    corto_mutex_lock(&corto_adminLock);
    result = corto_findContentType(isBinary, packagePtr);
    corto_mutex_unlock(&corto_adminLock);

    /* Load contentType outside of lock */
    if (!result) {
        corto_dl dl = NULL;
        corto_id packageId;
        sprintf(packageId, "driver/fmt/%s", packagePtr);

        result = corto_alloc(sizeof(struct corto_contentType_s));
        result->name = corto_strdup(packagePtr);
        result->isBinary = isBinary;

        /* Load package associated with content type */
        if (corto_use(packageId, 0, NULL)) {
            corto_throw("unresolved package '%s' for contentType '%s'",
                packageId, contentType);
            goto error;
        }

        /* Load serialization routines */
        corto_id id;
        sprintf(id, "%s_fromValue", packagePtr);
        result->fromValue =
            (corto_word ___ (*)(corto_value*))corto_load_proc(packageId, &dl, id);
        if (!result->fromValue) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toValue", packagePtr);
        result->toValue =
            (corto_int16 ___ (*)(corto_value*, corto_word)) corto_load_proc(packageId, &dl, id);
        if (!result->toValue) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }


        sprintf(id, "%s_fromResult", packagePtr);
        result->fromResult =
          (corto_word ___ (*)(corto_result*))corto_load_proc(packageId, &dl, id);
        if (!result->fromResult) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toResult", packagePtr);
        result->toResult =
          (corto_int16 ___ (*)(corto_result*, corto_word))corto_load_proc(packageId, &dl, id);
        if (!result->toResult) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }


        sprintf(id, "%s_fromObject", packagePtr);
        result->fromObject =
          (corto_word ___ (*)(corto_object))corto_load_proc(packageId, &dl, id);
        if (!result->fromObject) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toObject", packagePtr);
        result->toObject =
          (corto_int16 ___ (*)(corto_object*, corto_word))corto_load_proc(packageId, &dl, id);
        if (!result->toObject) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_copy", packagePtr);
        result->copy =
            (corto_word ___ (*)(corto_word))corto_load_proc(packageId, &dl, id);
        if (!result->copy) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_release", packagePtr);
        result->release =
            (void ___ (*)(corto_word))corto_load_proc(packageId, &dl, id);
        if (!result->release) {
            corto_throw("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        /* Add to admin, verify that it hasn't been already added by another
         * thread */
         corto_mutex_lock(&corto_adminLock);
         corto_contentType alreadyAdded = corto_findContentType(isBinary, packagePtr);
         if (!alreadyAdded) {
            corto_ll_append(contentTypes, result);
         } else {
            corto_dealloc(result->name);
            corto_dealloc(result);
            result = alreadyAdded;
         }
         corto_mutex_unlock(&corto_adminLock);
    }

    return result;
error:
    return NULL;
}
