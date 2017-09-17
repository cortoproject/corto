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
 * @section Time functions.
 * @brief Functions for doing basic operations/calculations on timespec values.
 */

#ifndef CORTO_TIME_H
#define CORTO_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

/** Sleep for specified amount of time.
 * 
 * @param sec Seconds to sleep
 * @param nanoseconds to sleep
 */
CORTO_EXPORT 
void corto_sleep(
    unsigned int sec, 
    unsigned int nanosec);

/** Get current time.
 * 
 * @param time Variable that will contain the time.
 */
CORTO_EXPORT 
void timespec_gettime(
    struct timespec* time);

/** Add two time values.
 * 
 * @param t1 Time value.
 * @param t2 Time value.
 * @result Result of adding t1 and t2
 */
CORTO_EXPORT 
struct timespec timespec_add(
    struct timespec t1, 
    struct timespec t2);

/** Subtract two time values.
 * 
 * @param t1 Time value to subtract from.
 * @param t2 Time value to subtract.
 * @result Result of subtracting t1 and t2
 */
CORTO_EXPORT 
struct timespec timespec_sub(
    struct timespec t1, 
    struct timespec t2);

/** Compare two time values.
 * 
 * @param t1 Time value.
 * @param t2 Time value.
 * @result 0 if equal, -1 if t2 is less than t1, 1 if t1 is larger than t2
 */
CORTO_EXPORT 
int timespec_compare(
    struct timespec t1, 
    struct timespec t2);

/** Convert time to double-precision floating point value.
 *
 * @param t Time value.
 * @result Floating point representation of the time.
 */
CORTO_EXPORT 
double timespec_toDouble(
    struct timespec t);

#ifdef __cplusplus
}
#endif

#endif
