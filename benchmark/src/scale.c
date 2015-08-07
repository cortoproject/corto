
#include "cortex.h"
#define NUM_OBJECTS (1000 * 100)

int cortexmain(int argc, char *argv[]) {
	cx_object o = NULL;
	cx_uint32 i = 0;
	cx_time start, stop;

	cx_object parent = cx_declareChild(NULL, "parent", cx_void_o);

	cx_timeGet(&start);
	for (i = 0; i < NUM_OBJECTS; i++) {
		cx_id id;
		sprintf(id, "%d", i);
		if (!(i % 200000)) {
			printf("declare %d\n", i);
		}
		o = cx_declareChild(parent, id, cx_uint32_o);
		*(cx_uint32*)o = i;
		cx_define(o);
	}
	cx_timeGet(&stop);
	stop = cx_timeSub(stop, start);
	printf("declared %d objects in %d.%.09u seconds.\n", NUM_OBJECTS, stop.tv_sec, stop.tv_nsec);

	cx_timeGet(&start);
	for(i = 0; i < NUM_OBJECTS; i++) {
		cx_id id;
		sprintf(id, "%d", i);
		o = cx_resolve(parent, id);
		if (!o) {
			printf("%s not found\n", id);
		} else {
			cx_release(o);
		}
		if (!(i % 200000)) {
			printf("resolved %d\n", i);
		}
	}
	cx_timeGet(&stop);
	stop = cx_timeSub(stop, start);
	printf("resolved %d objects in %d.%.09u seconds.\n", NUM_OBJECTS, stop.tv_sec, stop.tv_nsec);

	cx_timeGet(&start);
	for(i = 0; i < NUM_OBJECTS * 100; i++) {
		cx_update(parent);
	}
	cx_timeGet(&stop);
	stop = cx_timeSub(stop, start);
	printf("updated object %d times in %d.%.09u seconds.\n", NUM_OBJECTS * 100, stop.tv_sec, stop.tv_nsec);

	cx_delete(parent);

	return 0;
}
