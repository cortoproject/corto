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

#include <corto>

static 
corto_time from_timespec(
    struct timespec *t)
{
    corto_time r = {
        .sec = t->tv_sec,
        .nanosec = t->tv_nsec
    };
    return r;
}

static 
struct timespec to_timespec(
    corto_time *t)
{
    struct timespec r = {
        .tv_sec = t->sec,
        .tv_nsec = t->nanosec
    };
    return r;
}

void corto_time_get(
    corto_time* time)
{
    struct timespec t;
    timespec_gettime(&t);
    *time = from_timespec(&t);
}

corto_time corto_time_add(
    corto_time t1, 
    corto_time t2)
{
    struct timespec r = timespec_add(
        to_timespec(&t1),
        to_timespec(&t2)
    );
    return from_timespec(&r);
}

corto_time corto_time_sub(
    corto_time t1, 
    corto_time t2)
{
    struct timespec r = timespec_sub(
        to_timespec(&t1),
        to_timespec(&t2)
    );
    return from_timespec(&r);
}

int corto_time_compare(
    corto_time t1, 
    corto_time t2)
{
    return  timespec_compare(
        to_timespec(&t1),
        to_timespec(&t2)
    );
}

double corto_time_toDouble(
    corto_time t)
{
    return timespec_toDouble(
        to_timespec(&t)
    );
}
