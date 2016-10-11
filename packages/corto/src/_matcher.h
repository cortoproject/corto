
#ifndef CORTO__MATCHER_H_
#define CORTO__MATCHER_H_

#include <corto/corto.h>

typedef enum corto_matcherToken {
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
} corto_matcherToken;

typedef struct corto_matcherOp {
    corto_matcherToken token;
    char *start;
    corto_bool containsWildcard;
} corto_matcherOp;

struct corto_matcher_s {
    corto_matcherOp ops[CORTO_MATCHER_MAX_OP];
    corto_uint8 size;
    corto_string tokens;
};

corto_int16 corto_matcherParseIntern(
    corto_matcher data,
    corto_string expr,
    corto_bool allowScopes,
    corto_bool allowSeparators);

#endif
