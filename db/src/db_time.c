/*
 * db_misc.c
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */
#include "time.h"
#include "db_time.h"
#include "math.h"
#include "limits.h"
#include "errno.h"
#include "string.h"
#include "db_err.h"
#include "db_util.h"
#include "db__type.h"

/* Sleep */
void db_sleep(unsigned int sec, unsigned int nanosec) {
	struct timespec sleepTime;

	sleepTime.tv_sec = sec;
	sleepTime.tv_nsec = nanosec;
	if (nanosleep(&sleepTime, NULL)) {
		db_error("nanosleep failed: %s", strerror(errno));
	}
}

void db_timeGet(db_time* time) {

	clock_gettime(CLOCK_REALTIME, (struct timespec*)time);
}

db_time db_timeAdd(db_time t1, db_time t2) {
	db_time result;

	result.tv_nsec = t1.tv_nsec + t2.tv_nsec;
	result.tv_sec = t1.tv_sec + t2.tv_sec;
	if (result.tv_nsec > 1000000000) {
		result.tv_sec++;
		result.tv_nsec = result.tv_nsec - 1000000000;
	}

	return result;
}

db_time db_timeSub(db_time t1, db_time t2) {
	db_time result;

	if (t1.tv_nsec >= t2.tv_nsec) {
		result.tv_nsec = t1.tv_nsec - t2.tv_nsec;
		result.tv_sec = t1.tv_sec - t2.tv_sec;
	} else {
		result.tv_nsec = t1.tv_nsec - t2.tv_nsec + 1000000000;
		result.tv_sec = t1.tv_sec - t2.tv_sec - 1;
	}

	return result;
}

double db_timeToDouble(db_time t) {
	double result;

	result = t.tv_sec;
	result += (double)t.tv_nsec / (double)1000000000;

	return result;
}

int db_timeCompare(db_time t1, db_time t2) {
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

char* db_itoa(int num, char* buff) {
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

char* db_utoa(unsigned int num, char* buff) {
	DB_UNUSED(num);
	DB_UNUSED(buff);
	return NULL;
}

char* db_ftoa(float num, char* buff) {
	DB_UNUSED(num);
	DB_UNUSED(buff);
	return NULL;
}
