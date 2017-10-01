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

#include <corto/corto.h>

#include "src/store/object.h"
#include "idmatch.h"

extern corto_int8 CORTO_OLS_AUGMENT;
extern corto_threadKey CORTO_KEY_FLUENT;

struct corto_select_data;

#define CORTO_MAX_MOUNTS_PER_SELECT (256)

typedef int (*corto_mountAction)(corto_mount _this, corto_query *r, void *userData);

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

typedef struct corto_select_data corto_select_data;

typedef struct corto_selectHistoryIter_t {
    corto_iter iter;
    corto_select_data *data;
    corto_sample sample;
} corto_selectHistoryIter_t;

typedef struct corto_select_segment {
    char *scope;
    char *expr;
    corto_object o;
} corto_select_segment;

typedef struct corto_select_frame {
    corto_select_segment *cur;
    corto_object o;

    jsw_rbtrav_t trav; /* Persistent tree iterator */
    corto_iter iter;

    corto_int32 locationLength; /* Restore query when leaving frame */
    corto_uint8 firstMount; /* First mount loaded for frame */
    corto_int8 currentMount; /* Current mount being evaluated */
} corto_select_frame;

struct corto_select_data {
    corto_string scope;                      /* Scope passed to select */
    corto_string expr;                       /* Current expression */
    corto_string exprStart;                  /* Points to start of full expr */
    corto_string contentType;
    
    /* Object filter */
    corto_string filter;
    corto_idmatch_program filterProgram;   /* Parsed program */

    /* Which expression is being evaluated (when expression contains ,) */
    corto_uint32 exprCount;
    corto_uint32 exprCurrent;

    corto_string fullscope;             /* Scope + scope part of expression */
    corto_select_segment segments[CORTO_MAX_SCOPE_DEPTH]; /* Scopes to walk (parsed scope) */
    corto_uint32 segment;               /* Scope currently being walked */

    struct corto_idmatch_program_s program;   /* Parsed program */

    corto_select_frame stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    corto_uint8 sp;
    corto_eventMask mask;

    /* Mounts currently loaded */
    corto_mount mounts[CORTO_MAX_MOUNTS_PER_SELECT];

    /* Mounts with outstanding requests */
    corto_int16 mountsLoaded;

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

    /* Full path representing the current location of select */
    corto_id location;

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

static corto_contentType corto_selectSrcContentType(corto_select_data *data) {
    return (corto_contentType)
      data->mounts[data->stack[data->sp].currentMount - 1]->contentTypeOutHandle;
}

static corto_word corto_selectConvert(
    corto_select_data *data,
    corto_string type,
    corto_word value)
{
    corto_word result = 0;

    if (!value) {
        return 0;
    }

    corto_contentType srcType = corto_selectSrcContentType(data);

    if (!srcType && value) {
        corto_warning("select: mount '%s' provides value but no contentType",
            corto_fullpath(NULL, data->mounts[data->stack[data->sp].currentMount - 1]));
        return 0;
    }

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

void corto_pathstr(
    char *out,
    char *from,
    char *to,
    int tolen);

static void corto_setItemData(
    corto_object o,
    corto_result *item,
    corto_select_data *data)
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
    corto_pathstr(item->parent, from, to, -1);

    if (corto_idof(o)) {
        strcpy(item->id, corto_idof(o));
        corto_nameof(item->name, o);
    } else {
        item->id[0] = '\0';
        item->name[0] = '\0';
    }

    item->owner = corto_ownerof(o);
    corto_ptr_setref(&item->object, o);

    if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_NAMED)) {
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

    if (corto_scopeSize(o)) {
        item->flags = CORTO_RESULT_LEAF;
    }
}

static corto_bool corto_selectMatch(
    corto_object o,
    corto_result *item,
    corto_select_data *data)
{
    corto_bool result = TRUE;
    char *id = o ? corto_idof(o) : item->id;

    if (corto_secured()) {
        if (o) {
            if (!corto_authorized(o, CORTO_SECURE_ACTION_READ)) {
                goto access_error;
            }
        } else {
            corto_id id;
            sprintf(id, "%s/%s", item->parent, item->id);
            corto_cleanpath(id, id);
            if (!corto_authorizedId(id, CORTO_SECURE_ACTION_READ)) {
                goto access_error;
            }
        }
    }

    /* Filter name */
    if (data->filterProgram) {
        result = corto_idmatch_run(data->filterProgram, id);
    }

    /* Check if there are SINK mounts active for the current scope */
    if (result) {
        corto_id type;
        if (o) {
            corto_fullpath(type, corto_typeof(o));
        } else {
            strcpy(type, item->type);
        }

        /* Only filter (duplicate) results from the object store. The root object
         * cannot be masked by a mount. */
        if (o && (o != root_o)) {
            corto_int32 i;

            for (i = 0; i < data->mountsLoaded; i++) {
                corto_mount r = data->mounts[i];
                corto_string rType = r->super.query.type;

                /* If a SINK mount doesn't implement the onQuery method, select will
                 * return the contents of the object store */
                if ((r->policy.ownership == CORTO_LOCAL_OWNER) && !r->passThrough) {
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
            if (data->typeFilter[0] == '/' && type[0] != '/') {
                /* If typeFilter starts with a slash (indicating a full path)
                 * but the object type doesn't, the result either does not match
                 * or it is in one of corto's default search scopes. Try to
                 * obtain the full type identifier, then apply filter */
                corto_object typeObject = NULL;
                if ((typeObject = corto_resolve(NULL, type))) {
                    corto_fullpath(type, typeObject);
                    corto_release(typeObject);
                    result = corto_idmatch(data->typeFilter, type);
                } else {
                    result = FALSE;
                }
            } else {
                result = corto_idmatch(data->typeFilter, type);
            }
        }        
    }

    return result;
access_error:
    return FALSE;
}

static
char* corto_selectRelativeParent(
    corto_query *q,
    corto_select_data *data)
{
    uint64_t len = q->from ? strlen(q->from) : 0;

    if (q->from && q->from[0] != '/') {
        len ++;
    }

    char *parent = &data->location[len];
    if (!parent[0]) {
        parent = ".";
    } else if (parent[0] == '/') {
        parent ++;
    }

    return parent;
}

static 
corto_resultIter corto_selectRequestMount(
    corto_select_data *data,
    corto_mount mount)
{
    if (data->mountAction || !data->quit) {
        char *expr = data->mask == CORTO_ON_TREE ? "*" : data->filter ? data->filter : "*";
        corto_query *q = &corto_subscriber(mount)->query;
        char *parent = corto_selectRelativeParent(q, data);

        corto_debug("select: query (select='%s' from='%s') mount '%s', location '%s'",
          expr, 
          parent,
          corto_fullpath(NULL, mount),
          data->location);

        corto_query r = {
          .from = parent,
          .select = expr,
          .type = data->type,
          .offset = (data->offset > data->count) ? data->offset - data->count : 0,
          .limit = (data->offset > data->count) ? data->limit : data->limit - (data->offset - data->count),
          .content = data->contentType ? TRUE : FALSE,
          .timeBegin = data->from,
          .timeEnd = data->to};

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
            return corto_mount_query(mount, &r);
        }
    } else {
        return CORTO_ITER_EMPTY;
    }
}

int corto_selectHistoryHasNext(corto_iter *it) {
    corto_selectHistoryIter_t *ctx = it->ctx;
    return corto_iter_hasNext(&ctx->iter);
}

void* corto_selectHistoryNext(corto_iter *it) {
    corto_selectHistoryIter_t *ctx = it->ctx;
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
    corto_selectHistoryIter_t *ctx = it->ctx;
    
    if (ctx->sample.value) {
        ctx->data->dstSer->release(ctx->sample.value);
    }

    corto_iter_release(&ctx->iter);

    ctx->data->item.history.ctx = NULL;
}

static bool corto_selectIterMount(
    corto_select_data *data,
    corto_select_frame *frame)
{
    corto_id rpath;
    corto_mount mount = data->mounts[frame->currentMount - 1];

    corto_result *result = corto_iter_next(&frame->iter);
    if (!result) {
        corto_critical("mount iterator returned NULL");
    }

    corto_debug(
        "select: mount returned (id = '%s', parent = '%s' leaf = '%s')",
        result->id, result->parent, result->flags & CORTO_RESULT_LEAF ? "true" : "false");

    /* Filter data early if mount indicates it doesn't do any filtering, and
     * this is not a tree query */
    if (data->filterProgram && 
        mount->policy.filterResults && 
        data->mask != CORTO_ON_TREE) 
    {
        if (!corto_selectMatch(NULL, result, data)) {
            goto noMatch;
        }

        char *parent = corto_selectRelativeParent(&corto_subscriber(mount)->query, data);
        if (strcmp(parent, result->parent)) {
            goto noMatch;
        }
    }

    data->next = &data->item;
    data->item.owner = mount;
    data->item.object = NULL;
    data->item.flags = result->flags;

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
        strcpy(rpath, corto_subscriber(mount)->query.from);
        strcat(rpath, "/");
        strcat(rpath, result->parent);
        corto_cleanpath(rpath, rpath);
        corto_pathstr(data->item.parent, path, rpath, -1);
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
            data->item.history.ctx = &data->historyIterData;
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

        if (corto_observer(mount)->type) {
            corto_ptr_setref(&type, corto_observer(mount)->type);
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
        corto_ptr_setref(&result->object, ref);
        corto_release(ref);
    }

    return true;
noMatch:
    return false;
}

static corto_bool corto_selectIterNext(
    corto_select_data *data,
    corto_select_frame *frame,
    corto_object *o_out,
    corto_string lastKey)
{
    corto_bool hasData = FALSE;
    corto_object result = NULL;

    /* Select data from scope */
    if (frame->o) {

        /* Don't walk over objects if a frame contains a expr or if the
         * frame is already walking over a mount */
        if (!frame->cur->expr && (frame->currentMount == frame->firstMount)) {
            corto__scopeClaim(frame->o);

            if ((data->mask == CORTO_ON_SELF) && !data->filter) {
                result = frame->o;
            } else {

                /* When scope has changed, iterator becomes invalid. Re-obtain
                 * iterator and move to value that was last iterated over + 1.
                 * This prevents to either having to lock the scope / store all
                 * results in a temporary list. */
                if (corto_scopeof(frame->o) && corto_rb_iterChanged(&frame->iter)) {
                    frame->iter = _corto_rb_iter(corto_scopeof(frame->o), &frame->trav);
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
            corto__scopeRelease(frame->o);
        }
    }

    /* If no data was found in scope, and frame has unevaluated mounts,
     * request data from mounts. */
    bool retry;
    do {
        retry = false;
        if (!data->sp || (frame->cur != data->stack[data->sp - 1].cur)) {
            if (!hasData && data->mountsLoaded && (data->mountsLoaded > frame->firstMount)) {
                if (frame->currentMount == frame->firstMount) {
                    frame->currentMount ++;
                    frame->iter = corto_selectRequestMount(
                      data, data->mounts[frame->currentMount - 1]);
                }

                while (!(hasData = corto_iter_hasNext(&frame->iter)) && (frame->currentMount < data->mountsLoaded)) {
                    frame->currentMount ++;
                    frame->iter = corto_selectRequestMount(
                      data, data->mounts[frame->currentMount - 1]);
                }
            }
        } else if (!result) {
            hasData = corto_iter_hasNext(&frame->iter);
        }

        if (hasData && !result) {
            hasData = corto_selectIterMount(data, frame);

            /* If mount had data but did not return any data, the data did not
             * match the select query. Try next result */
            if (!hasData) retry = true;
        }
    } while (retry);

    if (hasData && (data->mask == CORTO_ON_SELF)) {
        data->mask = 0;
    }

    return hasData;
}

/* Evaluate whether mount for specific scope should be loaded */
static int corto_selectLoadMountWalk(
    corto_object entity, 
    corto_object instance, 
    void *userData) 
{
    corto_select_data *data = userData;
    corto_mount mount = entity;

    CORTO_UNUSED(instance);

    /* If user specified only one mount to query from, ignore other mounts */
    if (data->mount && (mount != data->mount)) {
        return 1;
    }

    /* Don't request data from self */
    if (data->instance && (mount == data->instance)) {
        return 1;
    }

    /* If historical data is requested, only load historians and don't request 
     * ordinary data from historians. */
    if (memcmp(&data->from, &data->to, sizeof(corto_frame))) {
        if (!(mount->policy.mask & CORTO_MOUNT_HISTORY_QUERY)) {
            return 1;
        }
    }

    /* If type is requested, test whether it matches with the mount type */
    corto_string rType = mount->super.query.type;
    if (data->typeFilter && rType) {
        if (!corto_idmatch(data->typeFilter, rType)) {
            return 1;
        }
    }

    /* If select query consists of multiple segments, ensure that next segments
     * do not conflict with mount type, if set. */
    if (rType) {
        int s = data->segment + 1;
        while (data->segments[s].scope) {
            corto_select_segment *segment = &data->segments[s];
            if (segment->o) {
                corto_id typeId;
                if (strcmp(rType, corto_fullpath(typeId, corto_typeof(segment->o)))) {
                    return 1;
                }
            }
            s ++;
        }
    }

    if (data->mountsLoaded == CORTO_MAX_MOUNTS_PER_SELECT) {
        corto_seterr("number of mounts exceeded (%d) for request",
            CORTO_MAX_MOUNTS_PER_SELECT);
        return 0;
    }

    /* Mount should be loaded */
    data->mounts[data->mountsLoaded] = mount;
    data->mountsLoaded ++;

    corto_debug("select: add mount '%s' of type = '%s', mountsLoaded = %d",
      corto_fullpath(NULL, mount),
      corto_fullpath(NULL, corto_typeof(mount)),
      data->mountsLoaded);

    return 1;
}

/* Load mounts for a frame */
static int16_t corto_selectLoadMounts(
    corto_select_data *data,
    corto_select_frame *frame)
{
    corto_bool recursive = !frame->cur->expr && data->mask == CORTO_ON_TREE;
    data->mountsLoaded = 0;

    /* Count mounts registered on parent scopes. Mounts loaded for this frame
     * will be appended to the mounts array. */
    while (data->mounts[data->mountsLoaded]) {
        data->mountsLoaded ++;
    }

    /* Keep track of current mount and the first mount loaded by this frame */
    frame->currentMount = data->mountsLoaded;
    frame->firstMount = data->mountsLoaded;

    corto_debug("select: look for mounts in '%s'%s", 
        frame->cur->scope,
        recursive ? " recursively" : "");

    /* Walk mount admin to obtain list of mounts for frame of current scope */
    if (!corto_entityAdmin_walk(
        &corto_mount_admin,
        corto_selectLoadMountWalk,
        frame->cur->scope,
        recursive ? true : false,
        data)) 
    {
        return -1;
    }

    return 0;
}

/* Depth first search */
static int16_t corto_selectTree(
    corto_select_data *data,
    corto_select_frame *frame)
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
        return 0;
    }

    corto_debug("select: iterate frame %d (scope = '%s', expr = '%s', location = '%s')",
            data->sp, frame->cur->scope, frame->cur->expr, data->location);

    do {
        corto_resultMask flags = CORTO_RESULT_LEAF, hasData = FALSE;

        /* Unwind stack for depleted iterators */
        while (!(hasData = corto_selectIterNext(data, frame, &o, lastKey)) && data->sp && !data->quit) {
            /* Cache name as next line might delete object */
            if (frame->o) {
                strcpy(data->item.name, corto_idof(frame->o));
                corto_ptr_setref(&frame->o, NULL);
            }

            data->sp --;
            data->mountsLoaded = frame->firstMount;
            data->location[frame->locationLength] = '\0';
            frame = &data->stack[data->sp];
        }


        if (hasData) {
            data->next = &data->item;

            if (o) {
                if (corto_selectMatch(o, &data->item, data) &&
                   (data->skip >= data->offset))
                {
                    noMatch = FALSE;
                    corto_setItemData(o, data->next, data);
                } else {
                    data->skip ++;
                }
                flags = 0;
            } else {
                /* If doing a lookup on a tree, select requests all objects from
                 * a mount and thus needs to perform matching. If not, select
                 * will pass the filter to the mount, and the mount is expected
                 * to only return matching objects. */
                if (data->mask != CORTO_ON_TREE) {
                    noMatch = FALSE;
                } else {
                    noMatch = !corto_selectMatch(NULL, &data->item, data);
                }
                flags = data->next->flags;
            }

            /* Prepare next frame if object has scope */
            if (!(flags & CORTO_RESULT_LEAF) && (data->mask == CORTO_ON_TREE)) {
                corto_select_frame *prevFrame = frame;
                frame = &data->stack[++ data->sp];
                frame->locationLength = strlen(data->location);
                frame->firstMount = data->mountsLoaded;
                frame->currentMount = frame->firstMount;
                frame->cur = prevFrame->cur;
                corto_ptr_setref(&frame->o, o);

                if (o) {
                    corto_rbtree scope = corto_scopeof(o);
                    if (scope) {
                        frame->iter = _corto_rb_iter(scope, &frame->trav);
                    }
                } else {
                    int len = strlen(data->location);
                    if (!len || data->location[len - 1] != '/') {
                        data->location[len] = '/';
                        len ++;
                    }                    
                    strcpy(&data->location[len], data->item.name);
                    frame->currentMount = prevFrame->currentMount;
                    frame->iter = corto_selectRequestMount(
                      data, data->mounts[frame->currentMount - 1]);

                    corto_debug("select: moved to '%s'", data->location);
                }
            }

            /* If result is hidden, skip */
            if (flags & CORTO_RESULT_HIDDEN) {
                noMatch = true;
            }
        } else {
            data->next = NULL;
        }

        if (o) corto_release(o);
    } while (noMatch && data->next && !data->quit);

    return 0;
}

/* Reset select data (either initially or when moving to next scope) */
static void corto_selectReset(corto_select_data *data) {
    if (data->item.value && data->dstSer && data->dstSer->release && data->valueAllocated) {
        data->dstSer->release(data->item.value);
    }

    if (data->item.object) {
        corto_ptr_setref(&data->item.object, NULL);
    }

    if (data->item.history.release) {
        data->item.history.release(&data->item.history);
        data->item.history.ctx = 0;
    }

    data->sp = 0;
    data->item.value = 0;
    data->mountsLoaded = -1;
}

static int16_t corto_selectPrepareFrame(
    corto_select_data *data,
    corto_select_frame *frame,
    corto_uint32 segment)
{
    frame->cur = &data->segments[segment];
    corto_ptr_setref(&frame->o, frame->cur->o);
    frame->currentMount = 0;
    frame->firstMount = 0;

    if (frame->o) {
        corto_rbtree tree = corto_scopeof(frame->o);
        if (tree) {
            frame->iter = _corto_rb_iter(tree, &frame->trav);
        } else {
            memset(&frame->iter, 0, sizeof(corto_iter));
        }
    }

    strcpy(data->location, data->segments[data->segment].scope);
    if (data->segments[data->segment].expr) {
        if (data->location[0] != '/' || data->location[1]) {
            strcat(data->location, "/");
        }
        strcat(data->location, data->segments[data->segment].expr);
    }

    if (corto_selectLoadMounts(data, frame)) {
        return -1;
    }

    return 0;
}

/* When moving to the next scope element, filter out active mounts that
 * don't operate on a tree, as they don't contain relevant data for
 * a child scope. The remaining mounts are used to evaluate whether a 
 * LOCAL_SOURCE is active for a scope, in which case objects must be masked. */
static void corto_selectFilterMounts(corto_select_data *data) {
    corto_int32 i = 0;

    for (i = 0; i < data->mountsLoaded; i ++) {
        corto_string mountType = NULL, segmentType = NULL;
        corto_id typeId;

        if (data->segments[data->segment + 1].scope && data->segments[data->segment + 2].scope) {
            mountType = ((corto_subscriber)data->mounts[i])->query.type;
            corto_select_segment *segment = &data->segments[data->segment + 2];
            segmentType = segment->o ? corto_fullpath(typeId, corto_typeof(segment->o)) : NULL;   
        }

        if (!(((corto_observer)data->mounts[i])->mask & CORTO_ON_TREE) ||
             (segmentType && mountType && strcmp(segmentType, mountType))) 
        {
            if (i == (data->mountsLoaded - 1)) {
                data->mounts[i] = NULL;
            } else {
                /* Don't move whole array forward, just move the last mount
                 * to the current position in the array. A user should make no
                 * assumptions on in which order mounts are invoked */
                data->mounts[i] =
                  data->mounts[data->mountsLoaded - 1];
                data->mounts[data->mountsLoaded - 1] = NULL;

                /* Process the mount moved into this position */
                i--;
            }
            data->mountsLoaded --;
        }
    }
}

static void* corto_selectNext(corto_resultIter *iter) {
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    if (data->next) {
        corto_debug("select: yield ('%s', '%s')", 
            data->next->id, 
            data->next->parent);
        data->count ++;
    }

    return data->next;
}

static void* corto_selectNextObjects(corto_objectIter *iter) {
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    if (data->next) {
        corto_debug("select: NextObject (%s, %s)", data->next->id, data->next->parent);
        data->count ++;
    }

    return data->next->object;
}

static void corto_selectRelease(corto_iter *iter) {
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    if (data->exprStart) corto_dealloc(data->exprStart);
    if (data->program.tokens) corto_dealloc(data->program.tokens);
    if (data->scope) corto_dealloc(data->scope);
    if (data->fullscope) corto_dealloc(data->fullscope);
    if (data->filterProgram) corto_idmatch_free(data->filterProgram);

    /* Free iterators */
    corto_int32 i;
    for (i = 0; i <= data->sp; i ++) {
        corto_ptr_setref(&data->stack[i].o, NULL);
        corto_iter_release(&data->stack[i].iter);
    }

    /* Free segments */
    i = 0;
    while (data->segments[i].scope) {
        corto_ptr_setstr(&data->segments[i].scope, NULL);
        corto_ptr_setstr(&data->segments[i].expr, NULL);
        corto_ptr_setref(&data->segments[i].o, NULL);
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
static corto_int16 corto_selectSplitScope(corto_select_data *data) {
    memset(data->segments, 0, sizeof(data->segments));

    char *ptr, ch;
    corto_uint32 current = 0;
    corto_id scope;
    strcpy(scope, data->fullscope);

    ptr = scope;

    if (ptr[0] == '/') {
        ptr ++;
    }

    /* Set first scope to root */
    corto_ptr_setstr(&data->segments[0].scope, "/");
    corto_ptr_setstr(&data->segments[0].expr, *ptr ? ptr : NULL);
    corto_ptr_setref(&data->segments[0].o, root_o);
    current ++;

    corto_debug("select: segment added: scope = '%s', expr = '%s', o = %p", 
        data->segments[0].scope, data->segments[0].expr, data->segments[0].o);

    if (ptr[0]) {
        do {
            ch = *ptr;
            if ((!ch && ptr != scope) || ch == '/') {
                *ptr = '\0';

                corto_ptr_setstr(&data->segments[current].scope, scope);
                corto_ptr_setstr(&data->segments[current].expr, ch ? ptr + 1 : NULL);

                /* Lookup object in advance, if it exists */
                data->segments[current].o = corto_find(
                    NULL,
                    data->segments[current].scope,
                    CORTO_FIND_DEFAULT);

                *ptr = ch;

                corto_debug("select: segment added: scope = '%s', expr = '%s', o = %p", 
                    data->segments[current].scope, data->segments[current].expr, data->segments[current].o);

                current++;
            }
            ptr++;
        } while (ch);
    }

    return 0;
}

/* Combine scope and expression, then split off id expression */
static corto_int16 corto_selectRun(corto_select_data *data) {
    corto_id fullscope;
    corto_string filter = NULL;
    corto_select_frame *frame = &data->stack[0];

    strcpy(fullscope, data->scope ? data->scope : "/");
    data->mask = CORTO_ON_SCOPE;

    if (*fullscope && strcmp(fullscope, "/") && (*data->expr != '/')) {
        strcat(fullscope, "/");
    }

    strcat(fullscope, data->expr ? data->expr : "");

    data->mask = corto_match_getScope(&data->program);

    corto_ptr_setstr(&data->fullscope, fullscope);
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
    
    /* Prepare object filter */
    data->filter = filter;
    if (filter) {
        data->filterProgram = corto_idmatch_compile(data->filter, FALSE, FALSE);
    }

    corto_debug("select: id filter = '%s'", filter);

    return 0;
error:
    return -1;
}

static corto_select_frame* corto_selectNextSegment(corto_select_data *data) {
    if (data->segments[data->segment + 1].scope) {
        corto_debug("select: evaluate segment: scope = '%s', expr = '%s'",
            data->segments[data->segment + 1].scope, 
            data->segments[data->segment + 1].expr);

        corto_select_frame *frame = &data->stack[0];
        corto_selectFilterMounts(data);
        corto_selectReset(data);
        corto_selectPrepareFrame(data, frame, ++data->segment);
        return frame;
    }
    return NULL;
}

/* Progress expressions separated by , */
static corto_bool corto_selectNextExpr(corto_select_data *data) {
    corto_bool result = FALSE;

    if (data->exprCurrent < data->exprCount) {
        data->expr = &data->expr[strlen(data->expr) + 1];
        data->exprCurrent ++;
        result = TRUE;

        corto_debug("select: evaluate expression '%s'", data->expr);

        corto_selectReset(data);
        data->segment = 0;

        if (data->program.tokens) corto_dealloc(data->program.tokens);
        if (corto_idmatchParseIntern(&data->program, data->expr, TRUE, FALSE)) {
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
    corto_select_data *data = iter->ctx;
    if (data->quit) {
        return 0;
    }

    corto_select_frame *frame = &data->stack[data->sp];

    CORTO_UNUSED(iter);

    if (data->limit) {
         if (data->limit <= data->count)
         {
              corto_debug("select: limit reached, stop iterating (%d)", data->limit);
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
    } while ((data->next == NULL) && (frame = corto_selectNextSegment(data)));

    /* If the select has been aborted, the select data likely contains data that
     * cannot yet be released. Therefore, give an application the opportunity to
     * obtain the data before returning 0, and cleaning up the select data. */

    if (!data->next) {
        corto_debug("select: no more data");
    }

    return data->quit ? 1 : data->next != NULL;
stop:
    return 0;
}

static corto_resultIter corto_selectPrepareIterator (
    struct corto_selectRequest *r)
{
    corto_select_data *data = corto_calloc(sizeof(corto_select_data));

    corto_resultIter result;
    memset(&result, 0, sizeof(corto_resultIter));

    corto_string scope = r->scope;

    if (scope && *scope) {
        if (*scope != '/') {
            /* Normalize scope to properly formatted identifier */
            data->scope = corto_asprintf("/%s", scope);
        } else {
            data->scope = corto_strdup(scope);
        }
    } else {
        /* If no scope is provided, a NULL indicates that the result of select
         * must include the root scope ('/') in the parent field of results. */
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
    data->item.flags = CORTO_RESULT_LEAF;
    data->mountAction = r->mountAction;
    data->instance = r->instance;
    data->mount = r->mount;
    data->valueAllocated = FALSE;

    if (data->contentType) {
        if (!(data->dstSer = corto_loadContentType(data->contentType))) {
            goto error;
        }
    }

    result.ctx = data;
    result.hasNext = corto_selectHasNext;
    result.next = corto_selectNext;
    result.release = corto_selectRelease;

    corto_debug("select: '%s' from '%s'", data->expr, scope);

    /* Split expression on ,. Expressions with multiple segments should be
     * evaluated sequentially. */
    char *ptr = data->expr, *prev = ptr;
    while ((ptr = strchr(ptr, ','))) {
        *ptr = '\0';
        ptr++;
        data->exprCount ++;
        corto_debug("select: expression added: '%s'", prev);
        prev = ptr;
    }
    if (!data->exprCount) {
        corto_debug("select: expression added: '%s'", data->expr);
    }
    data->exprCurrent = 0;

    if (corto_idmatchParseIntern(&data->program, data->expr, TRUE, FALSE)) {
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

static corto_select__fluent corto_select__fluentGet(void);

static corto_select__fluent corto_selectorContentType(
    corto_string contentType)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorLimit(
    corto_uint64 offset,
    corto_uint64 limit)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->offset = offset;
        request->limit = limit;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorType(
    corto_string type)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_select__fluentGet();
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

static int corto_mountAction_id(corto_mount m, corto_query *r, void *ctx) {
    CORTO_UNUSED(r);

    if (m->policy.ownership == CORTO_LOCAL_OWNER) {
        corto_select_data *data = ctx;
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

        corto_select_data *data = it.ctx;
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

static int corto_mountAction_subscribe(corto_mount m, corto_query *r, void *ctx) {
    CORTO_UNUSED(ctx);
    if (corto_getOwner() != m) {
        _corto_mount_subscribe(m, r);
    }
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

static int corto_mountAction_unsubscribe(corto_mount m, corto_query *r, void *ctx) {
    CORTO_UNUSED(ctx);
    if (corto_getOwner() != m) {
        _corto_mount_unsubscribe(m, r);
    }
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
        corto_select_data *data = ret->ctx;
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

static corto_select__fluent corto_selectorFromNow(void)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorFromTime(corto_time t)
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
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorFromSample(corto_uint64 sample)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_SAMPLE;
        request->from.value = sample;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorToNow(void)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorToTime(corto_time t)
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
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorToSample(corto_uint64 sample)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_SAMPLE;
        request->to.value = sample;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorForDuration(corto_time t)
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
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorForDepth(corto_int64 depth)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_DEPTH;
        request->to.value = depth;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorInstance(corto_object instance)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorMount(corto_mount mount)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->mount = mount;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_selectorFrom(char *scope)
{
    corto_selectRequest *request =
      corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->scope = scope;
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_select__fluentGet(void)
{
    corto_select__fluent result;
    result.from = corto_selectorFrom;
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

corto_select__fluent corto_select(
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
    
    if (expr) {
        va_start(arglist, expr);
        request->expr = corto_vasprintf(expr, arglist);
        va_end(arglist);
    }

    request->scope = NULL;
    return corto_select__fluentGet();
}
