
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "db_files.h"

int db_mkdir(char *name) {
	int result = 0;
	struct stat st = {0};

	if (stat(name, &st) == -1) {
	    if (mkdir(name, 0700)) {
	    	goto error;
	    }
	}

	return result;
error:
	return -1;
}
