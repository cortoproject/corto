
#define corto_lang_LIB
#include "corto.h"
#include "cx_arg.h"

#include "stdlib.h"
#include "string.h"

typedef struct cx_arg {
    char* arg;
    cx_argCallback callback;
    unsigned int min;
    unsigned int max;
    cx_ll exclusive;
    cx_ll depend;
}cx_arg;

static cx_ll cx_argList = 0;

/* Add argument to configuration */
static cx_arg* cx_argListAdd(char* arg, cx_argCallback callback, int min, int max) {
    cx_arg* result;

    if (!cx_argList) {
        cx_argList = cx_llNew();
    }

    result = malloc(sizeof(cx_arg));

    result->arg = arg;
    result->callback = callback;
    result->min = min;
    result->max = max;
    result->exclusive = 0;
    result->depend = 0;

    cx_llInsert(cx_argList, result);

    return result;
}

/* Lookup argument walk-function */
typedef struct cx_argListFindWalk_t {
    char* arg;
    cx_arg* result;
}cx_argListFindWalk_t;
static int cx_argListFindWalk(cx_arg* arg, cx_argListFindWalk_t* udata) {
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
static cx_arg* cx_argListFind(char* arg) {
    cx_arg* result;
    cx_argListFindWalk_t walkData;

    if (cx_argList) {
        walkData.arg = arg;
        walkData.result = 0;
        cx_llWalk(cx_argList, (cx_walkAction)cx_argListFindWalk, &walkData);
        result = walkData.result;
    } else {
        result = 0;
    }

    return result;
}

/* Execute argument */
static int cx_argExec(char* arg_str, int argc, char* argv[]) {
    cx_arg* arg;

    int result = 0;

    /* Lookup argument */
    arg = cx_argListFind(arg_str);
    if (arg) {
        /* Call callback for argument */
        result = arg->callback(arg_str, argc, argv);
    } else {
        /* Warning - do not abort processing */
        if (arg_str) {
            cx_warning("Unknown argument '%s'.", arg_str);
        } else {
            cx_warning("Redundant argument '%s'", arg_str);
        }
    }

    return result;
}

/* Set argument */
int cx_argSet(char* arg, cx_argCallback callback, int min, int max) {
    int result;

    result = 0;

    /* Set argument if it not already exists. */
    if (!cx_argListFind(arg)) {
        cx_argListAdd(arg, callback, min, max);
    } else {
        cx_error("cx_argSet: argument '%s' already set.", arg);
        result = -1;
    }

    return result;
}

/* Exclusive relationship */
int cx_argExclusive(char* arg1_str, char* arg2_str) {
    cx_arg* arg1;
    cx_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = cx_argListFind(arg1_str);
    arg2 = cx_argListFind(arg2_str);

    /* Add arguments to each-other as exclusive */
    if (arg1 && arg2) {
        if (!arg1->exclusive) arg1->exclusive = cx_llNew();
        if (!arg2->exclusive) arg2->exclusive = cx_llNew();

        cx_llInsert(arg1->exclusive, arg2_str);
        cx_llInsert(arg2->exclusive, arg1_str);
    } else {
        if (!arg1_str) {
            cx_error("cx_argExclusive: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            cx_error("cx_argExclusive: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Depend relation */
int cx_argDepend(char* arg1_str, char* arg2_str) {
    cx_arg* arg1;
    cx_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = cx_argListFind(arg1_str);
    arg2 = cx_argListFind(arg2_str);

    /* Add argument2 as dependency to argument 1 */
    if (arg1 && arg2) {
        if (!arg1->depend) arg1->depend = cx_llNew();

        cx_llInsert(arg1->depend, arg2_str);
    } else {
        if (!arg1_str) {
            cx_error("cx_argDepend: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            cx_error("cx_argDepend: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Count argument occurrence walk routine  */
typedef struct cx_argCountWalk_t {
    int count;
    char* arg;
}cx_argCountWalk_t;
static void cx_argCountWalk(char* arg, cx_argCountWalk_t* userData) {
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
static int cx_argCount(char* arg, cx_ll parsed) {
    cx_argCountWalk_t walkData;

    walkData.count = 0;
    walkData.arg = arg;
    cx_llWalk(parsed, (cx_walkAction)cx_argCountWalk, &walkData);

    return walkData.count;
}

/* Argument-dependency walk */
static int cx_argDependencyWalk(char* arg, cx_ll parsed) {
    if (!cx_argCount(arg, parsed)) {
        cx_error("cx_argDependencyWalk : missing argument '%s'.");
        return 0;
    }
    return 1;
}

/* Argument-exclusive walk */
static int cx_argExclusiveWalk(char* arg, cx_ll parsed) {
    if (cx_argCount(arg, parsed)) {
        cx_error("cx_argDependencyWalk : invalid argument '%s'.");
        return 0;
    }
    return 1;
}

/* Walkroutine for validation of argument */
static int cx_argValidateWalk(cx_arg* arg, cx_ll parsed) {
    char* arg_str;
    unsigned int occurred;
    int result;

    arg_str = arg->arg;
    result = 1;

    occurred = cx_argCount(arg_str, parsed);

    if ((arg->min <= occurred) && (occurred <= arg->max)) {
        /* Check dependencies */
        if (occurred) {
            if (arg->depend) {
                if (!cx_llWalk(arg->depend, (cx_walkAction)cx_argDependencyWalk, parsed)) {
                    cx_error("cx_argValidateWalk: not all dependencies are resolved for argument '%s'.", arg_str);
                    result = 0;
                }
            }
            if (arg->exclusive) {
                if (!cx_llWalk(arg->exclusive, (cx_walkAction)cx_argExclusiveWalk, parsed)) {
                    cx_error("cx_argValidateWalk: invalid combination of arguments encountered while parsing '%s'.", arg_str);
                    result = 0;
                }
            }
        }
    } else {
        if (occurred < arg->min) {
            cx_error("cx_argValidateWalk: too few occurrences(%d) of argument '%s' (min = %d).", occurred, arg_str, arg->min);
            result = 0;
        } else {
            cx_error("cx_argValidateWalk: too many occurrences(%d) of argument '%s' (max = %d).", occurred, arg_str, arg->max);
            result = 0;
        }
    }

    return result;
}

/* Validate commandline arguments */
static int cx_argValidate(cx_ll parsed) {
    return !cx_llWalk(cx_argList, (cx_walkAction)cx_argValidateWalk, parsed);
}

static int cx_releaseParsedWalk(char* arg, void* udata) {
    CX_UNUSED(udata);
    free(arg);
    return 1;
}

/* Parse arguments */
int cx_argParse(int argc, char* argv[]) {
    int result;
    int i;
    cx_ll parsed;
    char* arg;
    char argBuff[2]; /* For -x style arguments */
    int next;

    result = 0;
    i=1;
    argBuff[1] = '\0';

    /* Keep track of parsed arguments */
    parsed = cx_llNew();

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
                    next = cx_argExec(arg, argc-i, &argv[i]);
                    if (next >= 0) {
                        i += next + 1;

                        /* Add argument to parsed list */
                        cx_llInsert(parsed, strdup(arg));

                    } else {
                        result = -1;
                        break;
                    }
                } else {
                    /* Execute argument without '-' or '--' */
                    if (cx_argExec(0, argc-i, &argv[i]) > 0) {
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
        result = cx_argValidate(parsed);
    }
    if (!result) {
        /*cx_argUsage(argv[0]);*/
    }

    /* Free parsed */
    cx_llWalk(parsed, (cx_walkAction)cx_releaseParsedWalk, NULL);
    cx_llFree(parsed);

    return result;
}

int cx_argClearArg(void* o, void* udata) {
    cx_arg* arg;

    CX_UNUSED(udata);

    arg = o;
    if (arg->depend) {
        cx_llFree(arg->depend);
    }
    if (arg->exclusive) {
        cx_llFree(arg->exclusive);
    }
    cx_dealloc(arg);
    return 1;
}

void cx_argClear(void) {
    cx_llWalk(cx_argList, cx_argClearArg, NULL);
    cx_llFree(cx_argList);
    cx_argList = NULL;
}




