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

/** @file
 * @section fmt Serialization
 * @brief Serialize values from and to registered formats.
 */

#ifndef CORTO_FMT
#define CORTO_FMT

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_fmt_s *corto_fmt;

typedef struct corto_fmt_opt {
    const char *from;
} corto_fmt_opt;


/** Serialize object to a registered serialization format
 *
 * This serializes an object and its metadata to a registered serialization
 * format. Serialization formats are packages stored in driver/fmt.
 *
 * @param o The object to serialize.
 * @param fmtId The serialization format identifier (for example: "text/json").
 * @return The serialized value.
 * @see corto_deserialize corto_serialize_value corto_deserialize_value
 */
CORTO_EXPORT
char *corto_serialize(
    corto_object o,
    const char *fmtId);

/** Deserialize object from a registered serialization format
 *
 * This deserializes a value in a registered serialization format to an object.
 * The function accepts a pointer to an object reference, which may be NULL. If
 * the pointer is NULL, a new object will be created.
 *
 * If the pointer is not NULL and the serialized data does not match with the
 * specified object identifier or type, the function will fail.
 *
 * @param o Pointer to the object to deserialize into. Object may be NULL.
 * @param fmtId The serialization format identifier (for example: "text/json").
 * @param data Value formatted in the specified serialization format.
 * @return 0 if success, non-zero if failed.
 * @see corto_serialize corto_serialize_value corto_deserialize_value
 */
CORTO_EXPORT
int16_t corto_deserialize(
    void *o,
    const char *fmtId,
    const char *data);

/** Serialize object value to a registered serialization format
 *
 * This serializes an object value to a registered serialization
 * format. This function does not serialize object metadata, like type and id.
 * Serialization formats are packages stored in driver/fmt.
 *
 * @param o The object to serialize.
 * @param fmtId The serialization format identifier (for example: "text/json").
 * @return The serialized value.
 * @see corto_deserialize_value corto_serialize corto_deserialize
 */
CORTO_EXPORT
char *corto_serialize_value(
    corto_object o,
    const char *fmtId);

/** Deserialize object value from a registered serialization format
 *
 * This deserializes a value in a registered serialization format to an object.
 *
 * @param o The object to deserialize into.
 * @param fmtId The serialization format identifier (for example: "text/json").
 * @param data Value formatted in the specified serialization format.
 * @return 0 if success, non-zero if failed.
 * @see corto_serialize_value corto_serialize corto_deserialize
 */
CORTO_EXPORT
int16_t corto_deserialize_value(
    corto_object o,
    const char *fmtId,
    const char *data);


/** Obtain handle to a serialization format plugin.
 *
 * This function provides a high(er) performance alternative to looking up
 * serialization formats by id, by returning a handle to a format that can
 * be reused.
 *
 * @param fmtId The serialization format identifier.
 * @return Handle to a serialization format plugin. NULL if failed.
 */
CORTO_EXPORT
corto_fmt corto_fmt_lookup(
    const char *fmtId);


CORTO_EXPORT
void* corto_fmt_from_value(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_value *v);

CORTO_EXPORT
int16_t corto_fmt_to_value(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_value *v,
    const void *data);

CORTO_EXPORT
void* corto_fmt_from_result(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_record *result);

CORTO_EXPORT
int16_t corto_fmt_to_result(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_record *result,
    const void *data);

CORTO_EXPORT
void* corto_fmt_from_object(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_object object);

CORTO_EXPORT
int16_t corto_fmt_to_object(
    corto_fmt fmt,
    corto_fmt_opt *opt,
    corto_object *object_out,
    const void *data);

CORTO_EXPORT
void* corto_fmt_copy(
    corto_fmt fmt,
    const void *data);

CORTO_EXPORT
void corto_fmt_release(
    corto_fmt fmt,
    void *data);

#ifdef __cplusplus
}
#endif

#endif
