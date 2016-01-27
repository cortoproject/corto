/*
 * corto_misc.h
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */

#ifndef CORE_TIME_H_
#define CORE_TIME_H_

void corto_sleep(unsigned int sec, unsigned int nanosec);

void corto_timeGet(corto_time* time);

corto_time corto_timeAdd(corto_time t1, corto_time t2);

corto_time corto_timeSub(corto_time t1, corto_time t2);

int corto_time_compare(corto_time t1, corto_time t2);

double corto_timeToDouble(corto_time t);

/* Do not belong here */
char* corto_itoa (int num, char* buff);
char* corto_utoa (unsigned int num, char* buff);
char* corto_ftoa (float num, char* buff);

#endif /* CORE_TIME_H_ */
