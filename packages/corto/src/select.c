
#include "corto/corto.h"
#include "_object.h"
#include "_matcher.h"

extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_int8 CORTO_OLS_AUGMENT;
extern corto_threadKey CORTO_KEY_FLUENT;

struct corto_selectData;

/* Fluent request */
typedef struct corto_selectRequest {
    corto_int16 err;
    corto_string scope;
    corto_string expr;
    corto_string type;
    corto_uint64 offset;
    corto_uint64 limit;
    corto_string augment;
    corto_string contentType;
    corto_frame from;
    corto_frame to;
} corto_selectRequest;

typedef struct corto_selectStack {
    corto_object scope; /* Object of whose scope is being iterated */
    corto_string scopeQuery; /* String remainder of scope to be iterated */
    jsw_rbtrav_t trav; /* Persistent tree iterator */
    corto_iter iter;
    corto_string filter;

    corto_int32 recursiveQueryLength; /* Restore query when leaving frame */
    corto_uint8 firstMount; /* First mount loaded for frame */
    corto_int8 currentMount; /* Current mount being evaluated */

    /* Callback for either returning single object, traversing
     * scope or traversing a tree. */
    void (*next)(struct corto_selectData *data,
        struct corto_selectStack *frame);
} corto_selectStack;

typedef struct corto_scopeSegment {
    corto_object scope;
    corto_string scopeQuery;
} corto_scopeSegment;

typedef struct corto_selectData {
    corto_string scope;                      /* Scope passed to select */
    corto_string expr;                       /* Current expression */
    corto_string exprStart;                  /* Points to start of full expr */
    corto_string contentType;

    /* Which expression is being evaluated (when expression contains ,) */
    corto_uint32 exprCount;
    corto_uint32 exprCurrent;

    corto_string fullscope;                  /* Scope + scope part of expression */
    corto_scopeSegment scopes[CORTO_MAX_SCOPE_DEPTH]; /* Scopes to walk (parsed scope) */
    corto_uint32 currentScope;               /* Scope currently being walked */

    struct corto_matchProgram_s program;   /* Parsed program */

    corto_selectStack stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    corto_uint8 sp;
    corto_eventMask mask;

    /* Mounts currently loaded */
    corto_mount mounts[32];

    /* Mounts with outstanding requests */
    corto_int8 mountsLoaded;

    /* Serializer for requested content type */
    corto_contentType dstSer;

    /* Limit results */
    corto_uint64 offset;
    corto_uint64 limit;
    corto_uint64 count;

    /* History */
    corto_frame from;
    corto_frame to;

    /* Filters */
    corto_string typeFilter;
    corto_string augmentFilter;

    /* Query for recursive queries on mounts */
    corto_id recursiveQuery;

    /* Pre allocated for selectItem */
    corto_id id;
    corto_id name;
    corto_id parent;
    corto_id type;
    corto_augmentData augmentBuffer[CORTO_MAX_AUGMENTS];
    corto_result item;
    corto_result *next;
} corto_selectData;

static corto_word corto_selectConvert(
    corto_selectData *data,
    corto_string type,
    corto_word value)
{
    corto_word result = 0;

    corto_contentType srcType = (corto_contentType)
      corto_subscriber(data->mounts[data->stack[data->sp].currentMount - 1])->contentTypeHandle;

    /* If source serializer is loaded, a conversion is
     * needed */
    if (srcType) {
        corto_object t = corto_resolve(NULL, type);
        if (!t) {
            corto_seterr("unresolved type '%s'", type);
            goto error;
        } else {
            corto_object o = corto_create(t);

            /* Convert from source format to object */
            if (srcType->toCorto(o, value)) {
                corto_seterr("failed to convert value to '%s' (%s)",
                    type,
                    corto_lasterr());
                goto error;
            }

            /* Convert from object to destination format */
            if (!(result = data->dstSer->fromCorto(o))) {
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
                            parent, expr, data->type, 0, 1, data->contentType == NULL, {0,0}, {0,0}
                        };

                        augmentIt = corto_mount_request(
                          ols->mount,
                          &r);

                        /* Expecting a single result */
                        if (augmentIt.hasNext(&augmentIt)) {
                            corto_result *result = augmentIt.next(&augmentIt);
                            if (result) {
                                if (augment->data) {
                                    data->dstSer->release(augment->data);
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

char* corto_pathstr(
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
        corto_path(to, NULL, corto_parentof(o), "/");
    } else {
        /* Avoid the parent string from navigating beyond the root */
        corto_path(to, NULL, o, "/");
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

    item->mount = corto_ownerof(o);

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
            data->dstSer->release(item->value);
        }
        item->value = data->dstSer->fromCorto(o);
    }

    item->mount = NULL;
    item->leaf = corto_scopeSize(o) == 0;
}

static corto_bool corto_selectMatch(
    corto_selectStack *frame,
    corto_object o,
    corto_selectData *data)
{
    corto_bool result = TRUE;
    char *id = o ? corto_idof(o) : data->item.id;

    if (o) {
        if (!corto_authorized(o, CORTO_SECURE_ACTION_READ)) {
            goto access_error;
        }
    } else {
        corto_id id;
        sprintf(id, "%s/%s", data->item.parent, data->item.id);
        corto_cleanpath(id, id);
        if (!corto_authorizedId(id, CORTO_SECURE_ACTION_READ)) {
            goto access_error;
        }
    }

    /* Filter name */
    if (frame->filter) {
        corto_id filterLc, nameLc;

        strcpy(filterLc, frame->filter);
        strcpy(nameLc, id);
        corto_strlower(filterLc);
        corto_strlower(nameLc);

        result = corto_match(filterLc, nameLc);
    }

    /* Check if there are SINK mounts active for the current scope */
    if (result) {
        corto_id type;
        if (o) {
            corto_fullpath(type, corto_typeof(o));
        } else {
            strcpy(type, data->item.type);
        }

        /* Only filter (duplicate) results from the object store */
        if (o) {
            corto_int32 i;

            for (i = 0; i < data->mountsLoaded; i++) {
                corto_mount r = data->mounts[i];
                corto_string rType = corto_observer(r)->type;

                /* If a SINK mount doesn't return a valid iterator, which typically
                 * happens if it doesn't implement the onRequest method, select will
                 * return the contents of the object store */
                if ((r->kind == CORTO_SINK) && !r->passThrough) {
                    if (rType) {
                        /* If the type matches, the object is managed by the
                         * mount. This prevents returning duplicate results. */
                        if (!strcmp(rType, type)) {
                            result = FALSE;
                            break;
                        } else {
                            continue;
                        }
                    } else {
                        /* A SINK mount that has no type specified blocks
                         * everything */
                        result = FALSE;
                        break;
                    }

                    /* Do the same for attributes */
                    if (o && r->attr) {
                        if (corto_checkAttr(o, r->attr)) {
                            result = FALSE;
                            break;
                        } else {
                            continue;
                        }
                    } else {
                        result = FALSE;
                        break;
                    }
                }
            }
        }

        /* Filter type */
        if (result && data->typeFilter) {
            result = corto_match(data->typeFilter, type);
        }
    }

    if (result) {
        data->count ++;
    }

    return result;
access_error:
    return FALSE;
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

static corto_resultIter corto_selectRequestMount(
    corto_selectData *data,
    corto_selectStack *frame,
    corto_mount mount)
{
    corto_id parent, filter, expr;
    corto_int32 sp = data->sp;

    while (!data->stack[sp].scope) {
        sp --;
    }
    corto_path(parent, mount->mount, data->stack[sp].scope, "/");

    if (!frame->scope) {
        /* Recursively search in mount */
        strcat(parent, data->recursiveQuery);
    }

    filter[0] = '\0';
    if (frame->scopeQuery) {
        strcat(parent, "/");
        strcat(parent, frame->scopeQuery);
    }
    if (frame->filter) {
        strcat(filter, frame->filter);
    }

    corto_selectParseFilter(filter, parent, expr);

    if (data->mask == CORTO_ON_TREE) {
        strcpy(expr, "*");
    }

    corto_cleanpath(parent, parent);

    corto_debug("corto: select: RequestMount: request '%s' (%s), parent='%s', expr='%s'",
      corto_fullpath(NULL, mount),
      corto_fullpath(NULL, corto_typeof(mount)),
      parent,
      expr);

    corto_request r = {
      parent,
      expr,
      data->type,
      (data->offset > data->count) ? data->offset - data->count : 0,
      (data->offset > data->count) ? data->limit : data->limit - (data->offset - data->count),
      data->contentType ? TRUE : FALSE,
      data->from,
      data->to};

    return corto_mount_request(mount, &r);
}

static corto_int16 corto_selectIterMount(
    corto_selectData *data,
    corto_selectStack *frame)
{
    corto_id parent, expr;

    /* Parse filter into parent and expression */
    if (frame->scopeQuery) {
        strcpy(parent, frame->scopeQuery);
    } else {
        *parent = '\0';
    }

    corto_selectParseFilter(frame->filter, parent, expr);

    corto_result *result = corto_iterNext(&frame->iter);
    if (!result) {
        corto_error("mount iterator returned NULL");
        goto error;
    }

    corto_debug(
        "corto: select: IterMount: returned '%s, %s' (recursiveQuery = %s)",
        result->id, result->parent, data->recursiveQuery);

    data->next = &data->item;

    data->item.mount = data->mounts[frame->currentMount - 1];
    data->item.leaf = result->leaf;

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

    if (result->parent) {
        corto_id path, rpath;

        strcpy(path, data->scope ? data->scope : "");
        if (frame->scope) {
            corto_fullpath(rpath, frame->scope);
        } else {
            corto_fullpath(rpath, data->mounts[frame->currentMount - 1]->mount);
        }
        strcat(rpath, "/");
        strcat(rpath, parent);
        strcat(rpath, data->recursiveQuery);
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
        /* Convert value */
        data->dstSer->release(data->item.value);
        data->item.value = corto_selectConvert(
          data, result->type, result->value);

        /* Convert history */
        if (data->item.history.length) {
            corto_int32 i = 0;
            for (i = 0; i < data->item.history.length; i++) {
                data->dstSer->release(data->item.history.buffer[i]);
            }
        }
        if (data->item.history.length != result->history.length) {
            data->item.history.buffer = corto_realloc(
              data->item.history.buffer,
              result->history.length * sizeof(corto_word));
            data->item.history.length = result->history.length;
        }
        if (result->history.length) {
            corto_int32 i = 0;
            for (i = 0; i < result->history.length; i++) {
                data->item.history.buffer[i] = corto_selectConvert(
                  data, result->type, result->history.buffer[i]);
            }
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

    return 0;
error:
    return -1;
}

static corto_bool corto_selectIterNext(
    corto_selectData *data,
    corto_selectStack *frame,
    corto_object *o_out,
    corto_string lastKey)
{
    corto_bool hasData = FALSE;

    corto_debug("corto: select: IterNext: scope=%s, filter=%s, scopeQuery=%s, currentMount=%d, firstMount=%d, mountsLoaded=%d",
        corto_fullpath(NULL, frame->scope),
        frame->filter,
        frame->scopeQuery,
        frame->currentMount,
        frame->firstMount,
        data->mountsLoaded);

    /* Select data from scope */
    if (frame->scope) {

        /* Don't walk over objects if a frame contains a scopeQuery or if the
         * frame is already walking over a mount */
        if (!frame->scopeQuery && (frame->currentMount == frame->firstMount)) {
            corto_object result = NULL;

            corto__scopeClaim(frame->scope);

            if ((data->mask == CORTO_ON_SELF) && !frame->filter) {
                result = frame->scope;
            } else {

                /* When scope has changed, iterator becomes invalid. Re-obtain
                 * iterator and move to value that was last iterated over + 1.
                 * This prevents to either having to lock the scope / store all
                 * results in a temporary list. */
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
            }
            if (o_out) {
                *o_out = result;
            }
            if (result) {
                hasData = TRUE;
                corto_claim(result);
            }
            corto__scopeRelease(frame->scope);
        }

        /* If no data was found in scope, and frame has unevaluated mounts,
         * request data from mounts. */
        if (!hasData && data->mountsLoaded && (data->mountsLoaded > frame->firstMount)) {
            if (frame->currentMount == frame->firstMount) {
                frame->currentMount ++;
                frame->iter = corto_selectRequestMount(
                  data, frame, data->mounts[frame->currentMount - 1]);
            }

            while (!(hasData = corto_iterHasNext(&frame->iter)) && (frame->currentMount < data->mountsLoaded)) {
                frame->currentMount ++;
                frame->iter = corto_selectRequestMount(
                  data, frame, data->mounts[frame->currentMount - 1]);
            }

            if (hasData) {
                corto_selectIterMount(data, frame);
            }
        }
    } else {
        if ((hasData = corto_iterHasNext(&frame->iter))) {
            corto_selectIterMount(data, frame);
        }
    }

    if (hasData && (data->mask == CORTO_ON_SELF)) {
        data->mask = 0;
    }

    corto_debug("corto: select: IterNext: hasData = %d, currentMount = %d", hasData, frame->currentMount);

    return hasData;
}

/* Load mounts for a scope */
static void corto_selectLoadMounts(
    corto_selectData *data,
    corto_selectStack *frame,
    corto__scope *scope)
{
    corto_bool releaseScope = FALSE;

    data->mountsLoaded = 0;

    /* 1: Count mounts registered on parent scopes */
    while (data->mounts[data->mountsLoaded]) {
        data->mountsLoaded ++;
    }

    frame->currentMount = data->mountsLoaded;
    frame->firstMount = data->mountsLoaded;

    /* 2: Lock scope and get replicators */
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

                /* If historical data is requested, only request from
                 * historians and vice versa. */
                if (memcmp(&data->from, &data->to, sizeof(corto_frame))) {
                    if (odata->mount->kind != CORTO_HISTORIAN) {
                        continue;
                    }
                } else if (odata->mount->kind == CORTO_HISTORIAN) {
                    continue;
                }

                /* If type is requested, test whether it is compatible with
                 * the type of the mount */
                corto_string rType = corto_observer(odata->mount)->type;
                if (data->typeFilter && rType) {
                    if (!corto_match(data->typeFilter, rType)) {
                        continue;
                    }
                }

                data->mounts[data->mountsLoaded] = odata->mount;
                data->mountsLoaded ++;

                corto_debug("corto: select: LoadMounts: load '%s', type = %s, mountsLoaded = %d",
                  corto_fullpath(NULL, odata->mount),
                  corto_fullpath(NULL, corto_typeof(odata->mount)),
                  data->mountsLoaded);
            }
        }
    }

    /* Unlock scope */
    if (releaseScope) {
        corto__scopeRelease(frame->scope);
    }
}

/* Depth first search */
static void corto_selectTree(
    corto_selectData *data,
    corto_selectStack *frame)
{
    /* Keep track of the last key for when a tree changed while iterating over
     * it. When a change occurred, the iterator's current position can be no
     * longer valid. corto_selectIterNext will in that case iterate up to the
     * object after the last key. */
    corto_string lastKey = data->item.name;
    corto_bool noMatch = TRUE;

    corto_debug("corto: select: Tree %d='%s': filter = %s, scopeQuery = %s",
      data->sp, corto_fullpath(NULL, frame->scope), frame->filter, frame->scopeQuery);

    data->next = NULL;

    corto_object o = NULL;

    do {
        corto_bool leaf = TRUE, hasData = FALSE;

        /* Unwind stack for depleted iterators */
        while (!(hasData = corto_selectIterNext(data, frame, &o, lastKey)) && data->sp) {
            /* Cache name as next line might delete object */
            if (frame->scope) {
                strcpy(data->item.name, corto_idof(frame->scope));
                corto_setref(&frame->scope, NULL);
            }
            data->sp --;
            data->mountsLoaded = frame->firstMount;
            data->recursiveQuery[frame->recursiveQueryLength] = '\0';
            frame = &data->stack[data->sp];
        }

        if (hasData) {
            data->next = &data->item;

            if (o) {
                if (corto_selectMatch(frame, o, data) &&
                   (data->count > data->offset))
                {
                    noMatch = FALSE;
                    corto_setItemData(o, data->next, data);
                }
                leaf = FALSE;
                data->recursiveQuery[0] = '\0';
            } else {
                /* If doing a lookup on a tree, select requests all objects from
                 * a mount and thus needs to perform matching. If not, select
                 * will pass the filter to the mount, and the mount is expected
                 * to only return matching objects. */
                if (data->mask != CORTO_ON_TREE) {
                    noMatch = FALSE;
                } else {
                    noMatch = !corto_selectMatch(frame, NULL, data);
                }
                leaf = data->next->leaf;
            }

            /* Prepare next frame if object has scope */
            if (!leaf && (data->mask == CORTO_ON_TREE)) {
                corto_debug("corto: select: Tree push '%s'",
                    frame->scope ? corto_fullpath(NULL, frame->scope) : data->next->id);

                corto_selectStack *prevFrame = frame;
                frame = &data->stack[++ data->sp];
                frame->recursiveQueryLength = strlen(data->recursiveQuery);
                frame->firstMount = data->mountsLoaded;
                frame->currentMount = frame->firstMount;

                corto_setref(&frame->scope, o);
                if (o) {
                    corto_rbtree scope = corto_scopeof(o);
                    if (scope) {
                        frame->iter = _corto_rbtreeIter(scope, &frame->trav);
                    }
                    corto_selectLoadMounts(data, frame, NULL);
                } else {
                    frame->currentMount = prevFrame->currentMount;
                    if (prevFrame->scopeQuery) {
                        strcat(data->recursiveQuery, "/");
                        strcat(data->recursiveQuery, prevFrame->scopeQuery);
                    }
                    strcat(data->recursiveQuery, "/");
                    strcat(data->recursiveQuery, data->item.name);
                    frame->iter = corto_selectRequestMount(
                      data, frame, data->mounts[frame->currentMount - 1]);
                }
                frame->filter = data->stack[data->sp - 1].filter;
                frame->next = corto_selectTree;
            }
        } else {
            data->next = NULL;
        }

        if (o) corto_release(o);
    } while (noMatch && data->next);
}

/* Reset select data (either initially or when moving to next scope) */
static void corto_selectReset(corto_selectData *data) {
    if (data->item.value && data->dstSer->release) {
        data->dstSer->release(data->item.value);
    }

    if (data->item.history.length) {
        corto_int32 i;
        for (i = 0; i < data->item.history.length; i ++) {
            data->dstSer->release(data->item.history.buffer[i]);
        }
        corto_dealloc(data->item.history.buffer);
        data->item.history.length = 0;
        data->item.history.buffer = NULL;
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
    data->mountsLoaded = -1;
}

static void corto_selectPrepareFrame(
    corto_selectData *data,
    corto_selectStack *frame,
    corto_uint32 currentScope)
{
    frame->scope = data->scopes[currentScope].scope;
    frame->scopeQuery = data->scopes[currentScope].scopeQuery;
    frame->currentMount = 0;
    frame->firstMount = 0;

    corto_rbtree tree = corto_scopeof(frame->scope);
    if (tree) {
        frame->iter = _corto_rbtreeIter(tree, &frame->trav);
    } else {
        memset(&frame->iter, 0, sizeof(corto_iter));
    }

    corto_selectLoadMounts(data, frame, NULL);
}

/* When moving to the next scope element, filter out active mounts that
 * don't operate on a tree, as they don't contain relevant data for
 * a child scope. The remaining mounts are used to evaluate whether a SINK is
 * active for a scope, in which case objects must be masked. */
static void corto_selectFilterMounts(corto_selectData *data) {
    corto_int32 i = 0;
    for (i = 0; i < data->mountsLoaded; i ++) {
        if (!(data->mounts[i]->mask & CORTO_ON_TREE)) {
            if (i == (data->mountsLoaded - 1)) {
                data->mounts[i] = NULL;
            } else {
                /* Don't move whole array forward, just move the last mount
                 * to the current position in the array. A user should make no
                 * assumptions on in which order mounts are invoked */
                data->mounts[i] =
                  data->mounts[data->mountsLoaded - 1];
                data->mounts[data->mountsLoaded - 1] = NULL;
            }
            data->mountsLoaded --;
        }
    }
}

static void* corto_selectNext(corto_resultIter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    if (data->next) {
        corto_debug("corto: select: Next (%s, %s)", data->next->id, data->next->parent);
    }

    return data->next;
}

static void corto_selectRelease(corto_iter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    if (data->exprStart) corto_dealloc(data->exprStart);
    if (data->program.tokens) corto_dealloc(data->program.tokens);
    if (data->scope) corto_dealloc(data->scope);
    if (data->fullscope) corto_dealloc(data->fullscope);

    corto_selectReset(data);

    data->expr = NULL;
    data->program.tokens = NULL;
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
 * Mounts registered for /, /a, /a/b and /a/b/c will be invoked with the
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
    corto_uint8 quit = 0;
    corto_id fullscope;
    corto_string filter = NULL;
    corto_selectStack *frame = &data->stack[0];

    strcpy(fullscope, data->scope ? data->scope : "/");
    frame->next = corto_selectTree;
    data->mask = CORTO_ON_SCOPE;

    if (*fullscope && strcmp(fullscope, "/") && (*data->expr != '/')) {
        strcat(fullscope, "/");
    }

    strcat(fullscope, data->expr ? data->expr : "");

    for (op = 0; (op < data->program.size) && !quit; op ++) {
        switch (data->program.ops[op].token) {
        case CORTO_MATCHER_TOKEN_IDENTIFIER:
        case CORTO_MATCHER_TOKEN_THIS:
        case CORTO_MATCHER_TOKEN_PARENT:
            data->mask = CORTO_ON_SELF;
            break;
        case CORTO_MATCHER_TOKEN_SCOPE:
            data->mask = CORTO_ON_SCOPE;
            break;
        case CORTO_MATCHER_TOKEN_TREE:
            data->mask = CORTO_ON_TREE;
        default:
            quit = TRUE;
            break;
        }
    }

    corto_setstr(&data->fullscope, fullscope);
    corto_cleanpath(data->fullscope, data->fullscope);

    /* Does expression contain a filter? */
    if (data->expr && (data->expr[strlen(data->expr) - 1] != '/')) {
        char *ptr = strrchr(data->fullscope, '/');
        if (ptr) {
            filter = ptr + 1;
            if (!*filter) {
                filter = NULL;
            }
            *ptr = '\0';
        }
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

static corto_bool corto_selectNextScope(corto_selectData *data) {
    if (data->scopes[data->currentScope + 1].scope) {
        corto_selectStack *frame = &data->stack[0];
        corto_selectFilterMounts(data);
        corto_selectReset(data);
        corto_selectPrepareFrame(data, frame, ++data->currentScope);
        corto_debug("corto: select: NextScope: '%s, %s', currentMount=%d, firstMount=%d",
            corto_fullpath(NULL, data->scopes[data->currentScope].scope),
            data->scopes[data->currentScope].scopeQuery,
            frame->currentMount,
            frame->firstMount);
        return TRUE;
    }
    return FALSE;
}

static corto_bool corto_selectNextExpr(corto_selectData *data) {
    corto_bool result = FALSE;

    if (data->exprCurrent < data->exprCount) {
        data->expr = &data->expr[strlen(data->expr) + 1];
        data->exprCurrent ++;
        result = TRUE;

        corto_selectReset(data);
        data->currentScope = 0;

        if (data->program.tokens) corto_dealloc(data->program.tokens);
        if (corto_matchProgramParseIntern(&data->program, data->expr, TRUE, FALSE)) {
            corto_error("select '%s' failed: %s", data->expr, corto_lasterr());
            goto error;
        }

        if (corto_selectRun(data)) {
            corto_error("select '%s' failed: %s", data->expr, corto_lasterr());
            goto error;
        }
    }

    return result;
error:
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
              goto stop;
         }
    }

    if (!data->mask) {
        if (!corto_selectNextExpr(data)) {
            goto stop;
        }
    }

    do {
        corto_selectTree(data, frame);
    } while ((data->next == NULL) && (corto_selectNextScope(data)));

    return data->next != NULL;
stop:
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
    data->exprStart = data->expr;

    data->contentType = r->contentType;
    data->mountsLoaded = -1;
    data->offset = r->offset;
    data->limit = r->limit;
    data->augmentFilter = r->augment;
    data->typeFilter = r->type;
    data->from = r->from;
    data->to = r->to;
    data->item.parent = data->parent;
    data->item.name = data->name;
    data->item.type = data->type;
    data->item.id = data->id;
    data->item.leaf = TRUE;

    if (data->contentType) {
        if (!(data->dstSer = corto_loadContentType(data->contentType))) {
            goto error;
        }
    }

    result.udata = data;
    result.hasNext = corto_selectHasNext;
    result.next = corto_selectNext;
    result.release = corto_selectRelease;

    /* Split expression on ,. Expressions with multiple segments should be
     * evaluated sequentially. */
    char *ptr = data->expr;
    while ((ptr = strchr(ptr, ','))) {
        *ptr = '\0';
        ptr++;
        data->exprCount ++;
    }
    data->exprCurrent = 0;

    if (corto_matchProgramParseIntern(&data->program, data->expr, TRUE, FALSE)) {
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

static corto_selectFluent corto_selectFluentGet(void);

static corto_selectFluent corto_selectorContentType(
    corto_string contentType)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorLimit(
    corto_uint64 offset,
    corto_uint64 limit)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->offset = offset;
        request->limit = limit;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorType(
    corto_string type)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorAugment(
    corto_string augment)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->augment = augment;
    }
    return corto_selectFluentGet();
}

static corto_int16 corto_selectorIter(corto_resultIter *ret)
{
    corto_assert(ret != NULL, "no iterator provided to .iter()");

    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        corto_threadTlsSet(CORTO_KEY_FLUENT, NULL);
        *ret = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);
    }

    return 0;
error:
    return -1;
}

static corto_selectFluent corto_selectorFromNow(void)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorFromTime(corto_time t)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_TIME;
        union {
            corto_time t;
            corto_uint64 i;
        } toInt;
        toInt.t = t;
        request->from.value = toInt.i;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorFromSample(corto_uint64 sample)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_SAMPLE;
        request->from.value = sample;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorToNow(void)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorToTime(corto_time t)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_TIME;
        union {
            corto_time t;
            corto_uint64 i;
        } toInt;
        toInt.t = t;
        request->to.value = toInt.i;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorToSample(corto_uint64 sample)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_SAMPLE;
        request->to.value = sample;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorForDuration(corto_time t)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_DURATION;
        union {
            corto_time t;
            corto_uint64 i;
        } toInt;
        toInt.t = t;
        request->to.value = toInt.i;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorForDepth(corto_int64 depth)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_DEPTH;
        request->to.value = depth;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectFluentGet(void)
{
    corto_selectFluent result;
    result.contentType = corto_selectorContentType;
    result.limit = corto_selectorLimit;
    result.type = corto_selectorType;
    result.augment = corto_selectorAugment;
    result.fromNow = corto_selectorFromNow;
    result.fromTime = corto_selectorFromTime;
    result.fromSample = corto_selectorFromSample;
    result.toNow = corto_selectorToNow;
    result.toTime = corto_selectorToTime;
    result.toSample = corto_selectorToSample;
    result.forDuration = corto_selectorForDuration;
    result.forDepth = corto_selectorForDepth;
    result.iter = corto_selectorIter;
    return result;
}

corto_selectFluent corto_select(
    corto_string scope,
    corto_string expr)
{
    corto_selectRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_selectRequest));
        corto_threadTlsSet(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_selectRequest));
    }

    corto_debug("corto: select: '%s', '%s'", scope, expr);

    request->scope = scope;
    request->expr = expr;
    return corto_selectFluentGet();
}
