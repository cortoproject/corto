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
 * @section File utility functions.
 * @brief Functions that make commonly used file-based operations easier.
 */

#ifndef CORTO_FILE_H
#define CORTO_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

/** Load contents of text file in memory.
 * 
 * @param file The file to load.
 * @return A string that contains the file contents. Must be deallocated with free.
 */
CORTO_EXPORT 
char* corto_file_load(
    const char* file);

/** Test if a file exists.
 * 
 * @param filefmt A printf-style format specifier that describes the file to test.
 * @return true if file exists, otherwise false.
 */
CORTO_EXPORT
bool corto_file_test(
    const char* filefmt, 
    ...);

/** Calculate the size of a file.
 * 
 * @param file The file for which to calculate the size.
 * @return The size of the file.
 */
CORTO_EXPORT 
unsigned int corto_file_size(
    FILE* file);

/** Read from file until newline or eof character is encountered.
 * 
 * @param file The file to read.
 * @param buf The buffer to write to.
 * @param length The size of the buffer.
 * @return The buffer pointer if success.
 */
CORTO_EXPORT 
char* corto_file_readln(
    FILE* file, 
    char* buf, 
    unsigned int length);

/** Get extension from a file.
 * 
 * @param file The file to read.
 * @param buf The buffer in which to store the extension.
 * @return The buffer pointer if success.
 */
CORTO_EXPORT 
char* corto_file_extension(
    char* file, 
    char* buf);

/** Get path from a filename.
 * 
 * @param file The path to a file.
 * @param buf The buffer in which to store the path.
 * @return The buffer pointer if success.
 */
CORTO_EXPORT 
char* corto_file_path(
    char* file, 
    char* buf);

/** Get filename without extension.
 * 
 * @param file The path to a file.
 * @param buf The buffer in which to store the base filename.
 * @return The buffer pointer if success.
 */
CORTO_EXPORT 
char* corto_file_base(
    char* file, 
    char* buf);

#ifdef __cplusplus
}
#endif

#endif