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

    /* Access & accessKind provide a filter for which members to walk over, using
     * member modifiers. For example, to exclude all private & readonly members, do:
     * access = CORTO_PRIVATE | CORTO_READONLY
     * accessKind = CORTO_NOT */
    corto_modifier access;
    corto_operatorKind accessKind;

    /* See description of corto_aliasActionKind and corto_optionalActionKind */
    corto_aliasActionKind aliasAction;
    corto_optionalActionKind optionalAction;
    
    /* If TRUE, serializer will visit all union cases. Useful when walking 
     * types instead of values. */
    bool visitAllCases; 

    /* When set, only serialize specified members */
    corto_objectseq members;

    /* See description of corto_walk_traceKind */
    corto_walk_traceKind traceKind;

    /* Callbacks to be invoked before and after the walk. This allows for 
     * cleanup of any resources the walk functions may use. */
    corto_walk_init_cb construct;
    corto_walk_deinit_cb destruct;

    /* Callbacks invoked for type kinds */
    corto_walk_cb program[CORTO_ITERATOR+1];

    /* Callbacks invoked for value kinds */
    corto_walk_cb metaprogram[CORTO_CONSTANT+1];

    /* Callback invoked for reference members */
    corto_walk_cb reference;
};

CORTO_EXPORT int16_t corto_walk(corto_walk_opt* _this, corto_object o, void* userData);
CORTO_EXPORT int16_t corto_value_walk(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_any_walk(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_walk_members(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT int16_t corto_walk_elements(corto_walk_opt* _this, corto_value* info, void* userData);
CORTO_EXPORT void corto_walk_init(corto_walk_opt* _this);
CORTO_EXPORT int16_t corto_walk_deinit(corto_walk_opt* _this, void* userData);

CORTO_EXPORT int16_t _corto_metawalk(corto_walk_opt* s, corto_type type, void* userData);
CORTO_EXPORT int16_t corto_walk_constants(corto_walk_opt* s, corto_value *v, void* userData);
CORTO_EXPORT int16_t corto_walk_cases(corto_walk_opt* s, corto_value *v, void *userData);

#define corto_metawalk(s, t, d) _corto_metawalk(s, corto_type(t), d)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_WALK_H_ */
