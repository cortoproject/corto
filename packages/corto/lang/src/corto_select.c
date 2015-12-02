
#include "corto.h"
#include "ctype.h"
#include "corto_string_ser.h"
#include "jsw_rbtree.h"
#include "fnmatch.h"
#include "corto__object.h"

extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_threadKey CORTO_KEY_SELECT;
#define CORTO_SELECT_MAX_OP (32)

typedef enum corto_selectToken {
    TOKEN_NONE,
    TOKEN_IDENTIFIER,
    TOKEN_SCOPE,
    TOKEN_TREE,
    TOKEN_THIS,
    TOKEN_PARENT,
    TOKEN_ASTERISK,
    TOKEN_WILDCARD,
} corto_selectToken;

typedef struct corto_selectOp {
    corto_selectToken token;
    char *start;
    corto_bool containsWildcard;
} corto_selectOp;

struct corto_selectData;

typedef struct corto_selectStack {
    corto_object o; /* Object of whose scope is being iterated */
    jsw_rbtrav_t trav; /* Persistent tree iterator */
    corto_iter iter;
    corto_string filter;

    /* Callback for either returning single object, traversing
     * scope or traversing a tree. */
    void (*next)(struct corto_selectData *data,
        struct corto_selectStack *frame);
} corto_selectStack;

typedef struct corto_selectData {
    corto_string expr;                           /* Full expression */
    corto_object scope;                          /* Scope passed to select */
    corto_selectOp program[CORTO_SELECT_MAX_OP]; /* Parsed program */
    corto_uint8 programSize;
    corto_selectStack stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    corto_uint8 sp;
    corto_resultIter replicators[CORTO_MAX_REPLICATORS];
    corto_int8 activeReplicators; /* Replicators with outstanding requests */
    corto_int8 currentReplicator; /* Current replicator being evaluated */

    /* Pre allocated for selectItem */
    corto_id parent;
    corto_id name;
    corto_id type;
    corto_result item;
    corto_result *next;
}corto_selectData;

static corto_selectData* corto_selectDataGet(void) {
    corto_selectData* result;

    result = corto_threadTlsGet(CORTO_KEY_SELECT);
    if (!result) {
        result = corto_calloc(sizeof(corto_selectData));
        result->item.parent = result->parent;
        result->item.name = result->name;
        result->item.type = result->type;

        corto_threadTlsSet(CORTO_KEY_SELECT, result);
    }

    return result;
}

static int corto_selectParse(corto_selectData *data) {
    char *ptr, *start, ch;
    int op = 0;

    ptr = data->expr;
    for (; (ch = *ptr); data->program[op].start = ptr, ptr++) {
        data->program[op].containsWildcard = FALSE;
        start = ptr;
        switch(ch) {
        case '.':
            if (ptr[1] == '.') {
                data->program[op].token = TOKEN_PARENT;
                *ptr = '\0';
                ptr++;
            } else {
                *ptr = '\0';
                data->program[op].token = TOKEN_THIS;
            }
            break;
        case '/':
            if (ptr[1] == '/') {
                data->program[op].token = TOKEN_TREE;
                *ptr = '\0';
                ptr++;
            } else {
                *ptr = '\0';
                data->program[op].token = TOKEN_SCOPE;
            }
            break;
        case ':':
            if (ptr[1] == ':') {
                data->program[op].token = TOKEN_SCOPE;
                *ptr = '\0';
                ptr++;
            } else {
                corto_seterr("invalid usage of ':'");
                goto error;
            }
            break;
        default:
            while((ch = *ptr++) &&
                  (isalnum(ch) || (ch == '_') || (ch == '*') || (ch == '?') ||
                    (ch == '(') || (ch == ')') || (ch == '{') || (ch == '}'))) {
                if ((ch == '*') || (ch == '?')) {
                    data->program[op].containsWildcard = TRUE;
                }
            }

            ptr--; /* Go back one character to adjust for lookahead of one */
            int len = ptr - start;
            if (len) {
                if (len == 1) {
                    if (*(ptr - 1) == '?') {
                        data->program[op].token = TOKEN_WILDCARD;
                    } else if (*(ptr - 1) == '*') {
                        data->program[op].token = TOKEN_ASTERISK;
                    } else {
                        data->program[op].token = TOKEN_IDENTIFIER;
                    }
                } else {
                    data->program[op].token = TOKEN_IDENTIFIER;
                }
            } else {
                corto_seterr("invalid character '%c'", ch);
                goto error;
            }
            ptr--;
            break;
        }

        data->program[op].start = start;
        if (++op == CORTO_SELECT_MAX_OP) {
            corto_seterr("expression contains too many tokens");
            goto error;
        }
    }

    /* If program ends with scope or tree, auto-append asterisk */
    if (op) {
        switch(data->program[op - 1].token) {
        case TOKEN_SCOPE:
        case TOKEN_TREE:
            data->program[op].token = TOKEN_ASTERISK;
            if (++op == CORTO_SELECT_MAX_OP) {
                corto_seterr("expression contains too many tokens");
                goto error;
            }
            break;
        default:
            break;
        }
    }
    data->programSize = op;

    return 0;
error:
    return -1;
}

static char* corto_selectTokenStr(corto_selectToken t) {
    switch(t) {
    case TOKEN_NONE: return "none";
    case TOKEN_IDENTIFIER: return "identifier";
    case TOKEN_SCOPE: return "/";
    case TOKEN_TREE: return "//";
    case TOKEN_ASTERISK: return "*";
    case TOKEN_WILDCARD: return "?";
    case TOKEN_THIS: return ".";
    case TOKEN_PARENT: return "..";
    }
    return NULL;
}

static int corto_selectValidate(corto_selectData *data) {
    int op;
    corto_selectToken t = TOKEN_NONE, tprev = TOKEN_NONE;
    for (op = 0; op < data->programSize; op++) {
        t = data->program[op].token;
        switch(t) {
        case TOKEN_IDENTIFIER:
            switch(tprev) {
            case TOKEN_IDENTIFIER:
            case TOKEN_ASTERISK:
            case TOKEN_WILDCARD:
            case TOKEN_THIS:
            case TOKEN_PARENT:
                goto error;
            default: break;
            }
            break;
        case TOKEN_SCOPE:
            switch(tprev) {
            case TOKEN_SCOPE:
            case TOKEN_TREE:
                goto error;
            default: break;
            }
            break;
        case TOKEN_TREE:
            switch(tprev) {
            case TOKEN_SCOPE:
            case TOKEN_TREE:
                goto error;
            default: break;
            }
            break;
        case TOKEN_THIS:
        case TOKEN_PARENT:
            switch(tprev) {
            case TOKEN_THIS:
            case TOKEN_PARENT:
                goto error;
            default: break;
            }
            break;
        case TOKEN_WILDCARD:
        case TOKEN_ASTERISK:
            switch(tprev) {
            case TOKEN_IDENTIFIER:
            case TOKEN_THIS:
            case TOKEN_PARENT:
            case TOKEN_ASTERISK:
            case TOKEN_WILDCARD:
                goto error;
            default: break;
            }
            break;
        default:
            break;
        }
        tprev = t;
    }

    switch(t) {
    case TOKEN_SCOPE:
    case TOKEN_TREE:
        corto_seterr("'%s' unexpected at end of expression",
            corto_selectTokenStr(t));
        goto unexpected_end_error;
    default:
        break;
    }

    return 0;
error:
    corto_seterr("unexpected '%s' after '%s'",
        corto_selectTokenStr(t),
        corto_selectTokenStr(tprev));
unexpected_end_error:
    return -1;
}

static void corto_setItemData(
    corto_object o,
    corto_result *item,
    corto_selectData *data)
{
    if (o != root_o) {
        corto_relname(data->scope, corto_parentof(o), item->parent);
    } else {
        *item->parent = '\0';
    }

    if (corto_nameof(o)) {
        strcpy(item->name, corto_nameof(o));
    } else {
        item->name[0] = '\0';
    }

    if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
        if (corto_parentof(corto_typeof(o)) == corto_lang_o) {
            strcpy(item->type, corto_nameof(corto_typeof(o)));
        } else {
            corto_id type;
            corto_fullname(corto_typeof(o), type);
            strcpy(item->type, type + 1);
        }
    } else {
        corto_string_ser_t serData;
        struct corto_serializer_s s;

        serData.buffer = item->type;
        serData.length = CORTO_MAX_PATH_LENGTH;
        serData.maxlength = CORTO_MAX_PATH_LENGTH;
        serData.compactNotation = TRUE;
        serData.prefixType = FALSE;
        serData.enableColors = FALSE;

        s = corto_string_ser(
            CORTO_LOCAL,
            CORTO_NOT,
            CORTO_SERIALIZER_TRACE_NEVER);
        corto_serialize(&s, corto_typeof(o), &serData);
    }
}

static void corto_selectThis(
    corto_selectData *data,
    corto_selectStack *frame) {

    if (!data->next) {
        data->next = &data->item;
        corto_setItemData(frame->o, data->next, data);
    } else {
        corto_setref(&frame->o, NULL);
        data->next = NULL;
    }
}

static corto_bool corto_selectMatch(corto_string filter, corto_string name) {
    corto_id filterLc, nameLc;

    strcpy(filterLc, filter);
    strcpy(nameLc, name);
    corto_strlower(filterLc);
    corto_strlower(nameLc);

    return !fnmatch(filterLc, nameLc, 0);
}

static corto_object corto_selectIterNext(
    corto_selectStack *frame,
    corto_string lastKey)
{
    corto_object result = NULL;

    if (corto_rbtreeIterChanged(&frame->iter)) {
        frame->iter = _corto_rbtreeIter(corto_scopeof(frame->o), &frame->trav);
        while (corto_iterHasNext(&frame->iter)) {
            corto_object o = corto_iterNext(&frame->iter);
            if (stricmp(corto_nameof(o), lastKey) > 0) {
                result = o;
                break;
            }
        }
    } else {
        if (corto_iterHasNext(&frame->iter)) {
            result = corto_iterNext(&frame->iter);
        }
    }

    return result;
}

static void corto_selectRequestReplicators(
    corto_selectData *data,
    corto_selectStack *frame,
    corto__scope *scope)
{
    if (data->activeReplicators < 0) {
        corto__ols *ols = corto_olsFind(scope, CORTO_OLS_REPLICATOR);
        data->activeReplicators = 0;

        if (ols) {
            corto_ll replicators = ols->value;
            if (replicators) {
                corto_iter iter = corto_llIter(replicators);

                while (corto_iterHasNext(&iter)) {
                    corto_replicator_olsData_t *odata = corto_iterNext(&iter);

                    /* Make select request to replicator */
                    data->replicators[data->activeReplicators ++] =
                        corto_replicator_request(
                            odata->replicator,
                            frame->o,
                            frame->filter ? frame->filter : "*");
                }
            }
        }
    }
}

static void corto_selectIterateReplicators(
    corto_selectData *data,
    corto_selectStack *frame)
{
    if (data->activeReplicators) {
        if (data->currentReplicator < 0) {
            data->currentReplicator = 0;
        }

        /* Walk over iterators until one with data available has been found */
        while ((data->currentReplicator < data->activeReplicators)) {
            corto_resultIter *iter = &data->replicators[data->currentReplicator];
            while (corto_iterHasNext(iter)) {
                corto_result *result = corto_iterNext(iter);
                if (!frame->filter ||
                    corto_selectMatch(frame->filter, result->name))
                {
                    data->next = &data->item;

                    /* Copy data, so replicator can safely release it */
                    if (result->name) {
                        strcpy(data->item.name, result->name);
                    } else {
                        data->item.name[0] = '\0';
                    }
                    if (result->parent) {
                        strcpy(data->item.parent, result->name);
                    } else {
                        data->item.parent[0] = '\0';
                    }
                    if (result->type) {
                        strcpy(data->item.type, result->name);
                    } else {
                        data->item.type[0] = '\0';
                    }

                    break;
                }
            }

            if (!data->next) {
                corto_iterRelease(iter);
                data->currentReplicator ++;
            } else {
                break;
            }
        }
    }
}

static void corto_selectScope(
    corto_selectData *data,
    corto_selectStack *frame)
{
    corto_object o = NULL;
    corto_string lastKey = data->item.name;

    corto__scope *scope = corto__scopeClaim(frame->o);

    /* Request replicators once per scope, and do it before iterating over
     * corto store objects so replicators have more time to fetch data. */
    corto_selectRequestReplicators(data, frame, scope);

    data->next = NULL;

    /* If not iterating over a replicator, we're iterating over the store */
    if (data->currentReplicator == -1) {
        while ((o = corto_selectIterNext(frame, lastKey))) {
            if (!frame->filter || corto_selectMatch(frame->filter, corto_nameof(o))) {
                data->next = &data->item;
                corto_setItemData(o, data->next, data);
                break;
            }
        }
    }

    corto__scopeRelease(frame->o);

    /* Handle replicator iteration outside of scope lock */
    if (!data->next) {
        corto_selectIterateReplicators(data, frame);
    }
}

/* Depth first search */
static void corto_selectTree(
    corto_selectData *data,
    corto_selectStack *frame)
{
    corto_string lastKey = data->item.name;
    data->next = NULL;

    do {
        corto_object claimed = frame->o;
        corto__scope *scope = corto__scopeClaim(claimed);
        corto_object o = NULL;

        while (!(o = corto_selectIterNext(frame, lastKey)) && data->sp) {
            corto__scopeRelease(claimed);
            /* Cache name as next line might delete object */
            strcpy(data->item.name, corto_nameof(frame->o));
            corto_setref(&frame->o, NULL);
            data->sp --;
            frame = &data->stack[data->sp];
            scope = corto__scopeClaim((claimed = frame->o));
        }

        if (data->sp || o) {
            data->next = &data->item;
            corto_setItemData(o, data->next, data);

            corto_rbtree tree = corto_scopeof(o);
            if (tree && corto_rbtreeSize(tree)) {
                frame = &data->stack[++ data->sp];
                corto_setref(&frame->o, o);
                frame->iter = _corto_rbtreeIter(tree, &frame->trav);
                frame->next = corto_selectTree;
                frame->filter = data->stack[data->sp - 1].filter;
            }
        } else {
            data->next = NULL;
        }
        corto__scopeRelease(claimed);
    } while (frame->filter && (data->next &&
        !corto_selectMatch(frame->filter, data->next->name)));
}

static int corto_selectRun(corto_selectData *data) {
    corto_int32 i;
    corto_selectOp *op;
    corto_selectStack *frame = &data->stack[data->sp];
    corto_bool explicitRef = FALSE;
    if (data->sp) {
        explicitRef = TRUE;
    }

    if (!data->programSize) {
        corto_seterr("invalid program");
        goto error;
    }

    data->next = NULL;
    frame->next = corto_selectScope;

    /* Traverse program until a token has been found that requires iterating,
     * which is then taken care of by hasNext */
    for (i = 0; i < data->programSize; i ++) {
        op = &data->program[i];

        switch (op->token) {
        case TOKEN_THIS:
            frame->next = corto_selectThis;
            explicitRef = TRUE;
            break;
        case TOKEN_PARENT:
            if (frame->o != root_o) {
                corto_setref(&frame->o, corto_parentof(frame->o));
                frame->next = corto_selectThis;
            } else {
                corto_seterr("can't select parent of root");
                goto error;
            }
            explicitRef = TRUE;
            break;
        case TOKEN_SCOPE:
            frame->next = corto_selectScope;
            if (!explicitRef) {
                corto_setref(&frame->o, root_o);
            }
            break;
        case TOKEN_TREE:
            frame->next = corto_selectTree;
            if (!explicitRef) {
                corto_setref(&frame->o, root_o);
            }
            break;
        case TOKEN_IDENTIFIER:
            explicitRef = TRUE;
            if (!op->containsWildcard) {
                corto_object o = corto_lookup(frame->o, op->start);
                if (o) {
                    frame->next = corto_selectThis;
                    corto_setref(&frame->o, o);
                    corto_release(o);
                    break;
                }
            }

            /* If expression contains wildcard OR does not resolve to an object,
             * lookup object in scope (and replicators) */
            frame->filter = op->start;

        case TOKEN_WILDCARD:
            if (op->token == TOKEN_WILDCARD) {
                frame->filter = "?";
            }
        case TOKEN_ASTERISK: {
            corto_rbtree tree = corto_scopeof(frame->o);
            if (tree) {
                frame->iter = _corto_rbtreeIter(tree, &frame->trav);
            } else {
                memset(&frame->iter, 0, sizeof(corto_iter));
            }
            break;
        default:
            break;
        }
        }
    }

    return 0;
error:
    return -1;
}

static int corto_selectHasNext(corto_resultIter *iter) {
    corto_selectData *data = corto_selectDataGet();
    corto_selectStack *frame = &data->stack[data->sp];
    CORTO_UNUSED(iter);

    if (!data->next) {
        if (corto_selectRun(data)) {
            goto error;
        }
    }

    if (frame->next) {
        frame->next(data, frame);
    }

    return data->next != NULL;
error:
    return 0; /* Don't return -1, as this would require all hasNext statements
               * to check for two values */
}

static void* corto_selectNext(corto_resultIter *iter) {
    corto_selectData *data = corto_selectDataGet();

    CORTO_UNUSED(iter);

    return data->next;
}

corto_int16 corto_select(
    corto_object scope,
    corto_string expr,
    corto_resultIter *iter_out)
{
    corto_selectData *data = corto_selectDataGet();

    if (!scope) {
        scope = root_o;
    }

    corto_setstr(&data->expr, expr);
    data->scope = scope;
    data->sp = 0;
    data->next = NULL;
    data->activeReplicators = -1;
    data->currentReplicator = -1;

    iter_out->hasNext = corto_selectHasNext;
    iter_out->next = corto_selectNext;

    if (corto_selectParse(data)) {
        corto_seterr("select '%s' failed: %s", expr, corto_lasterr());
        goto error;
    }

    if (corto_selectValidate(data)) {
        corto_seterr("select '%s' failed: %s", expr, corto_lasterr());
        data->programSize = 0;
        goto error;
    }

    /* Prepare first stack frame */
    corto_claim(scope);
    memset(&data->stack, 0, sizeof(data->stack));
    data->stack[0].o = scope;

    return 0;
error:
    return -1;
}
