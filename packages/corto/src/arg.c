
#include "corto/corto.h"

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

            /* If arguments are required and there are none, there's no match */
            if ((argv[a + 1] && argv[a + 1][0] != '-') || !pattern->args) {

                /* '$' Indicates constraint */
                if (pattern->pattern[0] == '$') {
                    corto_int32 matchCount = pattern->match ?
                        *pattern->match ? corto_llSize(*pattern->match) : 0 : 0;
                    corto_int32 argCount = pattern->args ?
                        *pattern->args ? corto_llSize(*pattern->args) : 0 : 0;

                    /* | can be used with + or ? to indicate an OR relationship
                     * between multiple AT LEAST/AT MOST once patterns */
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
                            if (count && tentative && !fnmatch(tentative->pattern + 2, arg, 0))  {
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
                                tentative = NULL;
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
            }
            p++;
        }

        if (tentative && !fnmatch(tentative->pattern + 2, arg, 0)) {
            pattern = tentative;
            match = TRUE;
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
