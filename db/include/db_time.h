/*
 * db_misc.h
 *
 *  Created on: 23 aug. 2010
 *      Author: Sander
 */

#ifndef CORE_TIME_H_
#define CORE_TIME_H_

typedef struct db_time {
	int tv_sec;
	int tv_nsec;
}db_time;

void db_sleep(unsigned int sec, unsigned int nanosec);

void db_timeGet(db_time* time);

db_time db_timeAdd (db_time t1, db_time t2);

db_time db_timeSub (db_time t1, db_time t2);

int db_timeCompare (db_time t1, db_time t2);

double db_timeToDouble(db_time t);

/* Do not belong here */
char* db_itoa (int num, char* buff);
char* db_utoa (unsigned int num, char* buff);
char* db_ftoa (float num, char* buff);

#endif /* CORE_TIME_H_ */
