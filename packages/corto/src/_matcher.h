
#ifndef CORTO__MATCHER_H_
#define CORTO__MATCHER_H_

#include <corto/corto.h>

typedef enum corto_matchProgramToken {
    CORTO_MATCHER_TOKEN_NONE,
    CORTO_MATCHER_TOKEN_THIS,
    CORTO_MATCHER_TOKEN_PARENT,
    CORTO_MATCHER_TOKEN_IDENTIFIER,
    CORTO_MATCHER_TOKEN_FILTER,
    CORTO_MATCHER_TOKEN_AND,
    CORTO_MATCHER_TOKEN_OR,
    CORTO_MATCHER_TOKEN_NOT,
    CORTO_MATCHER_TOKEN_SCOPE,
    CORTO_MATCHER_TOKEN_TREE,
    CORTO_MATCHER_TOKEN_SEPARATOR
} corto_matchProgramToken;

typedef struct corto_matchProgramOp {
    corto_matchProgramToken token;
    char *start;
    corto_bool containsWildcard;
} corto_matchProgramOp;

struct corto_matchProgram_s {
    corto_matchProgramOp ops[CORTO_MATCHER_MAX_OP];
    corto_uint8 size;
    corto_string tokens;
};

corto_int16 corto_matchProgramParseIntern(
    corto_matchProgram data,
    corto_string expr,
    corto_bool allowScopes,
    corto_bool allowSeparators);

#endif
