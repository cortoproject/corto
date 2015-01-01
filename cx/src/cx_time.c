/*
 * cx_misc.c
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */
#include "time.h"
#include "cx_time.h"
#include "math.h"
#include "limits.h"
#include "errno.h"
#include "string.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx__type.h"

/* Sleep */
void cx_sleep(unsigned int sec, unsigned int nanosec) {
    struct timespec sleepTime;

    sleepTime.tv_sec = sec;
    sleepTime.tv_nsec = nanosec;
    if (nanosleep(&sleepTime, NULL)) {
        cx_error("nanosleep failed: %s", strerror(errno));
    }
}

void cx_timeGet(cx_time* time) {

    clock_gettime(CLOCK_REALTIME, (struct timespec*)time);
}

cx_time cx_timeAdd(cx_time t1, cx_time t2) {
    cx_time result;

    result.tv_nsec = t1.tv_nsec + t2.tv_nsec;
    result.tv_sec = t1.tv_sec + t2.tv_sec;
    if (result.tv_nsec > 1000000000) {
        result.tv_sec++;
        result.tv_nsec = result.tv_nsec - 1000000000;
    }

    return result;
}

cx_time cx_timeSub(cx_time t1, cx_time t2) {
    cx_time result;

    if (t1.tv_nsec >= t2.tv_nsec) {
        result.tv_nsec = t1.tv_nsec - t2.tv_nsec;
        result.tv_sec = t1.tv_sec - t2.tv_sec;
    } else {
        result.tv_nsec = t1.tv_nsec - t2.tv_nsec + 1000000000;
        result.tv_sec = t1.tv_sec - t2.tv_sec - 1;
    }

    return result;
}

double cx_timeToDouble(cx_time t) {
    double result;

    result = t.tv_sec;
    result += (double)t.tv_nsec / (double)1000000000;

    return result;
}

int cx_timeCompare(cx_time t1, cx_time t2) {
    int result;

    if (t1.tv_sec < t2.tv_sec) {
        result = -1;
    } else if (t1.tv_sec > t2.tv_sec) {
        result = 1;
    } else if (t1.tv_nsec < t2.tv_nsec) {
        result = -1;
    } else if (t1.tv_nsec > t2.tv_nsec) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

static char* g_num = "0123456789";
static int nmax = 1;

char* cx_itoa(int num, char* buff) {
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

char* cx_utoa(unsigned int num, char* buff) {
    CX_UNUSED(num);
    CX_UNUSED(buff);
    return NULL;
}

char* cx_ftoa(float num, char* buff) {
    CX_UNUSED(num);
    CX_UNUSED(buff);
    return NULL;
}
