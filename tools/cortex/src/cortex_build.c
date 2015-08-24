
#include "cortex_build.h"

cx_int16 cortex_build(int argc, char *argv[]) {
	CX_UNUSED(argc);
	CX_UNUSED(argv);

	system ("rake silent=true");

	return 0;
}
