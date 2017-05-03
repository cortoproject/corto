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

#ifndef CORTO_BUILD_H
#define CORTO_BUILD_H

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 cortotool_rakefile(int argc, char *argv[]);
corto_int16 cortotool_build(int argc, char *argv[]);
corto_int16 cortotool_rebuild(int argc, char *argv[]);
corto_int16 cortotool_clean(int argc, char *argv[]);
corto_int16 cortotool_coverage(int argc, char *argv[]);
void cortotool_buildHelp(void);
void cortotool_rebuildHelp(void);
void cortotool_cleanHelp(void);

#ifdef __cplusplus
}
#endif
#endif
