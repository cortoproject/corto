/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "corto/corto.h"
#include "_object.h"
#include "_matcher.h"

extern corto_int8 CORTO_OLS_AUGMENT;
extern corto_threadKey CORTO_KEY_FLUENT;

struct corto_selectData;

typedef int (*corto_mountAction)(corto_mount _this, corto_request *r, void *userData);

/* Fluent request */
typedef struct corto_selectRequest {
    corto_int16 err;
    corto_string scope;
    corto_string expr;
    corto_string type;
    corto_uint64 offset;
    corto_uint64 limit;
    corto_string contentType;
    corto_frame from;
    corto_frame to;
    corto_mountAction mountAction;
    corto_object instance;
    corto_mount mount;
} corto_selectRequest;

typedef struct corto_selectData corto_selectData;

typedef struct corto_selectHistoryIter_t {
    corto_iter iter;
    corto_selectData *data;
    corto_sample sample;
} corto_selectHistoryIter_t;

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

struct corto_selectData {
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
    corto_uint64 skip;

    /* History */
    corto_frame from;
    corto_frame to;

    /* Filters */
    corto_string typeFilter;

    /* Query for recursive queries on mounts */
    corto_id recursiveQuery;

    /* Does select need to resume objects */
    corto_bool resume;

    /* Additional action to be performed when data is requested from mount */
    corto_mountAction mountAction;

    /* Indicates if the walk should stop */
    corto_bool quit;
    corto_bool *quitPtr; /* If quit was not set to TRUE, this structure will be
                          * cleaned up. This pointer allows apps to check if
                          * iteration stopped because quit was set to TRUE. The
                          * variable assigned to quitPtr must be initialized to
                          * FALSE. */

    /* Ignore data from the instance (mount) if set */
    corto_object instance;

    /* Ignore all other mounts if set */
    corto_mount mount;

    /* Pre allocated for selectItem */
    corto_id id;
    corto_id name;
    corto_id parent;
    corto_id type;
    corto_result item;
    corto_bool valueAllocated;
    corto_selectHistoryIter_t historyIterData;
    corto_result *next;
};

static corto_contentType corto_selectSrcContentType(corto_selectData *data) {
    return (corto_contentType)
      data->mounts[data->stack[data->sp].currentMount - 1]->contentTypeOutHandle;
}

static corto_word corto_selectConvert(
    corto_selectData *data,
    corto_string type,
    corto_word value)
{
    corto_word result = 0;

    if (!value) {
        return 0;
    }

    corto_contentType srcType = corto_selectSrcContentType(data);

    /* If source serializer is loaded, a conversion is
     * needed */
    if (srcType && (srcType != data->dstSer)) {
        corto_object t = corto_resolve(NULL, type);
        if (!t) {
            corto_seterr("unresolved type '%s'", type);
            goto error;
        } else {
            corto_object o = corto_create(t);

            /* Convert from source format to object */
            corto_value v = corto_value_object(o, NULL);
            if (srcType->toValue(&v, value)) {
                corto_seterr("failed to convert value to '%s' (%s)",
                    type,
                    corto_lasterr());
                goto error;
            }

            /* Convert from object to destination format */
            if (!(result = data->dstSer->fromValue(&v))) {
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
       !stricmp(fromArray[common], toArray[common]))
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
                if (common || (toCount != 1)) {
                    strcat(buffer, "/");
                }
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

    item->owner = corto_ownerof(o);
    corto_setref(&item->object, o);

    if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
        strcpy(item->type, corto_fullpath(NULL, corto_typeof(o)));
    } else {
        corto_string_ser_t serData;
        corto_walk_opt s;

        serData.buffer = CORTO_BUFFER_INIT;
        serData.buffer.buf = item->type;
        serData.buffer.max = CORTO_MAX_PATH_LENGTH;
        serData.compactNotation = TRUE;
        serData.prefixType = FALSE;
        serData.enableColors = FALSE;

        s = corto_string_ser(
            CORTO_LOCAL,
            CORTO_NOT,
            CORTO_WALK_TRACE_NEVER);

        corto_walk(&s, corto_typeof(o), &serData);
    }

    if (data->contentType) {
        if (item->value) {
            data->dstSer->release(item->value);
        }
        corto_value v = corto_value_object(o, NULL);
        item->value = data->dstSer->fromValue(&v);
    }

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

        /* Only filter (duplicate) results from the object store. The root object
         * cannot be masked by a mount. */
        if (o && (o != root_o)) {
            corto_int32 i;

            for (i = 0; i < data->mountsLoaded; i++) {
                corto_mount r = data->mounts[i];
                corto_string rType = corto_observer(r)->type;

                /* If a SINK mount doesn't implement the onRequest method, select will
                 * return the contents of the object store */
                if ((r->kind == CORTO_SINK) && !r->passThrough) {
                    if (rType) {
                        /* If the type matches, the object is managed by the
                         * mount. This prevents returning duplicate results. */
                        if (!strcmp(rType, type)) {
                            result = FALSE;
                        } else {
                            continue;
                        }
                    } else {
                        /* A SINK mount that has no type specified blocks
                         * everything */
                        result = FALSE;
                    }

                    /* Do the same for attributes */
                    if (o && r->attr) {
                        if (corto_checkAttr(o, r->attr)) {
                            result = FALSE;
                        } else {
                            /* If result was set to FALSE by type, reset to TRUE */
                            result = TRUE;
                            continue;
                        }
                    } else {
                        result = FALSE;
                    }

                    if (!result) {
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
    if (data->mountAction || !data->quit) {
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

        corto_debug("select: RequestMount: request '%s' (%s), parent='%s', expr='%s'",
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

        if (data->mountAction) {
            /* If mount-action returns non-zero, quit the walk asap */
            if (!data->mountAction(mount, &r, data)) {
                data->mountAction = NULL;
                data->quit = TRUE;
                if (data->quitPtr) {
                    *(data->quitPtr) = TRUE;
                }
            }
        }

        /* If this is a dry run, don't request data from mount */
        if (data->quit) {
            return CORTO_ITER_EMPTY;
        } else {
            return corto_mount_request(mount, &r);
        }
    } else {
        return CORTO_ITER_EMPTY;
    }
}

int corto_selectHistoryHasNext(corto_iter *it) {
    corto_selectHistoryIter_t *ctx = it->udata;
    return corto_iter_hasNext(&ctx->iter);
}

void* corto_selectHistoryNext(corto_iter *it) {
    corto_selectHistoryIter_t *ctx = it->udata;
    corto_word dstValue;
    corto_sample *s = corto_iter_next(&ctx->iter);
    
    dstValue = corto_selectConvert(ctx->data, ctx->data->item.type, s->value);

    if (ctx->sample.value) {
        ctx->data->dstSer->release(ctx->sample.value);
    }

    ctx->sample.value = dstValue;
    ctx->sample.timestamp = s->timestamp;

    return &ctx->sample;
}

void corto_selectHistoryRelease(corto_iter *it) {
    corto_selectHistoryIter_t *ctx = it->udata;
    
    if (ctx->sample.value) {
        ctx->data->dstSer->release(ctx->sample.value);
    }

    corto_iter_release(&ctx->iter);

    ctx->data->item.history.udata = NULL;
}

static corto_int16 corto_selectIterMount(
    corto_selectData *data,
    corto_selectStack *frame)
{
    corto_id parent, expr, rpath;
    corto_mount mount = NULL;

    /* Parse filter into parent and expression */
    if (frame->scopeQuery) {
        strcpy(parent, frame->scopeQuery);
    } else {
        *parent = '\0';
    }

    corto_selectParseFilter(frame->filter, parent, expr);

    corto_result *result = corto_iter_next(&frame->iter);
    if (!result) {
        corto_error("mount iterator returned NULL");
        goto error;
    }

    corto_debug(
        "corto: select: IterMount: returned '%s, %s' (recursiveQuery = %s)",
        result->id, result->parent, data->recursiveQuery);

    data->next = &data->item;

    mount = data->mounts[frame->currentMount - 1];
    data->item.owner = mount;
    data->item.object = NULL;
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
        corto_id path;

        strcpy(path, data->scope ? data->scope : "");
        if (frame->scope) {
            corto_fullpath(rpath, frame->scope);
        } else {
            corto_fullpath(rpath, mount->mount);
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

    /* If src & dst contentTypes are different, translate */
    corto_contentType srcType = corto_selectSrcContentType(data);
    if (data->dstSer && (data->dstSer != srcType)) {
        /* Convert value */
        data->dstSer->release(data->item.value);
        data->item.value = corto_selectConvert(
          data, result->type, result->value);
        data->valueAllocated = TRUE;

        /* Wrap history iterator in other iterator that converts contentType */
        if (memcmp(&data->from, &data->to, sizeof(corto_frame))) {
            data->item.history.hasNext = corto_selectHistoryHasNext;
            data->item.history.next = corto_selectHistoryNext;
            data->item.history.release = corto_selectHistoryRelease;
            data->item.history.udata = &data->historyIterData;
            data->historyIterData.iter = result->history;
            data->historyIterData.data = data;
            data->historyIterData.sample.value = 0;            
        }
    } else {
        data->item.history = result->history;
        data->item.value = result->value;
        data->valueAllocated = FALSE;
    }

    if (data->resume) {
        corto_type type = NULL;

        if (corto_observer(mount)->typeReference) {
            corto_setref(&type, corto_observer(mount)->typeReference);
        } else {
            if (!(type = corto_resolve(NULL, result->type))) {
                corto_warning("select: could not resume '%s/%s' from '%s': type '%s not found",
                  result->parent,
                  result->id,
                  corto_fullpath(NULL, mount),
                  result->type);
            }
        }

        corto_object parent = corto_lookup(NULL, rpath);
        if (!parent) {
            corto_warning("select: could not resume '%s/%s' from '%s': parent not found",
              result->parent,
              result->id,
              corto_fullpath(NULL, mount));
        }

        corto_object prev = corto_setOwner(mount);
        corto_object ref = corto_declareChild(parent, result->id, type);
        corto_release(type);
        corto_release(parent);

        if (!ref) {
            corto_warning("select: could not resume '%s/%s' from '%s': failed to create object",
              result->parent,
              result->id,
              corto_fullpath(NULL, mount));
        }

        if (result->value) {
            if (mount->contentTypeOutHandle) {
                corto_contentType handle = (corto_contentType)mount->contentTypeOutHandle;
                corto_value v = corto_value_object(ref, type);
                handle->toValue(&v, result->value);
            } else {
                corto_warning("select: mount '%s' sets result.value but has no contentType",
                  corto_fullpath(NULL, mount));
            }
        }

        if (corto_define(ref)) {
            corto_warning("select: failed to define '%s/%s' from mount '%s'",
              result->parent, result->id,
              corto_fullpath(NULL, mount));
        }

        corto_setOwner(prev);
        corto_setref(&result->object, ref);
        corto_release(ref);
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
                if (corto_scopeof(frame->scope) && corto_rbtreeIterChanged(&frame->iter)) {
                    frame->iter = _corto_rbtreeIter(corto_scopeof(frame->scope), &frame->trav);
                    while (corto_iter_hasNext(&frame->iter)) {
                        corto_object o = corto_iter_next(&frame->iter);
                        if (stricmp(corto_idof(o), lastKey) > 0) {
                            result = o;
                            break;
                        }
                    }
                } else {
                    if (corto_iter_hasNext(&frame->iter)) {
                        result = corto_iter_next(&frame->iter);
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

            while (!(hasData = corto_iter_hasNext(&frame->iter)) && (frame->currentMount < data->mountsLoaded)) {
                frame->currentMount ++;
                frame->iter = corto_selectRequestMount(
                  data, frame, data->mounts[frame->currentMount - 1]);
            }

            if (hasData) {
                corto_selectIterMount(data, frame);
            }
        }
    } else {
        if ((hasData = corto_iter_hasNext(&frame->iter))) {
            corto_selectIterMount(data, frame);
        }
    }

    if (hasData && (data->mask == CORTO_ON_SELF)) {
        data->mask = 0;
    }

    return hasData;
}

static int corto_selectLoadMountWalk(
    corto_object entity, 
    corto_object instance, 
    void *userData) 
{
    corto_selectData *data = userData;
    corto_mount mount = entity;

    CORTO_UNUSED(instance);

    /* If only querying data from one mount, ignore all others */
    if (data->mount && (mount != data->mount)) {
        return 1;
    }

    /* If a mount is querying data for itself, ignore self */
    if (data->instance && (mount == data->instance)) {
        return 1;
    }

    /* If historical data is requested, only request from
     * historians and vice versa. */
    if (memcmp(&data->from, &data->to, sizeof(corto_frame))) {
        if (mount->kind != CORTO_HISTORIAN) {
            return 1;
        }
    } else if (mount->kind == CORTO_HISTORIAN) {
        return 1;
    }

    /* If type is requested, test whether it is compatible with
     * the type of the mount */
    corto_string rType = corto_observer(mount)->type;
    if (data->typeFilter && rType) {
        if (!corto_match(data->typeFilter, rType)) {
            return 1;
        }
    }

    data->mounts[data->mountsLoaded] = mount;
    data->mountsLoaded ++;

    corto_debug("select: LoadMounts: load '%s', type = %s, mountsLoaded = %d",
      corto_fullpath(NULL, mount),
      corto_fullpath(NULL, corto_typeof(mount)),
      data->mountsLoaded);

    return 1;
}

/* Load mounts for a scope */
static void corto_selectLoadMounts(
    corto_selectData *data,
    corto_selectStack *frame)
{
    data->mountsLoaded = 0;

    /* 1: Count mounts registered on parent scopes */
    while (data->mounts[data->mountsLoaded]) {
        data->mountsLoaded ++;
    }

    frame->currentMount = data->mountsLoaded;
    frame->firstMount = data->mountsLoaded;

    corto_id parentId;
    corto_fullpath(parentId, frame->scope);

    corto_entityAdmin_walk(&corto_mount_admin, corto_selectLoadMountWalk, parentId, data);
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
    data->next = NULL;
    corto_object o = NULL;

    if (data->quit) {
        return;
    }

    do {
        corto_bool leaf = TRUE, hasData = FALSE;

        /* Unwind stack for depleted iterators */
        while (!(hasData = corto_selectIterNext(data, frame, &o, lastKey)) && data->sp && !data->quit) {
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
                   (data->skip >= data->offset))
                {
                    noMatch = FALSE;
                    corto_setItemData(o, data->next, data);
                } else {
                    data->skip ++;
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
                    corto_selectLoadMounts(data, frame);
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
    } while (noMatch && data->next && !data->quit);
}

/* Reset select data (either initially or when moving to next scope) */
static void corto_selectReset(corto_selectData *data) {
    if (data->item.value && data->dstSer && data->dstSer->release && data->valueAllocated) {
        data->dstSer->release(data->item.value);
    }

    if (data->item.object) {
        corto_setref(&data->item.object, NULL);
    }

    if (data->item.history.release) {
        data->item.history.release(&data->item.history);
        data->item.history.udata = 0;
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

    corto_selectLoadMounts(data, frame);
}

/* When moving to the next scope element, filter out active mounts that
 * don't operate on a tree, as they don't contain relevant data for
 * a child scope. The remaining mounts are used to evaluate whether a SINK is
 * active for a scope, in which case objects must be masked. */
static void corto_selectFilterMounts(corto_selectData *data) {
    corto_int32 i = 0;
    for (i = 0; i < data->mountsLoaded; i ++) {
        if (!(((corto_observer)data->mounts[i])->mask & CORTO_ON_TREE)) {
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
        corto_debug("select: Next (%s, %s)", data->next->id, data->next->parent);
        data->count ++;
    }

    return data->next;
}

static void* corto_selectNextObjects(corto_objectIter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    if (data->next) {
        corto_debug("select: NextObject (%s, %s)", data->next->id, data->next->parent);
        data->count ++;
    }

    return data->next->object;
}

static void corto_selectRelease(corto_iter *iter) {
    corto_selectData *data = iter->udata;

    CORTO_UNUSED(iter);

    if (data->exprStart) corto_dealloc(data->exprStart);
    if (data->program.tokens) corto_dealloc(data->program.tokens);
    if (data->scope) corto_dealloc(data->scope);
    if (data->fullscope) corto_dealloc(data->fullscope);

    /* Free iterators */
    corto_int32 i;
    for (i = 0; i <= data->sp; i ++) {
        corto_iter_release(&data->stack[i].iter);
    }

    /* Free scope objects */
    i = 0;
    while (data->scopes[i].scope) {
        corto_setref(&data->scopes[i].scope, NULL);
        i++;
    }

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
            data->scopes[current].scope = corto_find(
                data->scopes[current - 1].scope,
                expr,
                CORTO_FIND_DEFAULT);
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
    if (data->quit) {
        return 0;
    }

    corto_selectStack *frame = &data->stack[data->sp];

    CORTO_UNUSED(iter);

    if (data->limit) {
         if (data->limit <= data->count)
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

    /* If the select has been aborted, the select data likely contains data that
     * cannot yet be released. Therefore, give an application the opportunity to
     * obtain the data before returning 0, and cleaning up the select data. */
    return data->quit ? 1 : data->next != NULL;
stop:
    return 0;
}

static corto_resultIter corto_selectPrepareIterator (
    struct corto_selectRequest *r)
{
    corto_selectData *data = corto_calloc(sizeof(corto_selectData));

    corto_resultIter result;
    memset(&result, 0, sizeof(corto_resultIter));

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

    if (r->expr && *(r->expr)) {
        data->expr = r->expr;
    } else {
        data->expr = corto_strdup(".");
        corto_dealloc(r->expr);
    }
    data->exprStart = data->expr;

    data->contentType = r->contentType;
    data->mountsLoaded = -1;
    data->offset = r->offset;
    data->limit = r->limit;
    data->typeFilter = r->type;
    data->from = r->from;
    data->to = r->to;
    data->item.parent = data->parent;
    data->item.name = data->name;
    data->item.type = data->type;
    data->item.id = data->id;
    data->item.leaf = TRUE;
    data->mountAction = r->mountAction;
    data->instance = r->instance;
    data->mount = r->mount;
    data->valueAllocated = FALSE;

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
        corto_seterr("select '%s' failed: %s", data->expr, corto_lasterr());
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

static int corto_mountAction_id(corto_mount m, corto_request *r, void *ctx) {
    CORTO_UNUSED(r);

    if (m->kind == CORTO_SINK) {
        corto_selectData *data = ctx;
        corto_string id = _corto_mount_id(m);
        if (id) {
            data->item.id = id;
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}
static corto_string corto_selectorId()
{
    corto_string result = NULL;
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);

    if (request) {
        corto_bool quit = FALSE;
        request->mountAction = corto_mountAction_id;
        corto_threadTlsSet(CORTO_KEY_FLUENT, NULL);
        corto_iter it = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);

        corto_selectData *data = it.udata;
        data->quitPtr = &quit;

        /* Walk results until id is found */
        while (corto_iter_hasNext(&it) && !quit) {
            corto_iter_next(&it);
        }
        if (quit) {
            result = data->item.id;
            corto_iter_release(&it);
        }
    }

    return result;
error:
    return NULL;
}

static int corto_mountAction_subscribe(corto_mount m, corto_request *r, void *ctx) {
    CORTO_UNUSED(ctx);
    _corto_mount_subscribe(m, r);
    return 1;
}
static corto_int16 corto_selectorSubscribe(corto_resultIter *ret)
{
    corto_assert(ret != NULL, "no iterator provided to .subscribe()");

    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->mountAction = corto_mountAction_subscribe;
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

static int corto_mountAction_unsubscribe(corto_mount m, corto_request *r, void *ctx) {
    CORTO_UNUSED(ctx);
    _corto_mount_unsubscribe(m, r);
    return 1;
}
static corto_int16 corto_selectorUnsubscribe()
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->mountAction = corto_mountAction_unsubscribe;
        corto_threadTlsSet(CORTO_KEY_FLUENT, NULL);
        corto_iter it = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);

        /* Walk results to unsubscribe all mounts */
        while (corto_iter_hasNext(&it)) {
            corto_iter_next(&it);
        }
    }

    return 0;
error:
    return -1;
}

static corto_int16 corto_selectorIterObjects(corto_objectIter *ret)
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

        /* When requesting objects, the from-scope is meaningless. Setting the
         * scope to NULL makes it easier to resolve the parent while iterating.
         */
        corto_selectData *data = ret->udata;
        data->resume = TRUE;

        /* Override iterator callbacks for object iterator */
        ret->next = corto_selectNextObjects;
    }

    return 0;
error:
    return -1;
}

static corto_int64 corto_selectorCount()
{
    corto_resultIter it;
    corto_uint64 count = 0;

    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);

    if (request) {
        corto_threadTlsSet(CORTO_KEY_FLUENT, NULL);
        it = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);

        while (corto_iter_hasNext(&it)) {
            corto_iter_next(&it);
            count ++;
        }
    }

    return count;
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

static corto_selectFluent corto_selectorInstance(corto_object instance)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectorMount(corto_mount mount)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->mount = mount;
    }
    return corto_selectFluentGet();
}

static corto_selectFluent corto_selectFluentGet(void)
{
    corto_selectFluent result;
    result.contentType = corto_selectorContentType;
    result.limit = corto_selectorLimit;
    result.type = corto_selectorType;
    result.fromNow = corto_selectorFromNow;
    result.fromTime = corto_selectorFromTime;
    result.fromSample = corto_selectorFromSample;
    result.toNow = corto_selectorToNow;
    result.toTime = corto_selectorToTime;
    result.toSample = corto_selectorToSample;
    result.forDuration = corto_selectorForDuration;
    result.forDepth = corto_selectorForDepth;
    result.iter = corto_selectorIter;
    result.subscribe = corto_selectorSubscribe;
    result.unsubscribe = corto_selectorUnsubscribe;
    result.id = corto_selectorId;
    result.iterObjects = corto_selectorIterObjects;
    result.count = corto_selectorCount;
    result.instance = corto_selectorInstance;
    result.mount = corto_selectorMount;
    return result;
}

corto_selectFluent corto_select(
    corto_string scope,
    corto_string expr,
    ...)
{
    va_list arglist;

    corto_selectRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_selectRequest));
        corto_threadTlsSet(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_selectRequest));
    }

    corto_debug("select: '%s', '%s'", scope, expr);
    
    if (expr) {
        va_start(arglist, expr);
        corto_vasprintf(&request->expr, expr, arglist);
        va_end(arglist);
    }

    request->scope = scope;
    return corto_selectFluentGet();
}
