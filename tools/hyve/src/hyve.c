/*
 * hyve.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_loader.h"

extern db_bool DB_DEBUG_ENABLED;

int main(int argc, char* argv[]) {
    int i;
    db_id filename;

    /* Start database */
    db_start();

    /* Pre-load hyve-ast parser */
    db_load("fast");

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (*argv[i] == '-') {
            if (*(argv[i]+1) == 'd') {
                DB_DEBUG_ENABLED = TRUE;
            }
        } else
    	if (!strstr(argv[i], ".hyve")) {
            sprintf(filename, "%s.hyve", argv[i]);
            if (db_load(filename)) {
            	db_error("failed to load file '%s'", argv[i]);
            }
    	} else {
    		if (db_load(argv[i])) {
    			db_error("failed to load file '%s'", argv[i]);
    		}
    	}
    }

    /* Stop database */
    db_stop();

    return 0;
}
