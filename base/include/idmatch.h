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

 #ifndef CORTO_IDMATCH_H
 #define CORTO_IDMATCH_H

/** @file
 * @section idmatch Id matching API
 * @brief API for matching corto identifiers against a pattern
 */

typedef struct corto_idmatch_program_s* corto_idmatch_program;

/** Match an id against a pattern.
 * Simple function that tests if an object id matches the provided pattern.
 *
 * @param pattern The pattern against which to match the object identifier
 * @param id The object identifier to match
 * @return true if the identifier matches, false if it does not match
 * @see corto_idmatch_compile corto_idmatch_run corto_idmatch_free
 */
CORTO_EXPORT 
bool corto_idmatch(
    char *pattern, 
    char *id);

/** Compile an id expression.
 * When a pattern needs to be evaluated against multiple strings, it is faster
 * to compile it first with the corto_idmatch_compile function. Once compiled,
 * strings can be matched with the corto_idmatch_run function. When the program
 * is no longer necessary, it should be freed with corto_idmatch_free.
 *
 * @param pattern The pattern against which to match the object identifier
 * @pattern allowScopes Determines whether `/` and `//` are allowed in the pattern
 * @pattern allowSeparators Determines whether `,` is allowed in a pattern
 * @return A compiled version of the string pattern.
 * @see corto_idmatch_run corto_idmatch_free corto_idmatch
 */
CORTO_EXPORT 
corto_idmatch_program corto_idmatch_compile(
    char *pattern, 
    bool allowScopes, 
    bool allowSeparators);

/** Run a compiled idmatch program.
 *
 * @param program A compiled program, created by corto_idmatch_compile
 * @pattern id The object identifier to match
 * @return true if the identifier matches, false if it does not match
 * @see corto_idmatch corto_idmatch_compile corto_idmatch_free
 */
CORTO_EXPORT 
bool corto_idmatch_run(
    corto_idmatch_program program, 
    char *id);

/** Free a compiled program.
 * The corto_idmatch_run function evaluates an identifier against a compiled
 * pattern program. The compiled program can be reused multiple times for
 * different identifiers.
 *
 * @param program A compiled program, created by corto_idmatch_compile
 * @pattern id The object identifier to match
 * @return true if the identifier matches, false if it does not match
 * @see corto_idmatch corto_idmatch_compile corto_idmatch_free
 */
CORTO_EXPORT 
void corto_idmatch_free(
    corto_idmatch_program program);
    
/** Match parent of an object identifier.
 * The corto_idmatch_parent function matches a specified parent identifier with
 * an object identifier. If ther is a match, the functino returns the remainder.
 *
 * @param parent An object identifier representing a parent
 * @pattern expr An object identifier
 * @return the remainder if the parent matches, NULL if it does not match
 */    
CORTO_EXPORT
char* corto_matchParent(
    char *parent, 
    char *expr);

#endif
