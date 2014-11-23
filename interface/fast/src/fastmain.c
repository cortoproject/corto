/*
 * fast.c
 *
 *  Created on: Mar 11, 2013
 *      Author: sander
 */

#include "hyve.h"
#include "db_util.h"
#include "db_loader.h"
#include "db_file.h"
#include "Fast__meta.h"
#include "Fast__api.h"
#include "Fast_Parser.h"
#include "db_mm.h"

db_threadKey FAST_PARSER_KEY;

/* Run a hyve file */
int fast_hyveRun(db_string file, void* udata) {
    db_char* source;
    Fast_Parser p;
    DB_UNUSED(udata);

    source = db_fileLoad(file);
    if (source) {
        /* Create parser */
        p = Fast_Parser__create(source, file);

        /* Set parser in local storage of thread (enables multithreaded parsers) */
        db_threadTlsSet(FAST_PARSER_KEY, p);

        /* Parse script */
        Fast_Parser_parse(p);
        db_free(p);
        db_dealloc(source);
    } else {
    	goto error;
    }

    return 0;
error:
	return -1;
}

int hyvemain(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);

    /* Load types */
    Fast_load();

    /* Obtain thread local storage key for parser */
    if (db_threadTlsKey(&FAST_PARSER_KEY, NULL)) {
        goto error;
    }

    /* Register hyve extension */
    db_loaderRegister("hyve", fast_hyveRun, NULL);

    return 0;
error:
    return -1;
}
