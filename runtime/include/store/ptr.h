/* Copyright (c) 2010-2017 the corto developers
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
 * @section ptr Ptr API
 * @brief API for native pointers.
 *
 * This API allows applications to utilize the corto typesystem with values that
 * are either allocated on the stack or the heap. All API functions accept at
 * least a pointer value and a corresponding type. The value pointed to by the
 * pointer must be at least of the size prescribed by the type, and must contain
 * a valid value.
 *
 * For safe creation of values on heap or stack, use `corto_ptr_new` and 
 * `corto_ptr_init`. To ensure that an application does not leak memory, ensure
 * to call `corto_ptr_free` for heap values created with `corto_ptr_new`, and call
 * `corto_ptr_deinit` for stack/heap values initialized with `corto_ptr_init`.
 */

#ifndef CORTO_PTR_H_
#define CORTO_PTR_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Allocate a new value on the heap.
 * This function allocates a new value on the heap that can hold the value of a
 * corto type. If the specified type is a reference type, a pointer-sized value
 * is returned. This function will invoke the initializer for the specified type.
 *
 * Note that the result of this function is a plain heap object, not a corto object, 
 * so you cannot use functions that accept a corto_object instance.
 *
 * To avoid memory leakage, the result of this function must be deallocated with
 * corto_ptr_free.
 *
 * @param type The type for which to create the value.
 * @return An initialized value on the heap for the specified type.
 * @see corto_ptr_free
 */
CORTO_EXPORT
void* _corto_ptr_new(
    corto_type type);

/** Deallocate a value allocated with corto_ptr_new.
 * This function deallocates a value allocated with corto_ptr_new and will invoke
 * the deinitializer for the specified type.
 *
 * @param type The type of the value to be deallocated.
 * @param ptr A pointer to the value.
 * @see corto_ptr_new
 */
CORTO_EXPORT
void _corto_ptr_free(
    void *ptr, corto_type type);

/** Populate a collection with specified number of elements.
 * This function fills a collection with initialized elements. Depending on
 * the kind of the collection the function will either populate an array, sequence
 * or list. This function is not valid for map collection types.
 *
 * If the provided collection is not empty, the existing elements will be 
 * deinitialized. Note that for array types the size is fixed, and if the
 * function finds an existing array it won't do anything.
 *
 * To free the resources, either call this function with size 0 or call the
 * `corto_ptr_free` function.
 *
 * This function may fail if the initializer of the elementType fails or if the
 * specified size exceeds the bound of the collection type.
 *
 * @param ptr A pointer to the collection
 * @param type The type for which to initialize the collection.
 * @param size The size to which to grow/shrink the collection.
 * @return 0 if success, -1 if failed.
 * @see corto_ptr_free
 */
CORTO_EXPORT
int16_t _corto_ptr_size(
    void *ptr,
    corto_type type,
    uint32_t size);

/** Return the number of elements in a type.
 * This function will return the number of elements in the specified pointer. If
 * the pointer is of an array type, the function will always return the max size
 * of the array. If the pointer is of any other collection type, the function
 * will return the current size.
 *
 * If this function is called on a non-collection type, it will return 1.
 *
 * @param ptr A pointer to the collection
 * @param type The type for which to initialize the collection.
 * @return 0 if success, -1 if failed.
 * @see corto_ptr_free
 */
CORTO_EXPORT
uint64_t _corto_ptr_count(
    void *ptr,
    corto_type type);

/** Serialize pointer to a specified format.
 * @param ptr A pointer to the value.
 * @param type The type of the value.
 * @param contentType The contentType to serialize to.
 * @return A serialized string for the value. Must be deallocated with free.
 * @see corto_ptr_str
 */
CORTO_EXPORT
char *_corto_ptr_contentof(
    void *ptr, corto_type type, char *contentType);

/** Get a corto string representation for value.
 * This function is equivalent to calling `corto_ptr_contentof` with content
 * type `text/corto`.
 *
 * @param ptr A pointer to the value.
 * @param type The type of the value.
 * @param maxLength The type of the value.
 * @return A serialized corto string for the value. Must be deallocated with free.
 * @see corto_ptr_fromStr corto_ptr_contentof
 */
CORTO_EXPORT
char *_corto_ptr_str(
    void *ptr, corto_type type, uint32_t maxLength);

/** Deserialize a string into a value.
 * @param ptr A pointer to the value.
 * @param type The type of the value.
 * @param str The string to deserialize into the value.
 * @return A serialized corto string for the value. Must be deallocated with free.
 * @see corto_ptr_str
 */
CORTO_EXPORT
int16_t _corto_ptr_fromStr(
    void *ptr,
    corto_type type,
    char *str);

/** Copy value into another value.
 * @param dst A pointer to the destination value.
 * @param type The type of the source and destination value.
 * @param src A pointer to the source value.
 * @return 0 if success, nonzero if failed.
 */
CORTO_EXPORT
int16_t _corto_ptr_copy(
    void *dst,
    corto_type type,
    void *src);

/** Perform unary operator on a value.
 * @param type The type of the value.
 * @param _operator The operator to perform.
 * @param ptr A pointer to the operand value.
 * @param result A pointer to the result value.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_binaryOp corto_ptr_cast
 */
CORTO_EXPORT
int16_t corto_ptr_unaryOp(
    corto_type type,
    corto_operatorKind _operator,
    void* ptr,
    void* result);

/** Perform binary operator with two values.
 * @param type The type of the left and right value.
 * @param _operator The operator to perform.
 * @param left A pointer to the left operand value.
 * @param left A pointer to the right operand value.
 * @param result A pointer to the result value.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_unaryOp corto_ptr_cast
 */
CORTO_EXPORT
int16_t corto_ptr_binaryOp(
    corto_type type,
    corto_operatorKind _operator,
    void *left,
    void *right,
    void *result);

/** Cast a value.
 * @param fromType The type of the value to cast.
 * @param from A pointer to the value to cast.
 * @param resultType The type to cast to.
 * @param result A pointer to the result of the cast.
 * @return 0 if success, nonzero if failed.
 * @see corto_ptr_unaryOp corto_ptr_binaryOp
 */
CORTO_EXPORT
int16_t _corto_ptr_cast(
    corto_type fromType,
    void *from,
    corto_type resultType,
    void *result);

/** Compare two values.
 * Both values must be instances of the same type.
 *
 * @param ptr1 A pointer to the first value.
 * @param type The type of the value.
 * @param ptr2 A pointer to the second value.
 * @return CORTO_EQ, CORTO_LT, CORTO_GT when ptr1 is equal, larger or greater than ptr2.
 */
CORTO_EXPORT
corto_equalityKind _corto_ptr_compare(
    const void *ptr1,
    corto_type type,
    const void *ptr2);

/** Initialize a value.
 * This function is not needed when a value is allocated with corto_ptr_new. A
 * valid example usecase for corto_ptr_init is when allocating a buffer for a 
 * sequence, and the new elements need to be initialized.
 *
 * @param ptr A pointer to the value.
 * @param type The type of the value.
 * @return 0 if success, -1 if failed.
 * @see corto_ptr_deinit corto_ptr_new corto_ptr_free
 */
CORTO_EXPORT
int16_t _corto_ptr_init(
    void *ptr,
    corto_type type);

/** Deinitialize a value.
 * This function is not needed when a value is allocated with corto_ptr_new. A
 * valid example usecase for corto_ptr_init is when deallocating a buffer for a 
 * sequence, and the elements need to be deinitialized.
 *
 * @param ptr A pointer to the value.
 * @param type The type of the value.
 * @return 0 if success, -1 if failed.
 * @see corto_ptr_init corto_ptr_new corto_ptr_free
 */
CORTO_EXPORT
int16_t _corto_ptr_deinit(
    void *ptr,
    corto_type type);

/* Set a reference value.
 * This function will increase the refcount of the specified object, assign the
 * object to the value, and decrease the refcount of the old object, in that order.
 * Both value (not ptr!) and object can be null.
 *
 * @param ptr A pointer to the value.
 * @param object The object reference to assign to the value.
 */
CORTO_EXPORT
void corto_ptr_setref(
    void* ptr,
    corto_object object);

/* Set a string value.
 * This function will duplicate the the specified string, assign the
 * string to the value, and deallocate the old string, in that order.
 * Both value (not ptr!) and object can be null.
 *
 * @param ptr A pointer to the value.
 * @param str The string to assign to the value.
 */
CORTO_EXPORT
void corto_ptr_setstr(
    char **ptr,
    char *str);

#define corto_ptr_cast(fromType, from, toType, to) _corto_ptr_cast(corto_type(fromType), from, corto_type(toType), to)
#define corto_ptr_str(p, type, maxLength) _corto_ptr_str(p, corto_type(type), maxLength)
#define corto_ptr_fromStr(out, type, string) _corto_ptr_fromStr(out, corto_type(type), string)
#define corto_ptr_contentof(p, type, maxLength) _corto_ptr_contentof(p, corto_type(type), maxLength)
#define corto_ptr_copy(p, type, src) _corto_ptr_copy(p, corto_type(type), src)
#define corto_ptr_compare(p1, type, p2) _corto_ptr_compare(p1, corto_type(type), p2)
#define corto_ptr_init(p, type) _corto_ptr_init(p, corto_type(type))
#define corto_ptr_deinit(p, type) _corto_ptr_deinit(p, corto_type(type))
#define corto_ptr_new(type) _corto_ptr_new(corto_type(type))
#define corto_ptr_free(ptr, type) _corto_ptr_free(ptr, corto_type(type))
#define corto_ptr_size(p, type, size) _corto_ptr_size(p, corto_type(type), size)
#define corto_ptr_count(p, type) _corto_ptr_count(p, corto_type(type))

#ifdef __cplusplus
}
#endif

#endif /* CORTO_PTR_H_ */
