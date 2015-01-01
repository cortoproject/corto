/** 
 * This file is fully generated. Do not modify!
 */

#include "Fast__meta.h"

/* $header() */
#include "Fast.h"
#include "db_util.h"
#include "db_loader.h"
#include "db_file.h"
#include "db_mm.h"

db_threadKey FAST_PARSER_KEY;

/* Run a cortex file */
int fast_cortexRun(db_string file, void* udata) {
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
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'Fast' scope */
int cortexmain(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    
    /* $begin(cortexmain) */
    /* Obtain thread local storage key for parser */
    if (db_threadTlsKey(&FAST_PARSER_KEY, NULL)) {
        return -1;
    }

    /* Register cortex extension */
    db_loaderRegister("cx", fast_cortexRun, NULL);
    /* $end */

    return Fast_load();
}

