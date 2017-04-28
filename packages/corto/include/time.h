/*
 * corto_misc.h
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */

#ifndef CORE_TIME_H_
#define CORE_TIME_H_

CORTO_EXPORT void corto_sleep(unsigned int sec, unsigned int nanosec);
CORTO_EXPORT void corto_timeGet(corto_time* time);
CORTO_EXPORT corto_time corto_timeAdd(corto_time t1, corto_time t2);
CORTO_EXPORT corto_time corto_timeSub(corto_time t1, corto_time t2);
CORTO_EXPORT int corto_time_compare(corto_time t1, corto_time t2);
CORTO_EXPORT double corto_timeToDouble(corto_time t);

/* Do not belong here */
CORTO_EXPORT char* corto_itoa (int num, char* buff);
CORTO_EXPORT char* corto_utoa (unsigned int num, char* buff);
CORTO_EXPORT char* corto_ftoa (float num, char* buff);

#endif /* CORE_TIME_H_ */
