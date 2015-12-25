/*
 * corto_misc.c
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */
#include "corto/corto.h"

#include "time.h"
#include <sys/time.h>
#include "math.h"
#include "limits.h"
#include "errno.h"
#include "string.h"

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

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
    time->tv_sec = mts.tv_sec;
    time->tv_nsec = mts.tv_nsec;
#else
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    time->tv_sec = t.tv_sec;
    time->tv_nsec = t.tv_nsec;
#endif
}

corto_time corto_timeAdd(corto_time t1, corto_time t2) {
    corto_time result;

    result.tv_nsec = t1.tv_nsec + t2.tv_nsec;
    result.tv_sec = t1.tv_sec + t2.tv_sec;
    if (result.tv_nsec > 1000000000) {
        result.tv_sec++;
        result.tv_nsec = result.tv_nsec - 1000000000;
    }

    return result;
}

corto_time corto_timeSub(corto_time t1, corto_time t2) {
    corto_time result;

    if (t1.tv_nsec >= t2.tv_nsec) {
        result.tv_nsec = t1.tv_nsec - t2.tv_nsec;
        result.tv_sec = t1.tv_sec - t2.tv_sec;
    } else {
        result.tv_nsec = t1.tv_nsec - t2.tv_nsec + 1000000000;
        result.tv_sec = t1.tv_sec - t2.tv_sec - 1;
    }

    return result;
}

double corto_timeToDouble(corto_time t) {
    double result;

    result = t.tv_sec;
    result += (double)t.tv_nsec / (double)1000000000;

    return result;
}

int corto_timeCompare(corto_time t1, corto_time t2) {
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
