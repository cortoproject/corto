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
 * @section Loading shared libraries at runtime.
 * @brief Functions for loading libraries and procedures at runtime.
 */

#ifndef CORTO_DL_H
#define CORTO_DL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_dl_s* corto_dl;

/** Load dynamic library.
 *
 * @param name Name of library.
 * @return Handle to dynamic library.
 */
CORTO_EXPORT 
corto_dl corto_dl_open(
    const char* file);

/** Close dynamic library.
 *
 * @param dl Handle to dynamic library.
 */
CORTO_EXPORT 
void corto_dl_close(
    corto_dl dl);

/** Resolve symbol in dynamic library.
 *
 * @param dl Handle to dynamic library.
 * @param sym Name of symbol to resolve.
 * @return Handle to dynamic library.
 */
CORTO_EXPORT 
void* corto_dl_sym(
    corto_dl dl, 
    const char* sym);

/** Resolve procedure in dynamic library.
 * This function is equivalent to corto_dl_sym, but has a more convenient
 * return type for resolving procedures.
 *
 * @param dl Handle to dynamic library.
 * @param proc Name of procedure to resolve.
 * @return Handle to dynamic library.
 */
CORTO_EXPORT 
void*(*corto_dl_proc(
    corto_dl dl, 
    const char* proc))(void);

/** Return last reported error when loading dynamic library.
 * Only call this function after one of the corto_dl_* functions has failed.
 *
 * @return Internal buffer containing the last reported error.
 */
CORTO_EXPORT 
const char* corto_dl_error(void);

#ifdef __cplusplus
}
#endif

#endif
