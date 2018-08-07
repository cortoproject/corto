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
  * @section reflection Reflection
  * @brief Access to metadata of in-memory objects.
  */

#ifndef CORTO_REFLECTION_H
#define CORTO_REFLECTION_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Get the type of an object.
 * @param o The object for which to obtain the type.
 * @return The object type.
 * @see corto_instanceof corto_type_instanceof
 */
CORTO_EXPORT
corto_type corto_typeof(
    corto_object o);

/** Obtain the current state mask of the object.
 * Object state changes as an object is declared, defined and ultimately deleted.
 *
 * @param o The object of which to obtain the state.
 * @return The state mask of the current object.
 * @see corto_check_state
 */
CORTO_EXPORT
corto_state corto_stateof(
    corto_object o);

/** Obtain the attribute mask of the object.
 * Object attributes are static after an object is declared.
 *
 * @param o The object of which to obtain the attributes.
 * @return The attribute mask of the current object.
 * @see corto_check_attr corto_get_attr corto_set_attr
 */
CORTO_EXPORT
corto_attr corto_attrof(
    corto_object o);

/** Check if an object is an orphan.
 * Orphans are objects that contain a reference to a parent object, but the
 * parent object does not have the object in its scope.
 *
 * @param o The object to check
 * @return true if the object is an orphan.
= */
CORTO_EXPORT
bool corto_isorphan(
    corto_object o);

/** Check if an object is a builtin object.
 * Builtin objects are part of the corto runtime and are not located on the heap.
 *
 * @param o The object to check
 * @return true if the object is builtin.
 */
CORTO_EXPORT
bool corto_isbuiltin(
    corto_object o);

/** Check if an object is a auto-resumed object.
 * Resumed objects are not created by the application through a corto_declare,
 * but have been automatically resumed by, for example, a lookup function.
 * Resumed objects may at any point become suspended again when there are no
 * more references to them. Because of this, automatically resumed objects do
 * not receive an initial refcount of 1 as is the case with regular named
 * objects.
 *
 * To ensure that memory is being properly released, corto keeps track of which
 * objects are automatically resumed. Only PERSISTENT objects can be resumed.
 *
 * @param o The object to check
 * @return true if the object is automatically resumed.
 */
CORTO_EXPORT
bool corto_isresumed(
    corto_object o);

/** The current reference count of the object.
 * This function should be used with caution, as it introduces dependencies on
 * the underlying garbage collection mechanism. A valid use for this function
 * would be in testcases, where it can be used to validate if an specific
 * operation did not introduce any leaks.
 *
 * @param o The object for which to obtain the reference count.
 * @return The reference count of the object.
 * @see corto_claim corto_release
 */
CORTO_EXPORT
int32_t corto_countof(
    corto_object o);

/** Get the object id.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * @param o A named object for which to obtain the id.
 * @return The object id. The returned string is not owned by the application.
 * @see corto_nameof
 */
CORTO_EXPORT
char *corto_idof(
    corto_object o);

/** Get the object name.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * The object name is the same as the object id, unless the 'nameof' function of
 * a type is overridden, in which case the result of that function is used.
 *
 * Object names are meant to provide a user friendly, though not necessarily
 * unique way to refer to an object.
 *
 * @param str An id buffer in which to store the name. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_nameof and
 * other functions that use the corto stringcache.
 * @param o A named object for which to obtain the name.
 * @return The object name. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof
 */
CORTO_EXPORT
char *corto_nameof(
    corto_id str,
    corto_object o);

/** Get the parent of an object.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * This function may return NULL if the corto root object is passed as argument. If
 * @param o The object for which to obtain the id.
 * @return The object id. The returned string is not owned by the application.
 * @see corto_childof
 */
CORTO_EXPORT
corto_object corto_parentof(
    corto_object o);

/** Returns the source for an object.
 * Only objects created with CORTO_ATTR_PERSISTENT can explicitly set a source. If
 * the object is not PERSISTENT and is an orphan the function will obtain the
 * source of the parent. In all other scenarios the function will return NULL.
 *
 * @param o A valid object.
 * @return The source of the object.
 * @see corto_owned corto_set_source corto_get_source
 */
CORTO_EXPORT
corto_object corto_sourceof(
    corto_object o);

/** Check if an object is of a specified state.
 * Object state changes as an object is declared, defined and ultimately deleted.
 *
 * @param o The object for which to check the state.
 * @param state The state to look for.
 * @return true if the object is in the specified state, otherwise false.
 * @see corto_stateof corto_set_state corto_get_state
 */
CORTO_EXPORT
bool corto_check_state(
    corto_object o,
    corto_state state);

/** Check if an object is of a specified attribute.
 * Object attributes are static after an object is declared.
 *
 * @param o The object for which to check the attribute.
 * @param state The attribute to look for.
 * @return true if the object has the specified attribute, otherwise false.
 * @see corto_attrof corto_get_attr corto_set_attr
 */
CORTO_EXPORT
bool corto_check_attr(
    corto_object o,
    corto_attr attr);

/** Check if object is an instance of a specified type.
 * This function returns true when types exactly match, when o is of a type that
 * is a subtype of type, when o is of a type that implements type, and when o is of
 * target{type}.
 *
 * @param type The type against which to check.
 * @param o The object to check.
 * @return true if o is an instance of type, otherwise false.
 * @see corto_typeof corto_type_instanceof
 */
CORTO_EXPORT
bool _corto_instanceof(
    corto_type type,
    corto_object o);

/** Check if objects of a type are an instance of another type.
 * @param type The type against which to check.
 * @param valueType The type to check.
 * @return true if objects of valueType are an instance of type, otherwise false.
 * @see corto_typeof corto_instanceof
 */
CORTO_EXPORT
bool _corto_type_instanceof(
    corto_type type,
    corto_type valueType);

/** Obtain a full path identifier to an object.
 * This function returns the shortest path that will lead to resolving the object
 * using a corto_resolve where the root is specified as scope.
 *
 * In practice this means that for objects in corto/lang it will only return the
 * object id (int32) while for all other objects the function will a forward slash ('/')
 * separated list of ids as obtained by corto_idof (/grandparent/parent/object).
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and
 * other functions that use the corto stringcache.
 *
 * @param o The object for which to obtain the id.
 * @return The full path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_fullpath(
    corto_id str,
    corto_object o);

/** Obtain a relative path identifier to an object.
 * This function returns the shortest path from the specified from object to the
 * to object, separated by sep. If to is a parent of from, this function will insert
 * the appropriate number of '..' operators. This function uses corto_idof to determine
 * the object ids.
 *
 * The result of this function can be used with corto_lookup to lookup the to object,
 * where from is specifed as scope and result as id.
 *
 * If NULL is specified for from, an initial forward slash will be added to the
 * resulting path. If root_o is specified for from, no initial slash will be added
 * to the resulting path.
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and
 * other functions that use the corto stringcache.
 *
 * @param from The object from the path should be offset.
 * @param o The object to which to generate the path.
 * @param sep The path separator.
 * @return The path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_path(
    corto_id str,
    corto_object from,
    corto_object to,
    const char* sep);

/** Check if object is a child of the specified parent.
 * The objects passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * @param p The parent object.
 * @param o The child object.
 * @return true if o is a child of p, otherwise false.
 * @see corto_parentof
 */
CORTO_EXPORT
bool corto_childof(
    corto_object p,
    corto_object o);

/** Check if object is owned by current thread.
 * Corto uses this function to check if a thread is allowed to change an object
 * through corto_update or corto_delete functions. The rules for sourceship are
 * as follows:
 *
 * 1. If the object source is NULL, the object is owned by the application. A SOURCE
 * mount will not be able to modify the object.
 * 2. If the object source is not NULL and not an instance of corto/vstore/mount, the
 * rule 1 applies. This mode can be used to emit notifications from a non-mount
 * instance without an observer for that instance receiving the notification.
 * 3. If the object source is an instance of corto/vstore/mount, the mount owns the
 * object. If the mount is a SINK, it shares sourceship with the application. If
 * the mount is a SOURCE, only that mount will be able to change the object.
 *
 * The source is determined as specified by corto_sourceof.
 *
 * @param o A valid object.
 * @return The source of the object.
 * @see corto_owned corto_set_source corto_get_source
 */
CORTO_EXPORT
bool corto_owned(
    corto_object o);


#ifdef __cplusplus
}
#endif

#endif
