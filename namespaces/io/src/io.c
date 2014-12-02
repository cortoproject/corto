/* io.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"
#include "io__meta.h"

/* $header() */
#include "io__meta.h"

int hyvemain(int argc, char* argv[]) {
	DB_UNUSED(argc);
	DB_UNUSED(argv);

	io_load();

	return 0;
}
/* $end */

/* ::hyve::io::print(::hyve::lang::string str) */
db_void io_print(db_string str) {
/* $begin(::hyve::io::print) */
    printf("%s", str);
/* $end */
}

/* ::hyve::io::println(::hyve::lang::string str) */
db_void io_println(db_string str) {
/* $begin(::hyve::io::println) */
    printf("%s\n", str);
/* $end */
}

/* ::hyve::io::readln() */
db_string io_readln(void) {
/* $begin(::hyve::io::readln) */
    size_t size=256;
    int read;
    db_string result = db_malloc(size+1);

    if ((read = getline(&result, &size, stdin)) == -1) {
        db_error("io::readln: read error\n");
        goto error;
    }
    
    /* Remove newline character */
    result[strlen(result)-1]='\0';
    
    return result;
error:
    db_dealloc(result);
    return NULL;
/* $end */
}
