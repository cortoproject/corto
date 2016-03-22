
#include "corto/corto.h"
#include "_object.h"

extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_int8 CORTO_OLS_AUGMENT;
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
    corto_object scope; /* Object of whose scope is being iterated */
    corto_string scopeQuery; /* String remainder of scope to be iterated */
    jsw_rbtrav_t trav; /* Persistent tree iterator */
    corto_iter iter;
    corto_string filter;

    /* Callback for either returning single object, traversing
     * scope or traversing a tree. */
    void (*next)(struct corto_selectData *data,
        struct corto_selectStack *frame);
} corto_selectStack;

typedef struct corto_contentType {
    corto_word ___ (*contentFromCorto)(corto_object o);
    corto_int16 ___ (*contentToCorto)(corto_object o, corto_word content);
    void (*contentRelease)(corto_word content);
} corto_contentType;

typedef struct corto_scopeSegment {
    corto_object scope;
    corto_string scopeQuery;
} corto_scopeSegment;

typedef struct corto_selectData {
    corto_string expr;                       /* Full expression */
    corto_string tokens;                     /* Cut up string for op tokens */
    corto_string contentType;
    corto_string param;
    corto_string scope;                      /* Scope passed to select */
    corto_scopeSegment scopes[CORTO_MAX_SCOPE_DEPTH]; /* Scopes to walk (parsed scope) */
    corto_uint32 currentScope;               /* Scope currently being walked */
    corto_selectOp program[CORTO_SELECT_MAX_OP]; /* Parsed program */
    corto_uint8 programSize;
    corto_selectStack stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    corto_uint8 sp;

    /* Replicators loaded for the scope that is currently evaluated */
    corto_resultIter replicators[CORTO_MAX_REPLICATORS];

    /* Replicators with outstanding requests */
    corto_int8 activeReplicators;

    /* Current replicator being evaluated */
    corto_int8 currentReplicator;

    /* Serializer for requested content type */
    corto_contentType destSer;

    /* Serializers for source content types */
    corto_contentType srcSer[CORTO_MAX_REPLICATORS];

    /* Limit results */
    corto_uint64 offset;
    corto_uint64 limit;
    corto_uint64 count;

    /* Augment filter */
    corto_string augmentFilter;

    /* Pre allocated for selectItem */
    corto_id id;
    corto_id name;
    corto_id parent;
    corto_id type;
    corto_augmentData augmentBuffer[CORTO_MAX_AUGMENTS];
    corto_result item;
    corto_result *next;
} corto_selectData;

static corto_string corto_selectToStr(corto_object o) {
    return corto_str(o, 0);
}

static corto_int16 corto_selectFromStr(corto_object o, corto_string str) {
    return corto_fromStr(&o, str);
}

static corto_int16 corto_loadContentType(
    corto_contentType *type_out,
    corto_string contentType)
{
    /* Built in Corto string serializer */
    if (!strcmp(contentType, "text/corto")) {
        type_out->contentToCorto =
            (corto_int16 ___ (*)(corto_object, corto_word))corto_selectFromStr;

        type_out->contentFromCorto =
            (corto_word ___ (*)(corto_object))corto_selectToStr;

        type_out->contentRelease = (void ___ (*)(corto_word))corto_dealloc;

    } else {
        char *componentPtr = strchr(contentType, '/');
        if (!componentPtr) {
            corto_seterr("invalid content type %s", contentType);
            goto error;
        }

        componentPtr ++;

        corto_id component;
        sprintf(component, "corto/fmt/%s", componentPtr);

        /* Load component associated with content type */
        corto_seterr(NULL);
        if (corto_load(component, 0, NULL)) {
            if (corto_lasterr()) {
                corto_seterr("unsupported content type %s (%s)",
                    contentType, corto_lasterr());
            } else {
                corto_seterr("unsupported content type %s", contentType);
            }
            goto error;
        }

        /* Load serialization routines */
        corto_id id; sprintf(id, "%s_fromCorto", componentPtr);
        type_out->contentFromCorto =
            (corto_word ___ (*)(corto_object))corto_loaderResolveProc(id);
        if (!type_out->contentFromCorto) {
            corto_seterr("unresolved symbol %s", id);
            goto error;
        }

        sprintf(id, "%s_toCorto", componentPtr);
        type_out->contentToCorto =
            (corto_int16 ___ (*)(corto_object, corto_word))
            corto_loaderResolveProc(id);
        if (!type_out->contentToCorto) {
            corto_seterr("unresolved symbol %s", id);
            goto error;
        }

        sprintf(id, "%s_release", componentPtr);
        type_out->contentRelease =
            (void ___ (*)(corto_word))corto_loaderResolveProc(id);
        if (!type_out->contentRelease) {
            corto_seterr("unresolved symbol %s", id);
            goto error;
        }
    }

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
            case TOKEN_PARENT:
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

static int corto_selectParse(corto_selectData *data) {
    char *ptr, *start, ch;
    int op = 0;

    ptr = data->tokens;
    for (; (ch = *ptr); data->program[op].start = ptr, ptr++) {
        data->program[op].containsWildcard = FALSE;
        data->program[op].start = NULL;
        start = ptr;
        switch(ch) {
        case '.':
            if (ptr[1] == '.') {
                if ((op < 4) ||
                    ((data->program[op - 2].token == TOKEN_PARENT) &&
                     (data->program[op - 1].token == TOKEN_SCOPE)))
                {
                    data->program[op].token = TOKEN_PARENT;
                } else {
                    op -= 4;
                }
                *ptr = '\0';
                ptr++;
            } else {
                if ((op < 2) || (data->program[op - 1].token != TOKEN_SCOPE)) {
                    data->program[op].token = TOKEN_THIS;
                } else {
                    op -= 2;
                }
                *ptr = '\0';
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

        if (!data->program[op].start) {
            data->program[op].start = start;
        }
        if (++op == CORTO_SELECT_MAX_OP) {
            corto_seterr("expression contains too many tokens");
            goto error;
        }
    }

    if (op) {
        data->programSize = op;

        switch(data->program[op - 1].token) {
        case TOKEN_SCOPE:
        case TOKEN_TREE:
            data->programSize--; /* Ignore trailing SCOPE or TREE */
            break;
        default:
            break;
        }

        if (corto_selectValidate(data)) {
            data->programSize = 0;
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

static corto_word corto_selectConvert(
    corto_selectData *data,
    corto_string type,
    corto_word value)
{
    corto_word result = 0;

    corto_int16 ___ (*toCorto)(corto_object o, corto_word content) =
        data->srcSer[data->currentReplicator].contentToCorto;
    corto_word ___ (*fromCorto)(corto_object o) =
        data->destSer.contentFromCorto;

    /* If source serializer is loaded, a conversion is
     * needed */
    if (toCorto) {
        corto_object t = corto_resolve(NULL, type);
        if (!t) {
            corto_seterr("unresolved type '%s'", type);
            goto error;
        } else {
            corto_object o = corto_create(t);

            /* Convert from source format to object */
            if (toCorto(o, value)) {
                corto_seterr("failed to convert value to '%s' (%s)",
                    type,
                    corto_lasterr());
                goto error;
            }

            /* Convert from object to destination format */
            if (!(result = fromCorto(o))) {
                corto_seterr("failed to convert value to '%s' (%s)",
                    data->contentType,
                    corto_lasterr());
                goto error;
            }

            corto_delete(o);
        }
    } else {
        /* If formats are equal, just pass through */
        result = value;
    }

    return result;
error:
    return 0;
}

static void corto_loadAugments(
    corto_string parent,
    corto_string expr,
    corto_string type,
    corto_result *item,
    corto_selectData *data)
{
    corto_type t = corto_resolve(NULL, type);

    if (t) {
        corto_ll augments = corto_olsGet(t, CORTO_OLS_AUGMENT);
        if (augments) {
            corto_iter it = corto_llIter(augments);
            item->augments.buffer = data->augmentBuffer;

            while (corto_iterHasNext(&it)) {
                corto_augment_olsData_t *ols = corto_iterNext(&it);

                if (!fnmatch(data->augmentFilter, ols->id, 0)) {
                    corto_augmentData *augment = &item->augments.buffer[item->augments.length];

                    item->augments.length++;
                    augment->id = ols->id;

                    /* Request augmentdata if user wants content */
                    if (data->contentType) {
                        corto_iter augmentIt;
                        corto_request r = {
                            parent, expr, 0, 1, data->contentType == NULL, NULL
                        };

                        augmentIt = corto_replicator_request(
                          ols->replicator,
                          &r);

                        /* Expecting a single result */
                        if (augmentIt.hasNext(&augmentIt)) {
                            corto_result *result = augmentIt.next(&augmentIt);
                            if (result) {
                                if (augment->data) {
                                    data->destSer.contentRelease(augment->data);
                                }

                                augment->data = corto_selectConvert(
                                    data,
                                    item->type,
                                    result->value);
                            }
                        }

                        if (augmentIt.release) {
                            augmentIt.release(&augmentIt);
                        }
                    }
                }
            }
        }

        corto_release(t);
    }
}

corto_int32 corto_pathToArray(corto_string path, char *elements[], char *sep);


static char* corto_pathstr(
    corto_string buffer,
    corto_string from,
    corto_string to,
    char *sep)
{
    char *fromArray[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 fromCount = corto_pathToArray(from, fromArray, sep);
    char *toArray[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 toCount = corto_pathToArray(to, toArray, sep);
    corto_int32 common = 0;
    buffer[0] = '\0'; buffer[1] = '\0';

    /* Find common ancestor */
    while ((common < fromCount) &&
       (common < toCount) &&
       !strcmp(fromArray[common], toArray[common]))
    {
        common ++;
    }

    if ((fromCount == toCount) && (toCount == common)) {
        strcpy(buffer, ".");
    } else {
        /* Go up until common ancestor */
        while (fromCount > common) {
            if (buffer[0]) {
                strcat(buffer, "/..");
            } else {
                strcat(buffer, "..");
            }
            fromCount --;
        }

        /* Navigate from common ancestor to target */
        while (common < toCount) {
            if (!toArray[common][0] || (buffer[0] && strcmp(buffer, "/"))) {
                strcat(buffer, "/");
            }
            strcat(buffer, toArray[common]);
            common ++;
        }
    }

    return buffer;
}

static void corto_setItemData(
    corto_object o,
    corto_result *item,
    corto_selectData *data)
{
    corto_id from, to;

    /* Construct from-string from scope and scopeQuery */
    corto_fullpath(from, data->scopes[data->currentScope].scope);
    if (data->scopes[data->currentScope].scopeQuery) {
        if (from[1]) {
            strcat(from, "/");
        }
        strcat(from, data->scopes[data->currentScope].scopeQuery);
    }

    /* Construct to-string from parent of object */
    if (o != root_o) {
        corto_fullpath(to, corto_parentof(o));
    } else {
        /* Avoid the parent string from navigating beyond the root */
        corto_fullpath(to, o);
    }

    /* Compute path from scope to result */
    corto_pathstr(item->parent, from, to, "/");

    if (corto_nameof(o)) {
        strcpy(item->id, corto_nameof(o));
        strcpy(item->name, corto_nameof(o));
    } else {
        item->id[0] = '\0';
        item->name[0] = '\0';
    }

    if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
        strcpy(item->type, corto_fullpath(NULL, corto_typeof(o)));
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

    if (data->contentType) {
        if (item->value) {
            data->destSer.contentRelease(item->value);
        }
        item->value = data->destSer.contentFromCorto(o);
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
        frame->iter = _corto_rbtreeIter(corto_scopeof(frame->scope), &frame->trav);
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

static void corto_selectParseFilter(
    corto_string filter,
    corto_id parent,
    corto_id expr)
{
    /* Separate filter in parent and expression */
    if (filter) {
        char *ptr = filter;
        char *exprStart = filter;
        while ((ptr = strchr(ptr, '/')) && (ptr[1] != '/')) {
            ptr ++;
            exprStart = ptr;
        }

        /* If ptr is NULL, the filter contains no '//' and thus the expr
         * should start after the last '/'. If the expression does contain a
         * '//', it should start at '//' (ptr). */
        exprStart = ptr ? ptr : exprStart;

        strcpy(expr, exprStart);
        if (exprStart != filter) {
            if (*parent) strcat(parent, "/");
            strcat(parent, filter);
            parent[strlen(parent) - (strlen(exprStart) + (ptr ? 0 : 1))] = '\0';
            corto_cleanpath(parent);
        } else if (!*parent) {
            strcpy(parent, ".");
        }
    } else {
        if (!*parent) strcpy(parent, ".");
        strcpy(expr, "*");
    }
}

/* Function returns FALSE if a SINK is found, which means that for this scope
 * the object store should not be walked */
static corto_bool corto_selectRequestReplicators(
    corto_selectData *data,
    corto_selectStack *frame,
    corto__scope *scope)
{
    corto_bool result = TRUE;

    if (data->activeReplicators < 0) {
        corto_id parent, expr;
        corto_bool releaseScope = FALSE;

        if (!scope) {
            scope = corto__scopeClaim(frame->scope);
            releaseScope = TRUE;
        }

        corto__ols *ols = corto_olsFind(scope, CORTO_OLS_REPLICATOR);

        if (frame->scopeQuery) {
            strcpy(parent, frame->scopeQuery);
        } else {
            *parent = '\0';
        }

        corto_selectParseFilter(frame->filter, parent, expr);
        data->activeReplicators = 0;

        if (ols) {
            corto_ll replicators = ols->value;
            if (replicators) {
                corto_iter iter = corto_llIter(replicators);

                while (corto_iterHasNext(&iter)) {
                    corto_replicator_olsData_t *odata = corto_iterNext(&iter);

                    /* If required, load replicator content type */
                    if (data->contentType && odata->replicator->contentType) {
                        if (strcmp(
                              data->contentType,
                              odata->replicator->contentType))
                        {
                            if (corto_loadContentType(
                                &data->srcSer[data->activeReplicators],
                                odata->replicator->contentType))
                            {
                                corto_error("contentType '%s' for %s not found",
                                  odata->replicator->contentType,
                                  corto_fullpath(NULL, corto_typeof(odata->replicator)));

                                /* Ignore replicator */
                                continue;
                            }
                        }
                    }

                    /* Make select request to replicator */
                    corto_request r = {
                      parent,
                      expr,
                      (data->offset > data->count) ? data->offset - data->count : 0,
                      (data->offset > data->count) ? data->limit : data->limit - (data->offset - data->count),
                      data->contentType ? TRUE : FALSE,
                      data->param};

                    data->replicators[data->activeReplicators ++] =
                        corto_replicator_request(
                            odata->replicator,
                            &r
                        );

                    if (odata->replicator->kind == CORTO_SINK) {
                        result = FALSE;
                    }
                }
            }
        }

        if (releaseScope) {
            corto__scopeRelease(frame->scope);
        }
    }

    return result;
}

static void corto_selectIterateReplicators(
    corto_selectData *data,
    corto_selectStack *frame)
{
    if (data->activeReplicators) {
        corto_id parent, expr;

        /* Parse filter into parent and expression */
        if (frame->scopeQuery) {
            strcpy(parent, frame->scopeQuery);
        } else {
            *parent = '\0';
        }

        corto_selectParseFilter(frame->filter, parent, expr);

        if (data->currentReplicator < 0) {
            data->currentReplicator = 0;
        }

        /* Walk over iterators until one with data available has been found */
        while ((data->currentReplicator < data->activeReplicators)) {
            corto_resultIter *iter = &data->replicators[data->currentReplicator];

            while (corto_iterHasNext(iter)) {
                corto_result *result = corto_iterNext(iter);
                if (!result) {
                    corto_error("replicator returned NULL result");
                    continue;
                }
                if (!frame->filter ||
                    corto_selectMatch(expr, result->id))
                {
                    data->next = &data->item;
                    data->count ++;

                    /* Copy data, so replicator can safely release it */
                    if (result->id) {
                        strcpy(data->item.id, result->id);
                    } else {
                        data->item.id[0] = '\0';
                    }

                    if (result->name) {
                        strcpy(data->item.name, result->name);
                    } else {
                        if (!result->id) {
                            data->item.name[0] = '\0';
                        } else {
                            strcpy(data->item.name, result->id);
                        }
                    }

                    /* If augmentFilter is provided, load augments */
                    if (data->augmentFilter) {
                        corto_loadAugments(
                          result->parent,
                          result->id,
                          result->type,
                          &data->item,
                          data);
                    }

                    if (result->parent) {
                        corto_id path, rpath;

                        corto_fullpath(path, data->scopes[data->currentScope].scope);
                        if (data->scopes[data->currentScope].scopeQuery) {
                            strcat(path, "/");
                            strcat(path, data->scopes[data->currentScope].scopeQuery);
                        }

                        corto_fullpath(rpath, frame->scope);
                        strcat(rpath, "/");
                        strcat(rpath, parent);
                        strcat(rpath, "/");
                        strcat(rpath, result->parent);
                        corto_cleanpath(rpath);

                        corto_pathstr(data->item.parent, path, rpath, "/");

                    } else {
                        data->item.parent[0] = '\0';
                    }

                    if (result->type) {
                        strcpy(data->item.type, result->type);
                    } else {
                        data->item.type[0] = '\0';
                    }

                    if (data->contentType) {
                        data->destSer.contentRelease(data->item.value);
                        data->item.value = corto_selectConvert(
                          data, result->type, result->value);
                    }

                    if (data->count > data->offset) {
                        break;
                    }
                }
            }

            if (!data->next) {
                data->currentReplicator ++;
            } else {
                break;
            }
        }
    }
}

static void corto_selectThis(
    corto_selectData *data,
    corto_selectStack *frame)
{
    if (frame->scopeQuery) {
        corto__scope *scope = corto__scopeClaim(frame->scope);
        frame->filter = frame->scopeQuery;
        frame->scopeQuery = NULL;
        corto_selectRequestReplicators(data, frame, scope);
        corto__scopeRelease(frame->scope);
        corto_selectIterateReplicators(data, frame);
    } else {
        if (!data->next) {
            data->next = &data->item;
            corto_setItemData(frame->scope, data->next, data);
        } else {
            /* Second time this function is called, ensure that hasNext returns
             * FALSE */
            corto_setref(&frame->scope, NULL);
            data->next = NULL;

            /* Signal that select shouldn't continue searching the next scope */
            frame->next = NULL;
        }
    }
}

static void corto_selectScope(
    corto_selectData *data,
    corto_selectStack *frame)
{
    corto_object o = NULL;
    corto_string lastKey = data->item.name;
    corto__scope *scope = corto__scopeClaim(frame->scope);

    /* Request replicators once per scope, and do it before iterating over
     * corto store objects so replicators have more time to fetch data. */
    corto_bool walkScope = corto_selectRequestReplicators(data, frame, scope);

    data->next = NULL;

    /* If not iterating over a replicator, we're iterating over the store */
    if ((data->currentReplicator == -1) &&
        !data->scopes[data->currentScope].scopeQuery)
    {
        while ((o = corto_selectIterNext(frame, lastKey))) {
            /* Skip object if walkScope is FALSE (which means that there is a
             * SINK replicator attached) *and* the object is not PERSISTENT
             * (a replicator won't persist non-PERSISTENT objects) */
            if ((!frame->filter ||
                corto_selectMatch(frame->filter, corto_nameof(o))) &&
                (walkScope || !corto_checkAttr(o, CORTO_ATTR_PERSISTENT)))
            {
                data->count ++;
                if (data->count > data->offset) {
                    data->next = &data->item;
                    corto_setItemData(o, data->next, data);
                    break;
                }
            }
        }
    }

    corto__scopeRelease(frame->scope);

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
    corto_bool noMatch = TRUE;

    /* Request replicators once per scope, and do it before iterating over
     * corto store objects so replicators have more time to fetch data. */
    corto_bool walkScope = corto_selectRequestReplicators(data, frame, NULL);

    data->next = NULL;

    if ((data->currentReplicator == -1) &&
        !data->scopes[data->currentScope].scopeQuery)
    {
        corto_object o = NULL;

        do {
            corto_object claimed = frame->scope;
            corto__scopeClaim(claimed);

            while (!(o = corto_selectIterNext(frame, lastKey)) && data->sp) {
                corto__scopeRelease(claimed);
                /* Cache name as next line might delete object */
                strcpy(data->item.name, corto_nameof(frame->scope));
                corto_setref(&frame->scope, NULL);
                data->sp --;
                frame = &data->stack[data->sp];
                corto__scopeClaim((claimed = frame->scope));
            }

            if (data->sp || o) {
                data->next = &data->item;
                corto_setItemData(o, data->next, data);

                corto_rbtree tree = corto_scopeof(o);
                if (tree && corto_rbtreeSize(tree)) {
                    frame = &data->stack[++ data->sp];
                    corto_setref(&frame->scope, o);
                    frame->iter = _corto_rbtreeIter(tree, &frame->trav);
                    frame->next = corto_selectTree;
                    frame->filter = data->stack[data->sp - 1].filter;
                }
            } else {
                data->next = NULL;
            }
            corto__scopeRelease(claimed);

            noMatch = ((frame->filter && (data->next &&
              !corto_selectMatch(frame->filter, data->next->name))) &&
              (walkScope || !corto_checkAttr(o, CORTO_ATTR_PERSISTENT)));

            if (!noMatch) {
                data->count ++;
                if (data->count <= data->offset) {
                    noMatch = TRUE;
                }
            }
        } while (noMatch);
    }

    /* Handle replicator iteration outside of scope lock */
    if (!data->next) {
        corto_selectIterateReplicators(data, frame);
    }
}

static int corto_selectRun(corto_selectData *data) {
    corto_int32 i;
    corto_selectOp *op;
    corto_selectStack *frame = &data->stack[data->sp];

    if (!data->programSize) {
        corto_seterr("invalid expression: '%s'", data->expr);
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
            break;
        case TOKEN_PARENT: {
            /* Take parent of current scope, start with scopeQuery string */
            if (frame->scopeQuery) {
                corto_id path;

                sprintf(
                  path,
                  "%s/..",
                  frame->scopeQuery);
                corto_cleanpath(path);

                if (data->scopes[data->currentScope].scopeQuery != frame->scopeQuery) {
                    corto_dealloc(frame->scopeQuery);
                }

                frame->scopeQuery = NULL;
                if (strcmp(path, ".") && strlen(path)) {
                    frame->scopeQuery = corto_strdup(path);
                }
            } else {
                if (frame->scope != root_o) {
                    corto_setref(&frame->scope, corto_parentof(frame->scope));
                    frame->next = corto_selectThis;
                } else {
                    corto_seterr("can't select parent of root");
                    goto error;
                }
            }
            frame->next = corto_selectThis;
            break;
        }
        case TOKEN_SCOPE:
            frame->next = corto_selectScope;
            break;
        case TOKEN_TREE:
            frame->next = corto_selectTree;
            break;
        case TOKEN_IDENTIFIER:
            if (!op->containsWildcard && !frame->scopeQuery) {
                corto_object o = corto_lookup(frame->scope, op->start);
                if (o) {
                    frame->next = corto_selectThis;
                    corto_setref(&frame->scope, o);
                    corto_release(o);
                    break;
                }
            }

            /* If expression contains wildcard OR does not resolve to an object,
             * lookup object in scope (and replicators) */
            if (!frame->filter) {
                frame->filter = &data->expr[op->start - data->tokens];
            }

        case TOKEN_WILDCARD:
            if (op->token == TOKEN_WILDCARD) {
                if (!frame->filter) {
                    frame->filter = "?";
                }
            }
        case TOKEN_ASTERISK: {
            corto_rbtree tree = corto_scopeof(frame->scope);
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

/* Reset select data (either initially or when moving to next scope) */
static void corto_selectReset(corto_selectData *data) {
    corto_int32 i = 0;

    for (i = 0; i < data->activeReplicators; i ++) {
        corto_iterRelease(&data->replicators[i]);
    }

    if (data->item.value && data->destSer.contentRelease) {
        data->destSer.contentRelease(data->item.value);
    }

    data->sp = 0;
    data->item.value = 0;
    data->activeReplicators = -1;
    data->currentReplicator = -1;
}

static corto_bool corto_selectNextScope(corto_selectData *data) {
    if (data->scopes[data->currentScope + 1].scope) {
        corto_selectStack *frame = &data->stack[0];

        /* Only continue of previous scope didn't return a single object, in
         * which case 'next' will have been set to NULL */
        if (frame->next &&
        /* If the current frame has been changed due to running the program,
         * subsequent scopes will yield the same outcome, and would result in
         * duplicate results. */
           (frame->scope == data->scopes[data->currentScope].scope))
        {
            corto_selectReset(data);
            data->currentScope ++;
            frame->scope = data->scopes[data->currentScope].scope;
            frame->scopeQuery = data->scopes[data->currentScope].scopeQuery;
            frame->filter = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

static int corto_selectHasNext(corto_resultIter *iter) {
    corto_selectData *data = iter->udata;
    corto_selectStack *frame = &data->stack[data->sp];

    CORTO_UNUSED(iter);

    if (data->limit) {
         if ((data->count > data->offset) &&
             (data->limit <= (data->count - data->offset)))
         {
              /* Limit is reached */
              goto error;
         }
    }

    do {
        if (!data->next) {
            if (corto_selectRun(data)) {
                goto error;
            }
        }

        if (frame->next) {
            frame->next(data, frame);
        }
    } while ((data->next == NULL) && (corto_selectNextScope(data)));

    return data->next != NULL;
error:
    return 0; /* Don't return -1, as this would require all hasNext statements
               * to check for two values */
}

static void* corto_selectNext(corto_resultIter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    return data->next;
}

static void corto_selectRelease(corto_iter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    if (data->expr) corto_dealloc(data->expr);
    if (data->tokens) corto_dealloc(data->tokens);
    if (data->scope) corto_dealloc(data->scope);

    corto_selectReset(data);

    data->expr = NULL;
    data->tokens = NULL;
    data->item.value = 0;
    corto_dealloc(data);
}

/* Split up scope expression in object/string pairs so replicators are invoked
 * at each level of the hierarchy. For example, the scope /a/b/c is split up in:
 *
 * / + "a/b/c"
 * /a + "b/c"
 * /a/b + "c"
 * /a/b/c
 *
 * Replicators registered for /, /a, /a/b and /a/b/c will be invoked with the
 * respective string remainders ("a/b/c", "b/c", "c").
 *
 * The function will only create elements for actual (not virtual) objects.
 */
static corto_int16 corto_selectSplitScope(corto_selectData *data) {
    memset(data->scopes, 0, sizeof(data->scopes));

    if (!data->scope || !strlen(data->scope)) {
        /* Leave scope to NULL. This way, the parent string in the result will
         * include the initial '/' */
    } else {
        char *ptr, *prev, ch;
        corto_uint32 current = 0;
        ptr = data->scope;

        if (ptr[0] == '/') {
            ptr ++;
        }

        /* Set first scope to root */
        corto_setref(&data->scopes[0].scope, root_o);
        data->scopes[0].scopeQuery = *ptr ? ptr : NULL;
        current ++;
        prev = ptr;

        do {
            ch = *ptr;
            if ((!ch && (prev != ptr)) || (ch == '/')) {
                corto_id expr;
                memcpy(expr, prev, ptr - prev);
                expr[ptr - prev] = '\0';

                /* Don't use resolve here since that might load objects in the
                 * object store, which is exactly what select must avoid */
                data->scopes[current].scope = corto_lookup(
                    data->scopes[current - 1].scope,
                    expr);
                if (!data->scopes[current].scope) {
                    /* If a scope cannot be found in the object store, select
                     * will attempt to request it from replicators */
                    break;
                } else {
                    data->scopes[current].scopeQuery = *ptr ? ptr + 1 : NULL;
                }

                prev = ptr + (*ptr ? 1 : 0);
                current++;
            }
            ptr++;
        } while (ch);
    }

    return 0;
}

static corto_resultIter corto_selectPrepareIterator (
    struct corto_selectRequest *r)
{
    corto_selectData *data = corto_calloc(sizeof(corto_selectData));

    corto_resultIter result;
    memset(&result, 0, sizeof(corto_resultIter));

    corto_string expr = r->expr;
    corto_string scope = r->scope;

    if (scope && *scope) {
        if (*scope != '/') {
            corto_asprintf(&data->scope, "/%s", scope);
        } else {
            data->scope = corto_strdup(scope);
        }
    } else {
        data->scope = NULL;
    }

    if (expr && *expr) {
        data->expr = corto_strdup(expr);
    } else {
        data->expr = corto_strdup(".");
    }

    data->tokens = corto_strdup(data->expr);
    data->contentType = r->contentType;
    data->activeReplicators = -1;
    data->currentReplicator = -1;
    data->offset = r->offset;
    data->limit = r->limit;
    data->augmentFilter = r->augment;
    data->item.parent = data->parent;
    data->item.name = data->name;
    data->item.type = data->type;
    data->item.id = data->id;

    if (corto_selectSplitScope(data)) {
        goto error;
    }

    if (data->contentType) {
        if (corto_loadContentType(&data->destSer, data->contentType)) {
            goto error;
        }
    }

    result.udata = data;
    result.hasNext = corto_selectHasNext;
    result.next = corto_selectNext;
    result.release = corto_selectRelease;

    if (corto_selectParse(data)) {
        corto_seterr("select '%s' failed: %s", expr, corto_lasterr());
        goto error;
    }

    /* Prepare first stack frame */
    data->stack[0].scope = data->scopes[0].scope ? data->scopes[0].scope : root_o;
    data->stack[0].scopeQuery = data->scopes[0].scopeQuery;

    return result;
error:
    r->err = 1;
    return result;
}

static corto_selectSelector corto_selectSelectorGet(void);

static corto_selectSelector corto_selectorContentType(
    corto_string contentType)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_SELECT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_selectSelectorGet();
}

static corto_selectSelector corto_selectorLimit(
    corto_uint64 offset,
    corto_uint64 limit)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_SELECT);
    if (request) {
        request->offset = offset;
        request->limit = limit;
    }
    return corto_selectSelectorGet();
}

static corto_selectSelector corto_selectorAugment(
    corto_string augment)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_SELECT);
    if (request) {
        request->augment = augment;
    }
    return corto_selectSelectorGet();
}

static corto_resultIter corto_selectorIter(void)
{
    corto_resultIter result;
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_SELECT);
    if (request) {
        result = corto_selectPrepareIterator(request);
    }
    return result;
}

static corto_selectSelector corto_selectSelectorGet(void)
{
    corto_selectSelector result;
    result.contentType = corto_selectorContentType;
    result.limit = corto_selectorLimit;
    result.augment = corto_selectorAugment;
    result._iter = corto_selectorIter;
    return result;
}

corto_selectSelector corto_select(
    corto_string scope,
    corto_string expr)
{
    corto_selectRequest *request = corto_threadTlsGet(CORTO_KEY_SELECT);
    if (!request) {
        request = corto_calloc(sizeof(corto_selectRequest));
        corto_threadTlsSet(CORTO_KEY_SELECT, request);
    } else {
        memset(request, 0, sizeof(corto_selectRequest));
    }
    request->scope = scope;
    request->expr = expr;
    return corto_selectSelectorGet();
}

corto_int16 corto_selectErr() {
    corto_selectRequest *request = corto_threadTlsGet(CORTO_KEY_SELECT);
    return request != NULL ? request->err : -1;
}
