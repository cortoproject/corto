
#include <fnmatch.h>

#include "corto.h"
#include "corto_arg.h"
#include "stdlib.h"
#include "string.h"

typedef struct corto_arg {
    char* arg;
    corto_argCallback callback;
    unsigned int min;
    unsigned int max;
    corto_ll exclusive;
    corto_ll depend;
}corto_arg;

static corto_ll corto_argList = 0;

/* Add argument to configuration */
static corto_arg* corto_argListAdd(char* arg, corto_argCallback callback, int min, int max) {
    corto_arg* result;

    if (!corto_argList) {
        corto_argList = corto_llNew();
    }

    result = malloc(sizeof(corto_arg));

    result->arg = arg;
    result->callback = callback;
    result->min = min;
    result->max = max;
    result->exclusive = 0;
    result->depend = 0;

    corto_llInsert(corto_argList, result);

    return result;
}

/* Lookup argument walk-function */
typedef struct corto_argListFindWalk_t {
    char* arg;
    corto_arg* result;
}corto_argListFindWalk_t;
static int corto_argListFindWalk(corto_arg* arg, corto_argListFindWalk_t* udata) {
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
static corto_arg* corto_argListFind(char* arg) {
    corto_arg* result;
    corto_argListFindWalk_t walkData;

    if (corto_argList) {
        walkData.arg = arg;
        walkData.result = 0;
        corto_llWalk(corto_argList, (corto_walkAction)corto_argListFindWalk, &walkData);
        result = walkData.result;
    } else {
        result = 0;
    }

    return result;
}

/* Execute argument */
static int corto_argExec(char* arg_str, int argc, char* argv[]) {
    corto_arg* arg;

    int result = 0;

    /* Lookup argument */
    arg = corto_argListFind(arg_str);
    if (arg) {
        /* Call callback for argument */
        result = arg->callback(arg_str, argc, argv);
    } else {
        /* Warning - do not abort processing */
        if (arg_str) {
            corto_warning("Unknown argument '%s'.", arg_str);
        } else {
            corto_warning("Redundant argument '%s'", arg_str);
        }
    }

    return result;
}

/* Set argument */
int corto_argSet(char* arg, corto_argCallback callback, int min, int max) {
    int result;

    result = 0;

    /* Set argument if it not already exists. */
    if (!corto_argListFind(arg)) {
        corto_argListAdd(arg, callback, min, max);
    } else {
        corto_error("corto_argSet: argument '%s' already set.", arg);
        result = -1;
    }

    return result;
}

/* Exclusive relationship */
int corto_argExclusive(char* arg1_str, char* arg2_str) {
    corto_arg* arg1;
    corto_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = corto_argListFind(arg1_str);
    arg2 = corto_argListFind(arg2_str);

    /* Add arguments to each-other as exclusive */
    if (arg1 && arg2) {
        if (!arg1->exclusive) arg1->exclusive = corto_llNew();
        if (!arg2->exclusive) arg2->exclusive = corto_llNew();

        corto_llInsert(arg1->exclusive, arg2_str);
        corto_llInsert(arg2->exclusive, arg1_str);
    } else {
        if (!arg1_str) {
            corto_error("corto_argExclusive: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            corto_error("corto_argExclusive: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Depend relation */
int corto_argDepend(char* arg1_str, char* arg2_str) {
    corto_arg* arg1;
    corto_arg* arg2;
    int result;

    result = 0;

    /* Find arguments */
    arg1 = corto_argListFind(arg1_str);
    arg2 = corto_argListFind(arg2_str);

    /* Add argument2 as dependency to argument 1 */
    if (arg1 && arg2) {
        if (!arg1->depend) arg1->depend = corto_llNew();

        corto_llInsert(arg1->depend, arg2_str);
    } else {
        if (!arg1_str) {
            corto_error("corto_argDepend: argument '%s' is not configured.", arg1_str);
        }
        if (!arg2_str) {
            corto_error("corto_argDepend: argument '%s' is not configured.", arg2_str);
        }
        result = -1;
    }

    return result;
}

/* Count argument occurrence walk routine  */
typedef struct corto_argCountWalk_t {
    int count;
    char* arg;
}corto_argCountWalk_t;
static void corto_argCountWalk(char* arg, corto_argCountWalk_t* userData) {
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
static int corto_argCount(char* arg, corto_ll parsed) {
    corto_argCountWalk_t walkData;

    walkData.count = 0;
    walkData.arg = arg;
    corto_llWalk(parsed, (corto_walkAction)corto_argCountWalk, &walkData);

    return walkData.count;
}

/* Argument-dependency walk */
static int corto_argDependencyWalk(char* arg, corto_ll parsed) {
    if (!corto_argCount(arg, parsed)) {
        corto_error("corto_argDependencyWalk : missing argument '%s'.");
        return 0;
    }
    return 1;
}

/* Argument-exclusive walk */
static int corto_argExclusiveWalk(char* arg, corto_ll parsed) {
    if (corto_argCount(arg, parsed)) {
        corto_error("corto_argDependencyWalk : invalid argument '%s'.");
        return 0;
    }
    return 1;
}

/* Walkroutine for validation of argument */
static int corto_argValidateWalk(corto_arg* arg, corto_ll parsed) {
    char* arg_str;
    unsigned int occurred;
    int result;

    arg_str = arg->arg;
    result = 1;

    occurred = corto_argCount(arg_str, parsed);

    if ((arg->min <= occurred) && (occurred <= arg->max)) {
        /* Check dependencies */
        if (occurred) {
            if (arg->depend) {
                if (!corto_llWalk(arg->depend, (corto_walkAction)corto_argDependencyWalk, parsed)) {
                    corto_error("corto_argValidateWalk: not all dependencies are resolved for argument '%s'.", arg_str);
                    result = 0;
                }
            }
            if (arg->exclusive) {
                if (!corto_llWalk(arg->exclusive, (corto_walkAction)corto_argExclusiveWalk, parsed)) {
                    corto_error("corto_argValidateWalk: invalid combination of arguments encountered while parsing '%s'.", arg_str);
                    result = 0;
                }
            }
        }
    } else {
        if (occurred < arg->min) {
            corto_error("corto_argValidateWalk: too few occurrences(%d) of argument '%s' (min = %d).", occurred, arg_str, arg->min);
            result = 0;
        } else {
            corto_error("corto_argValidateWalk: too many occurrences(%d) of argument '%s' (max = %d).", occurred, arg_str, arg->max);
            result = 0;
        }
    }

    return result;
}

/* Validate commandline arguments */
static int corto_argValidate(corto_ll parsed) {
    return !corto_llWalk(corto_argList, (corto_walkAction)corto_argValidateWalk, parsed);
}

static int corto_releaseParsedWalk(char* arg, void* udata) {
    CORTO_UNUSED(udata);
    free(arg);
    return 1;
}

/* Parse arguments */
int corto_argParse(int argc, char* argv[]) {
    int result;
    int i;
    corto_ll parsed;
    char* arg;
    char argBuff[2]; /* For -x style arguments */
    int next;

    result = 0;
    i=1;
    argBuff[1] = '\0';

    /* Keep track of parsed arguments */
    parsed = corto_llNew();

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
                    next = corto_argExec(arg, argc-i, &argv[i]);
                    if (next >= 0) {
                        i += next + 1;

                        /* Add argument to parsed list */
                        corto_llInsert(parsed, strdup(arg));

                    } else {
                        result = -1;
                        break;
                    }
                } else {
                    /* Execute argument without '-' or '--' */
                    if (corto_argExec(0, argc-i, &argv[i]) > 0) {
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
        result = corto_argValidate(parsed);
    }
    if (!result) {
        /*corto_argUsage(argv[0]);*/
    }

    /* Free parsed */
    corto_llWalk(parsed, (corto_walkAction)corto_releaseParsedWalk, NULL);
    corto_llFree(parsed);

    return result;
}

int corto_argClearArg(void* o, void* udata) {
    corto_arg* arg;

    CORTO_UNUSED(udata);

    arg = o;
    if (arg->depend) {
        corto_llFree(arg->depend);
    }
    if (arg->exclusive) {
        corto_llFree(arg->exclusive);
    }
    corto_dealloc(arg);
    return 1;
}

void corto_argClear(void) {
    corto_llWalk(corto_argList, corto_argClearArg, NULL);
    corto_llFree(corto_argList);
    corto_argList = NULL;
}

static void corto_arginit(corto_argdata *data) {
    corto_argdata *pattern = NULL;
    corto_int32 p = 0;

    while (data[p].pattern) {
        pattern = &data[p];
        if (pattern->match) {
            *(pattern->match) = NULL;
        }
        if (pattern->args) {
            *(pattern->args) = NULL;
        }
        p++;
    }
}

corto_argdata* corto_argparse(char *argv[], corto_argdata *data) {
    char *arg;
    corto_int32 a = 0;

    corto_arginit(data);

    while ((arg = argv[a])) {
        corto_int32 p = 0;
        corto_bool match = FALSE;
        corto_argdata *pattern = NULL, *tentative = NULL;
        corto_int32 count = 0;

        /* Skip empty arguments */
        if (!strlen(argv[a])) {
            a++;
            continue;
        }

        /* Match argument against patterns */
        while (!match && data[p].pattern) {
            pattern = &data[p];
            if (pattern->pattern[0] == '$') {
                corto_int32 matchCount = pattern->match ?
                    *pattern->match ? corto_llSize(*pattern->match) : 0 : 0;
                corto_int32 argCount = pattern->args ?
                    *pattern->args ? corto_llSize(*pattern->args) : 0 : 0;

                if (pattern->pattern[1] == '|') {
                    count += argCount + matchCount;
                } else {
                    count = argCount + matchCount;
                }

                /* Match AT MOST once */
                if (pattern->pattern[1] == '?') {
                    if (!count && !fnmatch(pattern->pattern + 2, arg, 0)) {
                        tentative = pattern;
                        /* Optionals will match when all other constraints
                         * are satisfied */
                    }

                /* Match AT LEAST once */
                } else if ((pattern->pattern[1] == '+') || (pattern->pattern[1] == '|')) {
                    if (!fnmatch(pattern->pattern + 2, arg, 0)) {
                        if (count && tentative)  {
                            /* Push back one element to optional pattern */
                            if (matchCount && pattern->match && *pattern->match) {
                                corto_string arg = corto_llTakeFirst(*pattern->match);
                                *tentative->match = corto_llNew();
                                corto_llAppend(*tentative->match, arg);
                            }
                            if (argCount && pattern->args && *pattern->args) {
                                corto_string arg = corto_llTakeFirst(*pattern->args);
                                *tentative->args = corto_llNew();
                                corto_llAppend(*tentative->args, arg);
                            }
                            tentative = NULL;
                            match = TRUE;
                        } else {
                            match = TRUE;
                        }
                    }

                /* Match an argument on a fixed position */
                } else {
                    int num = atoi(&pattern->pattern[1]);
                    if (num == a) {
                        match = TRUE;
                    }
                }
            } else {
                if (!fnmatch(pattern->pattern, arg, 0)) {
                    match = TRUE;
                }
            }
            p++;
        }

        if (match) {
            if (pattern->match) {
                 if(!*(pattern->match)) {
                    *(pattern->match) = corto_llNew();
                }
                corto_llAppend(*(pattern->match), arg);
            }

            if (pattern->args) {
                if (argv[a + 1]) {
                    if (!*pattern->args) {
                        *(pattern->args) = corto_llNew();
                    }
                    a++;
                    corto_llAppend(*(pattern->args), argv[a]);
                } else {
                    corto_seterr("missing argument for option %s", arg);
                    goto error;
                }
            }
        } else {
            corto_seterr("unknown option '%s'", arg);
            goto error;
        }
        a++;
    }

    return data;
error:
    return NULL;
}

static corto_bool corto_argcleanDeleted(
  corto_ll list,
  corto_ll *deleted,
  corto_int32 count)
{
    corto_int32 i;

    for (i = 0; i < count; i ++) {
        if (deleted[i] == list) {
            return TRUE;
        }
    }

    return FALSE;
}

void corto_argclean(corto_argdata *data) {
    corto_argdata *pattern = NULL;
    corto_int32 p = 0;
    corto_ll deleted[CORTO_ARG_MAX * 2];
    corto_uint32 count = 0;

    while (data[p].pattern) {
        pattern = &data[p];
        if (pattern->match && *pattern->match) {
            if (!corto_argcleanDeleted(*pattern->match, deleted, count)) {
                corto_llFree(*pattern->match);
                deleted[count ++] = *pattern->match;
            }
        }
        if (pattern->args && *pattern->args) {
            if (!corto_argcleanDeleted(*pattern->args, deleted, count)) {
                corto_llFree(*pattern->args);
                deleted[count ++] = *pattern->args;
            }
        }
        p++;
    }
}
