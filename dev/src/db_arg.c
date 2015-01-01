/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2011 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#include "cortex.h"
#include "db_arg.h"

#include "stdlib.h"
#include "string.h"

typedef struct db_arg {
    char* arg;
    db_argCallback callback;
    unsigned int min;
    unsigned int max;
    db_ll exclusive;
    db_ll depend;
}db_arg;

static db_ll db_argList = 0;

/* Add argument to configuration */
static db_arg* db_argListAdd(char* arg, db_argCallback callback, int min, int max) {
    db_arg* result;

    if (!db_argList) {
        db_argList = db_llNew();
    }

    result = malloc(sizeof(db_arg));

    result->arg = arg;
    result->callback = callback;
    result->min = min;
    result->max = max;
    result->exclusive = 0;
    result->depend = 0;

    db_llInsert(db_argList, result);

    return result;
}

/* Lookup argument walk-function */
typedef struct db_argListFindWalk_t {
    char* arg;
    db_arg* result;
}db_argListFindWalk_t;
static int db_argListFindWalk(db_arg* arg, db_argListFindWalk_t* udata) {
    int found;

    found = 0;

    if (udata->arg) {
        if (arg->arg) {
            if (!strcmp(arg->arg, udata->arg)) {
                udata->result = arg;
                found = 1;
            }
        }
    } else {
        if (!arg->arg) {
            udata->result = arg;
            found = 1;
        }
    }

    return !found;
}

/* Lookup argument */
static db_arg* db_argListFind(char* arg) {
    db_arg* result;
    db_argListFindWalk_t walkData;

    if (db_argList) {
        walkData.arg = arg;
        walkData.result = 0;
        db_llWalk(db_argList, (db_walkAction)db_argListFindWalk, &walkData);
        result = walkData.result;
    } else {
        result = 0;
    }

    return result;
}

/* Execute argument */
static int db_argExec(char* arg_str, int argc, char* argv[]) {
    db_arg* arg;

    int result = 0;

    /* Lookup argument */
    arg = db_argListFind(arg_str);
    if (arg) {
        /* Call callback for argument */
        result = arg->callback(arg_str, argc, argv);
    } else {
        /* Warning - do not abort processing */
        if (arg_str) {
            db_warning("Unknown argument '%s'.", arg_str);
        } else {
            db_warning("Redundant argument '%s'", arg_str);
        }
    }

    return result;
}

/* Set argument */
int db_argSet(char* arg, db_argCallback callback, int min, int max) {
    int result;

    result = 0;

    /* Set argument if it not already exists. */
    if (!db_argListFind(arg)) {
        db_argListAdd(arg, callback, min, max);
    } else {
        db_error("db_argSet: argument '%s' already set.", arg);
        result = -1;
    }

    return result;
}

/* Exclusive relationship */
int db_argExclusive(char* arg1_str, char* arg2_str) {
    db_arg* arg1;
    db_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = db_argListFind(arg1_str);
    arg2 = db_argListFind(arg2_str);

    /* Add arguments to each-other as exclusive */
    if (arg1 && arg2) {
        if (!arg1->exclusive) arg1->exclusive = db_llNew();
        if (!arg2->exclusive) arg2->exclusive = db_llNew();

        db_llInsert(arg1->exclusive, arg2_str);
        db_llInsert(arg2->exclusive, arg1_str);
    } else {
        if (!arg1_str) {
            db_error("db_argExclusive: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            db_error("db_argExclusive: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Depend relation */
int db_argDepend(char* arg1_str, char* arg2_str) {
    db_arg* arg1;
    db_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = db_argListFind(arg1_str);
    arg2 = db_argListFind(arg2_str);

    /* Add argument2 as dependency to argument 1 */
    if (arg1 && arg2) {
        if (!arg1->depend) arg1->depend = db_llNew();

        db_llInsert(arg1->depend, arg2_str);
    } else {
        if (!arg1_str) {
            db_error("db_argDepend: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            db_error("db_argDepend: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Count argument occurrence walk routine  */
typedef struct db_argCountWalk_t {
    int count;
    char* arg;
}db_argCountWalk_t;
static void db_argCountWalk(char* arg, db_argCountWalk_t* userData) {
    if (arg) {
    	if (userData->arg && !strcmp(arg, userData->arg)) {
    		userData->count++;
    	}
    } else {
    	if (!userData->arg) {
    		userData->count++;
    	}
    }
}

/* Count how many times an argumend is specified. */
static int db_argCount(char* arg, db_ll parsed) {
    db_argCountWalk_t walkData;

    walkData.count = 0;
    walkData.arg = arg;
    db_llWalk(parsed, (db_walkAction)db_argCountWalk, &walkData);

    return walkData.count;
}

/* Argument-dependency walk */
static int db_argDependencyWalk(char* arg, db_ll parsed) {
    if (!db_argCount(arg, parsed)) {
        db_error("db_argDependencyWalk : missing argument '%s'.");
        return 0;
    }
    return 1;
}

/* Argument-exclusive walk */
static int db_argExclusiveWalk(char* arg, db_ll parsed) {
    if (db_argCount(arg, parsed)) {
        db_error("db_argDependencyWalk : invalid argument '%s'.");
        return 0;
    }
    return 1;
}

/* Walkroutine for validation of argument */
static int db_argValidateWalk(db_arg* arg, db_ll parsed) {
    char* arg_str;
    unsigned int occurred;
    int result;

    arg_str = arg->arg;
    result = 1;

    occurred = db_argCount(arg_str, parsed);

    if ((arg->min <= occurred) && (occurred <= arg->max)) {
        /* Check dependencies */
        if (occurred) {
        	if (arg->depend) {
				if (!db_llWalk(arg->depend, (db_walkAction)db_argDependencyWalk, parsed)) {
					db_error("db_argValidateWalk: not all dependencies are resolved for argument '%s'.", arg_str);
					result = 0;
				}
        	}
        	if (arg->exclusive) {
				if (!db_llWalk(arg->exclusive, (db_walkAction)db_argExclusiveWalk, parsed)) {
					db_error("db_argValidateWalk: invalid combination of arguments encountered while parsing '%s'.", arg_str);
					result = 0;
				}
        	}
        }
    } else {
        if (occurred < arg->min) {
            db_error("db_argValidateWalk: too few occurrences(%d) of argument '%s' (min = %d).", occurred, arg_str, arg->min);
            result = 0;
        } else {
            db_error("db_argValidateWalk: too many occurrences(%d) of argument '%s' (max = %d).", occurred, arg_str, arg->max);
            result = 0;
        }
    }

    return result;
}

/* Validate commandline arguments */
static int db_argValidate(db_ll parsed) {
    return !db_llWalk(db_argList, (db_walkAction)db_argValidateWalk, parsed);
}

static int db_freeParsedWalk(char* arg, void* udata) {
	DB_UNUSED(udata);
    free(arg);
    return 1;
}

/* Parse arguments */
int db_argParse(int argc, char* argv[]) {
    int result;
    int i;
    db_ll parsed;
    char* arg;
    char argBuff[2]; /* For -x style arguments */
    int next;

    result = 0;
    i=1;
    argBuff[1] = '\0';

    /* Keep track of parsed arguments */
    parsed = db_llNew();

    if (argc != 1) {

		/* Parse arguments */
		while(i<argc) {
			arg = argv[i];

			if (arg) {
				if (*arg == '-') {
					arg++;
					if (*arg == '-') {
						arg++;
					} else {
						argBuff[0] = *arg;
						arg = argBuff;
					}

					/* Execute argument */
					next = db_argExec(arg, argc-i, &argv[i]);
					if (next > 0) {
						i += next + 1;

						/* Add argument to parsed list */
						db_llInsert(parsed, strdup(arg));

					} else {
						result = -1;
						break;
					}
				} else {
					/* Execute argument without '-' or '--' */
					if (db_argExec(0, argc-i, &argv[i]) > 0) {
						i++;
					} else {
						result = -1;
						break;
					}
				}
			}
		}
    }

    /* Validate rules */
    if (!result) {
        result = db_argValidate(parsed);
    }
    if (!result) {
    	/*db_argUsage(argv[0]);*/
    }

    /* Free parsed */
    db_llWalk(parsed, (db_walkAction)db_freeParsedWalk, NULL);
    db_llFree(parsed);

    return result;
}

int db_argClearArg(void* o, void* udata) {
	db_arg* arg;

	DB_UNUSED(udata);

	arg = o;
	if (arg->depend) {
		db_llFree(arg->depend);
	}
	if (arg->exclusive) {
		db_llFree(arg->exclusive);
	}
	db_dealloc(arg);
	return 1;
}

void db_argClear(void) {
	db_llWalk(db_argList, db_argClearArg, NULL);
	db_llFree(db_argList);
	db_argList = NULL;
}




