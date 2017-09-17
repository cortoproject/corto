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
 * @section Filesystem functions.
 * @brief Functions for doing basic operations on a filesystem.
 */

#ifndef CORTO_FS_H
#define CORTO_FS_H

#ifdef __cplusplus
extern "C" {
#endif

/** Create a directory.
 * The function creates any directories in the provided name that do not yet
 * exist, as if the Linux command "mkdir -p" is specified. If the directory
 * already exists, the function will not throw an error.
 *
 * @param fmt printf-style format string for building the directory name.
 * @return zero when success, non-zero when failed.
 */
CORTO_EXPORT 
int corto_mkdir(
    const char *fmt, 
    ...);

/** Read the contents of a directory.
 * Returns a list of strings that represents the files in a directory specified
 * by "name". To clean up the resources, use corto_closedir.
 *
 * @param name The name of the directory to open. 
 * @return Linked list that contains the files in the directory.
 */
CORTO_EXPORT 
corto_ll corto_opendir(
    const char *name);

/** Release resources from corto_opendir.
 * 
 * @param dir Linked list returned by corto_opendir.
 */
CORTO_EXPORT 
void corto_closedir(
    corto_ll dir);

/** Creates an empty file. 
 *
 * @param name Name of the file.
 * @return zero if success, non-zero if failed 
 */
CORTO_EXPORT 
int corto_touch(
    const char *name);

/* Get current working directory. 
 *
 * @return NULL if failed, an internal buffer set to current working directory otherwise 
 */
CORTO_EXPORT 
char* corto_cwd(void);

/** Change working directory.
 *
 * @return zero if success, non-zero if failed
 */
CORTO_EXPORT 
int corto_chdir(
    const char *name);

/** Copy a file. 
 * If the destination file did not yet exist, it will be created.
 *
 * @param source Source file.
 * @param destination Destination file.
 * @return zero if success, non-zero if failed 
 */
CORTO_EXPORT 
int corto_cp(
    const char *source, 
    const char *destination);

/** Test if name is a directory.
 *
 * @param name Name to test.
 * @return true if a directory, false if a regular file.
 */
CORTO_EXPORT 
bool corto_isdir(
    const char *name);

/** Rename a file or directory.
 *
 * @param oldName Current filename.
 * @param newName New filename.
 * @return 0 if success, non-zero if failed
 */
CORTO_EXPORT 
int corto_rename(
    const char *oldName, 
    const char *newName);

/** Remove a file or directory. 
 * This function will recursively remove subdirectories.
 *
 * @param name Name of file to remove.
 * @return 0 if success, non-zero if failed 
 */
CORTO_EXPORT 
int corto_rm(
    const char *name);

/** Recursively remove a directory 
 *
 * @param name Name of directory to remove.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT 
int corto_rmtree(
    const char *name);

#ifdef __cplusplus
}
#endif

#endif
