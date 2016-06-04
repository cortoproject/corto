
#include "corto/corto.h"
#include "_object.h"

extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_int8 CORTO_OLS_AUGMENT;
extern corto_threadKey CORTO_KEY_SELECT;
#define CORTO_SELECT_MAX_OP (32)

typedef enum corto_selectToken {
    TOKEN_NONE,
    TOKEN_IDENTIFIER,
    TOKEN_FILTER,
    TOKEN_SCOPE,
    TOKEN_TREE,
    TOKEN_THIS,
    TOKEN_PARENT,
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

typedef struct corto_selectReplicator {
    corto_mount r;
    corto_resultIter iter;
} corto_selectReplicator;

typedef struct corto_selectData {
    corto_string scope;                      /* Scope passed to select */
    corto_string expr;                       /* Full expression */
    corto_string contentType;
    corto_string param;

    corto_string fullscope;                  /* Scope + scope part of expression */
    corto_scopeSegment scopes[CORTO_MAX_SCOPE_DEPTH]; /* Scopes to walk (parsed scope) */
    corto_uint32 currentScope;               /* Scope currently being walked */

    corto_string tokens;                     /* Cut up string for op tokens */
    corto_selectOp program[CORTO_SELECT_MAX_OP]; /* Parsed program */
    corto_uint8 programSize;

    corto_selectStack stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    corto_uint8 sp;

    /* Replicators loaded for the scope that is currently evaluated */
    corto_selectReplicator mounts[CORTO_MAX_REPLICATORS];

    /* Replicators with outstanding requests */
    corto_int8 activeReplicators;

    /* Current mount being evaluated */
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
    case TOKEN_FILTER: return "filter";
    case TOKEN_SCOPE: return "/";
    case TOKEN_TREE: return "//";
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
            case TOKEN_FILTER:
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
        case TOKEN_FILTER:
            switch(tprev) {
            case TOKEN_IDENTIFIER:
            case TOKEN_THIS:
            case TOKEN_PARENT:
            case TOKEN_FILTER:
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
            data->program[op].token = TOKEN_IDENTIFIER;
            while((ch = *ptr++) &&
                  (isalnum(ch) || (ch == '_') || (ch == '*') || (ch == '?') ||
                    (ch == '(') || (ch == ')') || (ch == '{') || (ch == '}'))) {
                if ((ch == '*') || (ch == '?')) {
                    data->program[op].token = TOKEN_FILTER;
                }
            }

            ptr--; /* Go back one character to adjust for lookahead of one */
            if (!(ptr - start)) {
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

                        augmentIt = corto_mount_request(
                          ols->mount,
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
    if (!from) from = "";
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
    corto_id to, from;

    /* Construct to-string from parent of object */
    if (o != root_o) {
        corto_fullpath(to, corto_parentof(o));
    } else {
        /* Avoid the parent string from navigating beyond the root */
        corto_fullpath(to, o);
    }

    /* Compute path from scope to result */
    strcpy(from, data->scope ? data->scope : "");
    corto_pathstr(item->parent, from, to, "/");

    if (corto_idof(o)) {
        strcpy(item->id, corto_idof(o));
        corto_nameof(item->name, o);
    } else {
        item->id[0] = '\0';
        item->name[0] = '\0';
    }

    if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
        strcpy(item->type, corto_fullpath(NULL, corto_typeof(o)));
    } else {
        corto_string_ser_t serData;
        struct corto_serializer_s s;

        serData.buffer = CORTO_BUFFER_INIT;
        serData.buffer.buf = item->type;
        serData.buffer.max = CORTO_MAX_PATH_LENGTH;
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

static corto_bool corto_selectMatch(
    corto_selectStack *frame,
    corto_object o,
    corto_selectData *data)
{
    corto_bool result = TRUE;

    /* Filter name */
    if (frame->filter) {
        corto_id filterLc, nameLc;

        strcpy(filterLc, frame->filter);
        strcpy(nameLc, corto_idof(o));
        corto_strlower(filterLc);
        corto_strlower(nameLc);

        result = !fnmatch(filterLc, nameLc, 0);
    }

    /* Check if there are SINK mounts active for the current scope */
    if (result && corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        corto_int32 i;
        corto_id type; corto_fullpath(type, corto_typeof(o));
        for (i = 0; i < data->activeReplicators; i++) {
            corto_mount r = data->mounts[i].r;

            /* If a SINK mount doesn't return a valid iterator, which typically
             * happens if it doesn't implement the onRequest method, select will
             * return the contents of the object store */
            if ((r->kind == CORTO_SINK) && data->mounts[i].iter.next) {
                if (r->type) {
                    /* If the type matches, the object is managed by the
                     * mount. This prevents returning duplicate results. */
                    if (!strcmp(r->type, type)) {
                        result = FALSE;
                        break;
                    }
                } else {
                    /* A SINK mount that has no type specified blocks
                     * everything */
                    result = FALSE;
                    break;
                }
            }
        }
    }

    return result;
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
            if (stricmp(corto_idof(o), lastKey) > 0) {
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
            corto_cleanpath(parent, parent);
        } else if (!*parent) {
            strcpy(parent, ".");
        }
    } else {
        if (!*parent) strcpy(parent, ".");
        strcpy(expr, "*");
    }
}

static corto_resultIter corto_selectRequestReplicator(
    corto_mount mount,
    corto_string parent,
    corto_string expr,
    corto_selectData *data)
{
    corto_request r = {
      parent,
      expr,
      (data->offset > data->count) ? data->offset - data->count : 0,
      (data->offset > data->count) ? data->limit : data->limit - (data->offset - data->count),
      data->contentType ? TRUE : FALSE,
      data->param};

    return corto_mount_request(mount, &r);
}

/* Function returns TRUE if a SINK is found, which means that for this scope
 * the object store should not be walked (or specific types should not be
 * walked) */
static void corto_selectRequestReplicators(
    corto_selectData *data,
    corto_selectStack *frame,
    corto__scope *scope,
    corto_bool dryRun)
{
    if (data->activeReplicators < 0) {
        corto_bool releaseScope = FALSE;
        corto_bool requestStart = 0;

        data->activeReplicators = 0;

        /* 1: Count mounts registered on parent scopes */
        while (data->mounts[data->activeReplicators].r) {
            data->activeReplicators ++;
            requestStart = data->activeReplicators;
        }

        /* 2: Request data from mounts registered on current scope */
        if (!scope) {
            scope = corto__scopeClaim(frame->scope);
            releaseScope = TRUE;
        }

        corto__ols *ols = corto_olsFind(scope, CORTO_OLS_REPLICATOR);

        if (ols) {
            corto_ll mounts = ols->value;
            if (mounts) {
                corto_iter iter = corto_llIter(mounts);

                while (corto_iterHasNext(&iter)) {
                    corto_mount_olsData_t *odata = corto_iterNext(&iter);

                    /* If required, load mount content type */
                    if (data->contentType && odata->mount->contentType) {
                        if (strcmp(
                              data->contentType,
                              odata->mount->contentType))
                        {
                            if (corto_loadContentType(
                                &data->srcSer[data->activeReplicators],
                                odata->mount->contentType))
                            {
                                corto_error("contentType '%s' for %s not found",
                                  odata->mount->contentType,
                                  corto_fullpath(NULL, corto_typeof(odata->mount)));

                                /* Ignore mount */
                                continue;
                            }
                        }
                    }

                    data->mounts[data->activeReplicators].r = odata->mount;
                    data->activeReplicators ++;
                }
            }
        }

        if (releaseScope) {
            corto__scopeRelease(frame->scope);
        }

        /* Request data outside of lock */
        if (!dryRun) {
            corto_int32 i;
            for (i = requestStart; i < data->activeReplicators; i++) {
                corto_id parent, expr;
                corto_path(parent, data->mounts[i].r->mount, frame->scope, "/");
                if (frame->scopeQuery) {
                    if (parent[0]) {
                        strcat(parent, "/");
                    }
                    strcat(parent, frame->scopeQuery);
                }

                corto_selectParseFilter(frame->filter, parent, expr);
                corto_cleanpath(parent, parent);

                data->mounts[i].iter = corto_selectRequestReplicator(
                    data->mounts[i].r,
                    parent,
                    expr,
                    data);
            }
        }
    }

    if (data->activeReplicators == 0) {
        data->activeReplicators = -1;
    }
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

        while (!data->mounts[data->currentReplicator].iter.hasNext) {
            data->currentReplicator ++;
        }

        /* Walk over iterators until one with data available has been found */
        while ((data->currentReplicator < data->activeReplicators)) {
            corto_resultIter *iter = &data->mounts[data->currentReplicator].iter;

            while (corto_iterHasNext(iter)) {
                corto_result *result = corto_iterNext(iter);
                if (!result) {
                    corto_error("mount returned NULL result");
                    continue;
                }

                data->next = &data->item;
                data->count ++;

                /* Copy data, so mount can safely release it */
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

                    strcpy(path, data->scope ? data->scope : "");
                    corto_fullpath(rpath, frame->scope);
                    strcat(rpath, "/");
                    strcat(rpath, parent);
                    strcat(rpath, "/");
                    strcat(rpath, result->parent);
                    corto_cleanpath(rpath, rpath);

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
        frame->filter = frame->scopeQuery;
        frame->scopeQuery = NULL;
        corto_selectRequestReplicators(data, frame, NULL, FALSE);
        corto_selectIterateReplicators(data, frame);
    } else {
        /* Ensure that SINK mounts are loaded so any filters will be
         * correctly applied by corto_selectMatch */

         /* Set scope to parent of scope to ensure that mounts for the
          * parent scope are loaded, not the ones for the current object */
        corto_object o = frame->scope;
        frame->scope = corto_parentof(frame->scope);
        if (frame->scope) {
            corto_selectRequestReplicators(data, frame, NULL, TRUE);
        }
        if (!data->next) {
            if (!frame->scope || corto_selectMatch(frame, o, data)) {
                data->next = &data->item;
                corto_setItemData(o, data->next, data);
            }
            frame->scope = o;

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

    /* Request mounts once per scope, and do it before iterating over
     * corto store objects so mounts have more time to fetch data. */
    corto_selectRequestReplicators(data, frame, NULL, FALSE);

    corto__scopeClaim(frame->scope);
    data->next = NULL;


    /* If not iterating over a mount, iterate over the store */
    if ((data->currentReplicator == -1) &&
        !data->scopes[data->currentScope].scopeQuery)
    {
        while ((o = corto_selectIterNext(frame, lastKey))) {
            if (corto_selectMatch(frame, o, data)) {
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

    /* Handle mount iteration outside of scope lock */
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

    /* Request mounts once per scope, and do it before iterating over
     * corto store objects so mounts have more time to fetch data. */
    corto_selectRequestReplicators(data, frame, NULL, TRUE);

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
                strcpy(data->item.name, corto_idof(frame->scope));
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

            noMatch = (frame->filter &&
                (data->next && !corto_selectMatch(frame, o, data)));

            if (!noMatch) {
                data->count ++;
                if (data->count <= data->offset) {
                    noMatch = TRUE;
                }
            }
        } while (noMatch);
    }

    /* Handle mount iteration outside of scope lock */
    if (!data->next) {
        corto_selectIterateReplicators(data, frame);
    }
}

/* Reset select data (either initially or when moving to next scope) */
static void corto_selectReset(corto_selectData *data) {
    corto_int32 i = 0;

    for (i = 0; i < data->activeReplicators; i ++) {
        corto_iterRelease(&data->mounts[i].iter);
        data->mounts[i].iter.hasNext = NULL;
    }

    if (data->item.value && data->destSer.contentRelease) {
        data->destSer.contentRelease(data->item.value);
    }

    if (data->stack[0].scopeQuery) {
        if (data->stack[0].scopeQuery !=
             data->scopes[data->currentScope].scopeQuery)
        {
            corto_dealloc(data->stack[0].scopeQuery);
            data->stack[0].scopeQuery = NULL;
        }
    }

    data->sp = 0;
    data->item.value = 0;
    data->activeReplicators = -1;
    data->currentReplicator = -1;
}

static void corto_selectPrepareFrame(
    corto_selectData *data,
    corto_selectStack *frame,
    corto_uint32 currentScope)
{
    frame->scope = data->scopes[currentScope].scope;
    frame->scopeQuery = data->scopes[currentScope].scopeQuery;

    corto_rbtree tree = corto_scopeof(frame->scope);
    if (tree) {
        frame->iter = _corto_rbtreeIter(tree, &frame->trav);
    } else {
        memset(&frame->iter, 0, sizeof(corto_iter));
    }
}

/* When moving to the next scope element, filter out active mounts that
 * don't operate on a tree, as they don't contain relevant data for
 * a child scope. */
static void corto_selectFilterReplicators(corto_selectData *data) {
    corto_int32 i = 0;
    for (i = 0; i < data->activeReplicators; i ++) {
        if (!(data->mounts[i].r->mask & CORTO_ON_TREE)) {
            if (i == (data->activeReplicators - 1)) {
                data->mounts[i].r = NULL;
            } else {
                /* Don't move whole array forward, just move the last mount
                 * to the current position in the array. A user should make no
                 * assumptions on in which order mounts are invoked */
                data->mounts[i].r =
                  data->mounts[data->activeReplicators - 1].r;
                data->mounts[data->activeReplicators - 1].r = NULL;
            }
            data->activeReplicators --;
        }
    }
}

static corto_bool corto_selectNextScope(corto_selectData *data) {
    if (data->scopes[data->currentScope + 1].scope) {
        corto_selectStack *frame = &data->stack[0];

        /* Only continue if previous scope didn't return a single object, in
         * which case 'next' will have been set to NULL */
        if (frame->next) {
            corto_selectFilterReplicators(data);
            corto_selectReset(data);
            corto_selectPrepareFrame(data, frame, ++data->currentScope);
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
    if (data->fullscope) corto_dealloc(data->fullscope);

    corto_selectReset(data);

    data->expr = NULL;
    data->tokens = NULL;
    data->item.value = 0;
    corto_dealloc(data);
}

/* Split up scope expression in object/string pairs so mounts are invoked
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

    char *ptr, *prev, ch;
    corto_uint32 current = 0;
    ptr = data->fullscope;

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
                 * will attempt to request it from mounts */
                break;
            } else {
                data->scopes[current].scopeQuery = *ptr ? ptr + 1 : NULL;
            }

            prev = ptr + (*ptr ? 1 : 0);
            current++;
        }
        ptr++;
    } while (ch);

    return 0;
}

/* Combine expression and scope */
static corto_int16 corto_selectRun(corto_selectData *data) {
    corto_int32 op;
    corto_bool quit = FALSE;
    corto_id fullscope;
    corto_string filter = NULL;
    corto_selectStack *frame = &data->stack[0];

    strcpy(fullscope, data->scope ? data->scope : "/");
    frame->next = corto_selectScope;

    if (*fullscope && strcmp(fullscope, "/")) {
        strcat(fullscope, "/");
    }

    for (op = 0; (op < data->programSize) && !quit; op ++) {
        switch (data->program[op].token) {
        case TOKEN_FILTER:
            quit = TRUE;
            break;
        case TOKEN_IDENTIFIER:
            frame->next = corto_selectThis;
            strcat(fullscope, data->program[op].start);
            break;
        case TOKEN_THIS:
            strcat(fullscope, ".");
            frame->next = corto_selectThis;
            break;
        case TOKEN_PARENT:
            strcat(fullscope, "..");
            frame->next = corto_selectThis;
            break;
        case TOKEN_SCOPE:
            strcat(fullscope, "/");
            frame->next = corto_selectScope;
            break;
        case TOKEN_TREE:
            frame->next = corto_selectTree;
            op ++; /* The filter, if provided, is in next token */
        default:
            quit = TRUE;
            break;
        }
    }

    corto_cleanpath(fullscope, fullscope);
    corto_setstr(&data->fullscope, fullscope);

    if (quit) {
        filter = data->program[op - 1].start;
    }

    if (corto_selectSplitScope(data)) {
        goto error;
    }

    /* Prepare first frame */
    corto_selectPrepareFrame(data, frame, 0);
    frame->filter = filter;

    return 0;
error:
    return -1;
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

    if (corto_selectRun(data)) {
        goto error;
    }

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

static corto_resultIter corto_selectorIter(corto_int16 *ret)
{
    corto_resultIter result = {NULL};

    if (ret) *ret = 0;

    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_SELECT);
    if (request) {
        result = corto_selectPrepareIterator(request);
        if (request->err && ret) {
            *ret = -1;
        }
    }
    return result;
}

static corto_selectSelector corto_selectSelectorGet(void)
{
    corto_selectSelector result;
    result.contentType = corto_selectorContentType;
    result.limit = corto_selectorLimit;
    result.augment = corto_selectorAugment;
    result.iter = corto_selectorIter;
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
