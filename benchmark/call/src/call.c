/* call.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "call.h"
#include "call__meta.h"


/* $begin($header) */
#include "db_time.h"

#define CALL_SAMPLES (100000000)

/* Store functions in pointers to avoid inlining */
static void (*fp_noargCall)(void);
static db_word (*fp_wordCall)(db_word w1, db_word w2, db_word w3, db_word w4);
static db_float64 (*fp_floatCall)(db_word w1, db_word w2, db_word w3, db_word w4);
static call_Point (*fp_complexCall)(db_word w1, db_word w2, db_word w3, db_word w4);

void benchmark_noargCall(void) {
    db_time start, stop;
    db_uint32 i;

    fp_noargCall = call_noargCall;

    /* Test direct */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        fp_noargCall();
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("noarg direct: \t%f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));

    /* Test indirect */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        db_call(call_noargCall_o, NULL);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("noarg indirect: %f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));
}

void benchmark_wordCall(void) {
    db_time start, stop;
    db_uint32 i;
    db_word result;

    fp_wordCall = call_wordCall;

    /* Test direct */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        fp_wordCall(1,2,3,4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("word direct: \t%f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));

    /* Test indirect */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        db_call(call_wordCall_o, &result, 1, 2, 3, 4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("word indirect: \t%f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));
}

void benchmark_floatCall(void) {
    db_time start, stop;
    db_uint32 i;
    db_float64 result;

    fp_floatCall = call_floatCall;

    /* Test direct */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        fp_floatCall(1,2,3,4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("float direct: \t%f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));

    /* Test indirect */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        db_call(call_floatCall_o, &result, 1, 2, 3, 4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("float indirect: %f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));
}

void benchmark_complexCall(void) {
    db_time start, stop;
    db_uint32 i;
    call_Point result;

    fp_complexCall = call_complexCall;

    /* Test direct */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        fp_complexCall(1,2,3,4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("complex direct: %f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));

    /* Test indirect */
    db_timeGet(&start);
    for(i=0; i<CALL_SAMPLES; i++) {
        db_call(call_complexCall_o, &result, 1, 2, 3, 4);
    }
    db_timeGet(&stop);
    stop = db_timeSub(stop, start);
    printf("complex indirect: %f us\n", db_timeToDouble(stop) * ((db_float64)1000000/(db_float64)CALL_SAMPLES));
}


int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    db_start();
    call_load();
    benchmark_noargCall();
    benchmark_wordCall();
    benchmark_floatCall();
    benchmark_complexCall();
    db_stop();
    return 0;
}
/* $end */

/* ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
call_Point call_complexCall(db_word w1, db_word w2, db_word w3, db_word w4) {
/* $begin(::call::complexCall) */
    call_Point result;
    result.x = w1 * w2;
    result.y = w3 * w4;
    return result;
/* $end */
}

/* ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
db_float64 call_floatCall(db_word w1, db_word w2, db_word w3, db_word w4) {
/* $begin(::call::floatCall) */
    return w1 * w2 * w3 * w4;
/* $end */
}

/* ::call::noargCall() */
db_void call_noargCall(void) {
/* $begin(::call::noargCall) */

    /* << Insert implementation >> */

/* $end */
}

/* ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
db_word call_wordCall(db_word w1, db_word w2, db_word w3, db_word w4) {
/* $begin(::call::wordCall) */
    return w1 * w2 * w3 * w4;
/* $end */
}
