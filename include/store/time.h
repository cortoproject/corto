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

#ifndef CORTO_TIME_H_
#define CORTO_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Get current time.
 * 
 * @param time Variable that will contain the time.
 */
CORTO_EXPORT 
void corto_time_get(
    corto_time* time);

/** Add two time values.
 * 
 * @param t1 Time value.
 * @param t2 Time value.
 * @result Result of adding t1 and t2
 */
CORTO_EXPORT 
corto_time corto_time_add(
    corto_time t1, 
    corto_time t2);

/** Subtract two time values.
 * 
 * @param t1 Time value to subtract from.
 * @param t2 Time value to subtract.
 * @result Result of subtracting t1 and t2
 */
CORTO_EXPORT 
corto_time corto_time_sub(
    corto_time t1, 
    corto_time t2);

/** Compare two time values.
 * 
 * @param t1 Time value.
 * @param t2 Time value.
 * @result 0 if equal, -1 if t2 is less than t1, 1 if t1 is larger than t2
 */
CORTO_EXPORT 
int corto_time_compare(
    corto_time t1, 
    corto_time t2);

/** Convert time to double-precision floating point value.
 *
 * @param t Time value.
 * @result Floating point representation of the time.
 */
CORTO_EXPORT 
double corto_time_toDouble(
    corto_time t);

#ifdef __cplusplus
}
#endif

#endif

