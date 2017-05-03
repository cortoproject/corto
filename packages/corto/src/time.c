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

#include "corto/corto.h"

/* Sleep */
void corto_sleep(unsigned int sec, unsigned int nanosec) {
    struct timespec sleepTime;

    sleepTime.tv_sec = sec;
    sleepTime.tv_nsec = nanosec;
    if (nanosleep(&sleepTime, NULL)) {
        corto_error("nanosleep failed: %s", strerror(errno));
    }
}

void corto_timeGet(corto_time* time) {
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    time->sec = mts.tv_sec;
    time->nanosec = mts.tv_nsec;
#else
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    time->sec = t.tv_sec;
    time->nanosec = t.tv_nsec;
#endif
}

corto_time corto_timeAdd(corto_time t1, corto_time t2) {
    corto_time result;

    result.nanosec = t1.nanosec + t2.nanosec;
    result.sec = t1.sec + t2.sec;
    if (result.nanosec > 1000000000) {
        result.sec++;
        result.nanosec = result.nanosec - 1000000000;
    }

    return result;
}

corto_time corto_timeSub(corto_time t1, corto_time t2) {
    corto_time result;

    if (t1.nanosec >= t2.nanosec) {
        result.nanosec = t1.nanosec - t2.nanosec;
        result.sec = t1.sec - t2.sec;
    } else {
        result.nanosec = t1.nanosec - t2.nanosec + 1000000000;
        result.sec = t1.sec - t2.sec - 1;
    }

    return result;
}

double corto_timeToDouble(corto_time t) {
    double result;

    result = t.sec;
    result += (double)t.nanosec / (double)1000000000;

    return result;
}

int corto_time_compare(corto_time t1, corto_time t2) {
    int result;

    if (t1.sec < t2.sec) {
        result = -1;
    } else if (t1.sec > t2.sec) {
        result = 1;
    } else if (t1.nanosec < t2.nanosec) {
        result = -1;
    } else if (t1.nanosec > t2.nanosec) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

static char* g_num = "0123456789";
static int nmax = 1;

char* corto_itoa(int num, char* buff) {
    char* buffptr;
    unsigned int ch;
    unsigned int ntest;
    int i;
    int ignoreNull;

    if (nmax == 1) {
        i = log10(INT_MAX);
        for (; i>=1; i--) {
            nmax *= 10;
        }
    }

    ntest = nmax;
    buffptr = buff;
    ignoreNull = TRUE;

    if (!num) {
        *buffptr = '0';
        buffptr++;
    } else {
        if (num < 0) {
            *buffptr = '-';
            buffptr++;
            num *= -1;
        }

        while (ntest) {
            ch = num / ntest;
            if (ch) ignoreNull = FALSE;

            if (!ignoreNull) {
                *buffptr = g_num[ch];
                buffptr++;
            }

            num -= ch * ntest;
            ntest /= 10;
        }
    }

    *buffptr = '\0';

    return buffptr;
}

char* corto_utoa(unsigned int num, char* buff) {
    CORTO_UNUSED(num);
    CORTO_UNUSED(buff);
    return NULL;
}

char* corto_ftoa(float num, char* buff) {
    CORTO_UNUSED(num);
    CORTO_UNUSED(buff);
    return NULL;
}
