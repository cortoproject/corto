/* pp_Pinger.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "pp_Pinger.h"
#include "PingPong__meta.h"


/* $begin($header) */
#include "hyve.h"

#define PP_MEASURE_ON_SAMPLE (10000)
#define PP_PRINT_ON_SAMPLE (10000000)

void pp_Pinger_updateStats(pp_Pinger _this) {
	db_time t, t_prev, t_min, t_max, t_cumm;

	/* Calculate roundtrip */
	db_timeGet(&t);
	t_prev.tv_sec = _this->lastPing.sec;
	t_prev.tv_nsec = _this->lastPing.nanosec;
	t_min.tv_sec = _this->minPing.sec;
	t_min.tv_nsec = _this->minPing.nanosec;
	t_max.tv_sec = _this->maxPing.sec;
	t_max.tv_nsec = _this->maxPing.nanosec;
	t_cumm.tv_sec = _this->cummPing.sec;
	t_cumm.tv_nsec = _this->cummPing.nanosec;

	_this->lastPing.sec = t.tv_sec;
	_this->lastPing.nanosec = t.tv_nsec;
	t = db_timeSub(t, t_prev);

	if (t_prev.tv_nsec) {
		if (!t_min.tv_nsec) {
			t_min.tv_sec = t.tv_sec;
			t_min.tv_nsec = t.tv_nsec;
		}

		if (db_timeCompare(t, t_max) > 0) {
			t_max.tv_sec = t.tv_sec;
			t_max.tv_nsec = t.tv_nsec;
		}

		if (db_timeCompare(t, t_min) < 0) {
			t_min.tv_sec = t.tv_sec;
			t_min.tv_nsec = t.tv_nsec;
		}

		t_cumm = db_timeAdd(t_cumm, t);

		_this->minPing.sec = t_min.tv_sec;
		_this->minPing.nanosec = t_min.tv_nsec;
		_this->maxPing.sec = t_max.tv_sec;
		_this->maxPing.nanosec = t_max.tv_nsec;
		_this->cummPing.sec = t_cumm.tv_sec;
		_this->cummPing.nanosec = t_cumm.tv_nsec;
	}
}
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Pinger::construct(::PingPong::Pinger object) */
db_int16 pp_Pinger_construct(pp_Pinger object) {
/* $begin(::PingPong::Pinger::construct) */
	db_observer onEvent;

	/* Lookup instantiated observer */
	onEvent = db_class_privateObserver(pp_Pinger_o, object, pp_Pinger_onEvent_o);
	if (onEvent) {
		db_observer_setDispatcher(onEvent,object->dispatcher);
	} else {
		goto error;
	}

	return 0;
error:
	return -1;
/* $end */
}

/* ::PingPong::Pinger::onEvent */
db_void pp_Pinger_onEvent(pp_Pinger _this, db_object *observable, db_object *source) {
/* $begin(::PingPong::Pinger::onEvent) */
	DB_UNUSED(observable);
	DB_UNUSED(source);

	if (_this->isPing) {
	    if (!(_this->samples % PP_MEASURE_ON_SAMPLE)) {
	        pp_Pinger_updateStats(_this);
	    }

	    if (!(_this->samples % (PP_PRINT_ON_SAMPLE * 10))) {
	        printf("\n\t avg\t\t min\t\t max\t\t frequency\n");
	    }
		if (_this->samples && !(_this->samples % PP_PRINT_ON_SAMPLE)) {
			db_time cumm,min,max;
			cumm.tv_sec = _this->cummPing.sec;
			cumm.tv_nsec = _this->cummPing.nanosec;
			min.tv_sec = _this->minPing.sec;
			min.tv_nsec = _this->minPing.nanosec;
			max.tv_sec = _this->maxPing.sec;
			max.tv_nsec = _this->maxPing.nanosec;

			printf("\t %f us\t %f us\t %f us\t %.2f Mhz\n",
					db_timeToDouble(cumm) / ((double)PP_PRINT_ON_SAMPLE / (double)1000000),
					db_timeToDouble(min) / ((double)PP_MEASURE_ON_SAMPLE / (double)1000000),
					db_timeToDouble(max) / ((double)PP_MEASURE_ON_SAMPLE / (double)1000000),
					(double)1 / (db_timeToDouble(cumm) / ((double)PP_PRINT_ON_SAMPLE / (double)1000000)));
			_this->maxPing.sec = 0;
			_this->maxPing.nanosec = 0;
			_this->minPing.sec = 0;
			_this->minPing.nanosec = 0;
			_this->cummPing.sec = 0;
			_this->cummPing.nanosec = 0;
		}
		_this->samples++;
		db_updateFrom(pp_pong_o, _this);
	} else {
		db_updateFrom(pp_ping_o, _this);
	}
/* $end */
}
