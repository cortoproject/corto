/*
 * cx_misc.h
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */

#ifndef CORE_TIME_H_
#define CORE_TIME_H_

typedef struct cx_time {
    int tv_sec;
    int tv_nsec;
} cx_time;

void cx_sleep(unsigned int sec, unsigned int nanosec);

void cx_timeGet(cx_time* time);

cx_time cx_timeAdd(cx_time t1, cx_time t2);

cx_time cx_timeSub(cx_time t1, cx_time t2);

int cx_timeCompare(cx_time t1, cx_time t2);

double cx_timeToDouble(cx_time t);

/* Do not belong here */
char* cx_itoa (int num, char* buff);
char* cx_utoa (unsigned int num, char* buff);
char* cx_ftoa (float num, char* buff);

#endif /* CORE_TIME_H_ */
