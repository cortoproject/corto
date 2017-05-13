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
 * @section walk Walk API
 * @brief API for dynamic walking of corto values.
 *
 * The walk API provides functionality to dynamically walk over a corto value
 * without requiring compile time knowledge of the values' type. The API allows
 * for the creation of generic components that can translate corto values to 
 * other representations, like JSON, XML or an SQL statement.
 *
 * The walk API accepts an instance of corto_walk_opt which contains two arrays
 * of callbacks. The first array is called `program`, and contains callback that
 * are invoked when values of a specific corto_typeKind (PRIMITIVE, COMPOSITE, 
 * COLLECTION, etc) are encountered. A member called `reference` contains a callback
 * that is invoked when an object reference value is encountered.
 *
 * The second array is called `metaprogram` and contains callbacks that are
 * invoked when walking over a certain kind of meta-structure, expressed by
 * corto_valueKind (OBJECT, MEMBER, ELEMENT, etc).
 *
 * The walk API is recursively implemented, which means that to visit deeper
 * levels of nesting, a walk method has to be invoked recursively. Scalar values
 * represent the leaf nodes of the values to visit. To visit all values, callbacks
 * in the `metaprogram` array must invoke `corto_value_walk` on the 'value' parameter
 * of the callback. In the `program` array, the following typeKinds must invoke
 * these functions respectively (if not specified, do not invoke anything):
 *
 * - CORTO_COMPOSITE: `corto_walk_members`
 * - CORTO_COLLECTION: `corto_walk_elements`
 *
 * When doing a metawalk, also invoke:
 *
 * - CORTO_PRIMITIVE: `corto_walk_constants` (for bitmask and enum types only)
 * - CORTO_COMPOSITE: `corto_walk_cases` (for unions only)
 *
 * In addition to callbacks, corto_walk_opt contains extra information to
 * instruct the walk routine which values to serialize. The access and accessKind
 * values determine which members the walk routine will visit. The `access` member
 * specifies a mask of member modifiers which will be matched against the member
 * modifiers (GLOBAL, LOCAL, PRIVATE, READONLY, etc). The `accessKind` member
 * specifies the function used to match the modifier:
 *
 * - CORTO_NOT: visit members without any of the modifiers specified by access.
 * - CORTO_OR: visit members with one or more modifiers specified by access.
 * - CORTO_XOR: visit members that exactly match modifiers specified by access.
 *
 * The corto_walk_opt type contains a `members` sequence that when populated, 
 * will restrict the visited members to those specified in the sequence.
 *
 * The `aliasAction` member specifies what to do when an alias member is 
 * encountered:
 * 
 * - CORTO_WALK_ALIAS_FOLLOW: follow alias members to the original member.
 * - CORTO_WALK_ALIAS_IGNORE: ignore alias members
 * - CORTO_WALK_ALIAS_PASSTHROUGH: visit alias members like ordinary members.
 *
 * The `optionalAction` member specifies what to do when an optional member is 
 * encountered:
 *
 * - CORTO_WALK_OPTIONAL_IF_SET: only visit optional values when set.
 * - CORTO_WALK_OPTIONAL_ALWAYS: always visit optional values.
 *
 * The `visitAllCases` member specifies whether the walk action should visit
 * all union cases or only the active union case (determined by the 
 * discriminator). When invoking corto_metawalk, this value is automatically set
 * to true.
 * 
 * A corto_walk_opt instance must always be initialized using the 
 * corto_walk_init function. By default all values of an object are visited.
 */

#ifndef CORTO_WALK_H_
#define CORTO_WALK_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Type that contains configuration parameters for walking object values */
typedef struct corto_walk_opt corto_walk_opt;

/* Callbacks used to walk object data */
typedef int16_t (*corto_walk_cb)(corto_walk_opt* _this, corto_value *v, void* userData);
typedef int16_t (*corto_walk_init_cb)(corto_walk_opt* _this, corto_value *v, void* userData);
typedef int16_t (*corto_walk_deinit_cb)(corto_walk_opt* _this, void* userData);

/* Enable / disable tracing when doing walk */
typedef enum corto_walk_traceKind {
    CORTO_WALK_TRACE_ALWAYS,
    CORTO_WALK_TRACE_ON_FAIL,
    CORTO_WALK_TRACE_NEVER
} corto_walk_traceKind;

/* How should walk treat alias members */
typedef enum corto_aliasActionKind {
    CORTO_WALK_ALIAS_FOLLOW,
    CORTO_WALK_ALIAS_IGNORE,
    CORTO_WALK_ALIAS_PASSTHROUGH
} corto_aliasActionKind;

/* How should walk treat optional members */
typedef enum corto_optionalActionKind {
    CORTO_WALK_OPTIONAL_IF_SET,
    CORTO_WALK_OPTIONAL_ALWAYS
} corto_optionalActionKind;

struct corto_walk_opt {
    bool initialized;
    bool constructed;

    corto_modifier access;
    corto_operatorKind accessKind;

    corto_aliasActionKind aliasAction;
    corto_optionalActionKind optionalAction;

    bool visitAllCases; 
    corto_objectseq members;

    corto_walk_traceKind traceKind;
    corto_walk_init_cb construct;
    corto_walk_deinit_cb destruct;

    corto_walk_cb program[CORTO_ITERATOR+1];
    corto_walk_cb metaprogram[CORTO_CONSTANT+1];
    corto_walk_cb reference;
};

/** Walk over a corto object.
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param object The object to be visited.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_value_walk corto_ptr_walk corto_metawalk
 */
CORTO_EXPORT int16_t corto_walk(corto_walk_opt* opt, corto_object o, void* userData);

/** Walk over a corto_value instance.
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param object The corto_value instance to be visited.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk corto_ptr_walk
 */
CORTO_EXPORT int16_t corto_value_walk(corto_walk_opt* opt, corto_value* value, void* userData);

/** Walk over a native pointer.
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param ptr The pointer to be visited.
 * @param type The type of the pointer.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk corto_value_walk
 */
CORTO_EXPORT int16_t corto_ptr_walk(corto_walk_opt* opt, void* ptr, corto_type type, void* userData);

/** Walk over the members of a composite type.
 * This function should only be called from the CORTO_COMPOSITE callback in the
 * program array of 'opt'.
 *
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param value The 'value' parameter passed to the CORTO_COMPOSITE callback.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk_elements
 */
CORTO_EXPORT int16_t corto_walk_members(corto_walk_opt* opt, corto_value* value, void* userData);

/** Walk over the elements of a collection type.
 * This function should only be called from the CORTO_COLLECTION callback in the
 * program array of 'opt'.
 *
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param value The 'value' parameter passed to the CORTO_COLLECTION callback.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk_elements
 */
CORTO_EXPORT int16_t corto_walk_elements(corto_walk_opt* opt, corto_value* value, void* userData);

/** Initialize a corto_walk_opt instance.
 * @param opt Pointer to corto_walk_opt struct.
 */
CORTO_EXPORT void corto_walk_init(corto_walk_opt* opt);

/** Deinitialize a corto_walk_opt instance.
 * @param opt Pointer to an initialized corto_walk_opt instance.
 */
CORTO_EXPORT int16_t corto_walk_deinit(corto_walk_opt* opt, void* userData);

/** Walk over a corto type.
 * This function creates a dummy object of the specified type, and then walks
 * over this dummy object. It ensures that every potential value of the type is
 * visited, which makes the function suitable for serializing types to type
 * representations of other technologies, such as a CREATE TABLE statement or an
 * XSD.
 *
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param type The type to visit.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk
 */
CORTO_EXPORT int16_t _corto_metawalk(corto_walk_opt* opt, corto_type type, void* userData);

/** Walk over the constants of a bitmask/enumeration type.
 * This function should only be called from the CORTO_PRIMITIVE callback in the
 * program array of 'opt', and only when serializing an instance of a bitmask or
 * enumeration type.
 * 
 * In addition, this function should only be invoked when doing a corto_metawalk.
 * Invoking this function in an ordinary corto_walk will result in undefined 
 * behavior.
 *
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param value The 'value' parameter passed to the CORTO_PRIMITIVE callback.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk_elements
 */
CORTO_EXPORT int16_t corto_walk_constants(corto_walk_opt* opt, corto_value *value, void* userData);

/** Walk over the cases of a union type.
 * This function should only be called from the CORTO_COMPOSITE callback in the
 * program array of 'opt', and only when serializing an instance of a union type.
 * 
 * In addition, this function should only be invoked when doing a corto_metawalk.
 * Invoking this function in an ordinary corto_walk will result in undefined 
 * behavior.
 *
 * @param opt Pointer to an initialized corto_walk_opt instance.
 * @param value The 'value' parameter passed to the CORTO_COMPOSITE callback.
 * @param userData A pointer that will be passed to the callbacks.  
 * @return 0 if success, non-zero if failed.
 * @see corto_walk_elements
 */
CORTO_EXPORT int16_t corto_walk_cases(corto_walk_opt* opt, corto_value *value, void *userData);

#define corto_metawalk(opt, t, d) _corto_metawalk(opt, corto_type(t), d)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_WALK_H_ */
