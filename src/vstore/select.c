/* Copyright (c) 2010-2018 the corto developers
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
#include "../platform/src/idmatch.h"

extern int8_t CORTO_OLS_AUGMENT;
extern corto_tls CORTO_KEY_FLUENT;

struct corto_select_data;

#define CORTO_MAX_MOUNTS_PER_SELECT (256)

typedef
int (*corto_mountAction)(
    corto_mount _this,
    corto_query *r,
    void *userData);

/* Fluent request */
typedef struct corto_selectRequest {
    int16_t err;
    const char *scope;
    corto_string expr;
    const char *type;
    const char *instanceof;
    uint64_t offset;
    uint64_t limit;
    uint64_t soffset;
    uint64_t slimit;
    const char *contentType;
    corto_frame from;
    corto_frame to;
    corto_mountAction mountAction;
    corto_object instance;
    corto_mount mount;
    corto_mountMask mountMask;
    bool isHistoricalQuery;
    bool queryVstore;
    bool queryStore;
    bool yield_unknown;
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

    int32_t locationLength; /* Restore query when leaving frame */
    uint8_t firstMount; /* First mount loaded for frame */
    int8_t currentMount; /* Current mount being evaluated */
} corto_select_frame;

struct corto_select_data {
    corto_string scope;                      /* Scope passed to select */
    corto_string expr;                       /* Current expression */
    corto_string exprStart;                  /* Points to start of full expr */
    const char *contentType;

    /* Object filter */
    corto_string filter;
    corto_idmatch_program filterProgram;   /* Parsed program */

    /* Which expression is being evaluated (when expression contains ,) */
    uint32_t exprCount;
    uint32_t exprCurrent;

    corto_string fullscope;         /* Scope + scope part of expression */
    corto_select_segment segments[CORTO_MAX_SCOPE_DEPTH]; /* Scopes to walk (parsed scope) */
    uint32_t segment;               /* Scope currently being walked */

    struct corto_idmatch_program_s program;   /* Parsed program */

    corto_select_frame stack[CORTO_MAX_SCOPE_DEPTH]; /* Execution stack */
    uint8_t sp;
    corto_eventMask mask;
    corto_mountMask mountMask;

    /* Mounts currently loaded */
    corto_mount mounts[CORTO_MAX_MOUNTS_PER_SELECT];

    /* Mounts with outstanding requests */
    int16_t mountsLoaded;

    /* Serializer for requested content type */
    corto_fmt dstSer;

    /* Limit results */
    uint64_t offset;
    uint64_t limit;
    uint64_t soffset;
    uint64_t slimit;
    uint64_t count;
    uint64_t skip;

    /* History */
    corto_frame from;
    corto_frame to;
    bool isHistoricalQuery;
    bool queryVstore;
    bool queryStore;
    bool yield_unknown;

    /* Filters */
    corto_string typeFilter;
    corto_idmatch_program typeFilterProgram;   /* Parsed program */
    corto_type instanceof;

    /* Full path representing the current location of select */
    corto_id location;

    /* Does select need to resume objects */
    bool resume;
    bool resumeKeep;

    /* Additional action to be performed when data is requested from mount */
    corto_mountAction mountAction;

    /* Indicates if the walk should stop */
    bool quit;
    bool *quitPtr; /* If quit was not set to TRUE, this structure will be
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
    bool valueAllocated;
    corto_selectHistoryIter_t historyIterData;
    corto_result *next;
};

static
corto_mount corto_selectCurrentMount(
    corto_select_data *data)
{
    return data->mounts[data->stack[data->sp].currentMount - 1];
}

static
corto_fmt corto_selectSrcContentType(
    corto_select_data *data)
{
    return (corto_fmt)
      data->mounts[data->stack[data->sp].currentMount - 1]->contentTypeOutHandle;
}

static
int16_t corto_selectConvert(
    corto_select_data *data,
    corto_string type,
    uintptr_t *dst,
    uintptr_t src,
    bool *converted)
{
    corto_mount mount = corto_selectCurrentMount(data);
    corto_fmt srcType = corto_selectSrcContentType(data);
    void *dst_value = (void*)*dst;
    bool should_convert = false;

    if (!srcType && dst_value) {
        corto_warning("mount '%s' provides value but no contentType",
            corto_fullpath(NULL,
                data->mounts[data->stack[data->sp].currentMount - 1]));
        goto error;
    }

    corto_fmt_opt src_opt = {
        .from = mount->super.query.from
    };
    corto_fmt_opt dst_opt = {
        .from = data->scope
    };

    bool different_from = false, different_fmt = false;
    if (srcType && data->dstSer) {
        if (src_opt.from && dst_opt.from) {
            different_from = strcmp(src_opt.from, dst_opt.from) != 0;
        } else if (src_opt.from || dst_opt.from) {
            different_from = true;
        }
        different_fmt = srcType != data->dstSer;
    }

    should_convert = different_from || different_fmt;

    /* If source serializer is loaded, a conversion is needed */
    if (src && (different_from || different_fmt)) {
        corto_type t = corto_type(corto_resolve(NULL, type));
        if (!t) {
            corto_throw("unresolved type '%s'", type);
            goto error;
        } else {
            if (different_fmt || t->flags & CORTO_TYPE_HAS_REFERENCES) {
                if (dst_value) {
                    corto_fmt_release(data->dstSer, dst_value);
                }

                void *intermediate = corto_mem_new(t);

                /* Convert from source format to object */
                corto_value v = corto_value_mem(intermediate, t);
                if (corto_fmt_to_value(srcType, &src_opt, &v, (char*)src)) {
                    corto_throw("failed to convert value to '%s'", type);
                    goto error;
                }

                /* Convert from object to destination format */
                if (!(*dst = (uintptr_t)corto_fmt_from_value(
                    data->dstSer, &dst_opt, &v)))
                {
                    corto_throw(
                        "failed to convert value to '%s'", data->contentType);
                    goto error;
                }

                corto_mem_free(intermediate);
            } else {
                /* If value doesn't contain any references and is of the same
                 * format, there's no point in converting */
                should_convert = false;
            }
        }
    }

    if (!should_convert) {
        /* If formats are equal, just pass through */
        *dst = src;
    }

    if (converted) *converted = should_convert;

    return 0;
error:
    return -1;
}

static
void corto_setItemData(
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
    corto_path_offset(item->parent, from, to, -1, true);

    if (corto_idof(o)) {
        strcpy(item->id, corto_idof(o));
        corto_nameof(item->name, o);
    } else {
        item->id[0] = '\0';
        item->name[0] = '\0';
    }

    item->owner = corto_sourceof(o);
    corto_set_ref(&item->object, o);

    if (corto_check_attr(corto_typeof(o), CORTO_ATTR_NAMED)) {
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
        corto_fmt_opt dst_opt = {
            .from = data->scope
        };
        if (item->value) {
            corto_fmt_release(data->dstSer, (void*)item->value);
        }

        corto_value v = corto_value_object(o, NULL);
        item->value =
            (uintptr_t)corto_fmt_from_value(data->dstSer, &dst_opt, &v);
    }

    item->flags = 0;

    if (!corto_scope_size(o)) {
        item->flags = CORTO_RESULT_LEAF;
    }

    if (corto_typeof(o) == corto_unknown_o) {
        if (!data->yield_unknown) {
            item->flags |= CORTO_RESULT_HIDDEN;
        }
    }
}

static
bool corto_selectMatch(
    corto_object o,
    corto_result *item,
    corto_select_data *data)
{
    bool result = TRUE;
    char *id = o ? corto_idof(o) : item->id;

    /* If item is hidden, it will not be shown to the application but is just
     * used to indicate that a mount has objects at a deeper nesting level. It
     * is therefore not required to apply filters */
    if (item->flags & CORTO_RESULT_HIDDEN) {
        return true;
    }

    if (corto_secured()) {
        if (o) {
            if (!corto_authorize(o, CORTO_SECURE_ACTION_READ)) {
                corto_debug("no read access: %s", corto_fullpath(NULL, o));
                goto access_error;
            }
        } else {
            corto_id id;
            sprintf(id, "%s/%s/%s", data->scope, item->parent, item->id);
            corto_path_clean(id, id);
            if (!corto_authorize_id(id, CORTO_SECURE_ACTION_READ)) {
                corto_debug("no read access: %s", id);
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
            int32_t i;

            for (i = 0; i < data->mountsLoaded; i++) {
                corto_mount r = data->mounts[i];
                corto_string rType = r->super.query.type;

                /* If a SINK mount doesn't implement the on_query method, select will
                 * return the contents of the object store */
                if ((r->policy.ownership == CORTO_LOCAL_SOURCE) && !r->passThrough) {
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
                        if (corto_check_attr(o, r->attr)) {
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
                    result = corto_idmatch_run(data->typeFilterProgram, type);
                } else {
                    result = FALSE;
                }
            } else {
                result = corto_idmatch_run(data->typeFilterProgram, type);
            }
        }

        if (result && data->instanceof) {
            corto_type type = NULL;
            if (o) {
                type = corto_typeof(o);
            } else {
                type = corto_resolve(NULL, item->type);
            }
            result = corto_type_instanceof(data->instanceof, type);
            if (!o) {
                corto_release(type);
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
    if (data->mountAction || (!data->quit && data->queryVstore)) {
        char *expr = data->mask == CORTO_ON_TREE ? "*" : data->filter ? data->filter : "*";
        corto_query *q = &corto_subscriber(mount)->query;
        char *parent = corto_selectRelativeParent(q, data);

        corto_debug("query (select='%s' from='%s') mount '%s', location '%s'",
          expr,
          parent,
          corto_fullpath(NULL, mount),
          data->location);

        corto_query r = {
          .from = parent,
          .select = expr,
          .type = data->type,
          .offset = (data->offset > data->count) ? data->offset - data->count : 0,
          .limit = (data->offset > data->count || !data->limit) ? data->limit : data->limit - (data->offset - data->count),
          .soffset = data->soffset,
          .slimit = data->slimit,
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
        if (data->quit || !data->queryVstore) {
            return CORTO_ITER_EMPTY;
        } else {
            if (data->isHistoricalQuery) {
                return corto_mount_historyQuery(mount, &r);
            } else {
                return corto_mount_query(mount, &r);
            }
        }
    } else {
        return CORTO_ITER_EMPTY;
    }
}

static
bool corto_selectHistoryHasNext(
    corto_iter *it)
{
    corto_selectHistoryIter_t *ctx = it->ctx;
    return corto_iter_hasNext(&ctx->iter);
}

static
void* corto_selectHistoryNext(
    corto_iter *it)
{
    corto_selectHistoryIter_t *ctx = it->ctx;
    corto_sample *s = corto_iter_next(&ctx->iter);

    corto_selectConvert(
        ctx->data,
        ctx->data->item.type,
        &ctx->sample.value,
        s->value,
        NULL); /* Wouldn't be here if we didn't need a conversion */

    ctx->sample.timestamp = s->timestamp;

    return &ctx->sample;
}

static
void corto_selectHistoryRelease(
    corto_iter *it)
{
    corto_selectHistoryIter_t *ctx = it->ctx;

    if (ctx->sample.value) {
        corto_fmt_release(ctx->data->dstSer, (void*)ctx->sample.value);
    }

    corto_iter_release(&ctx->iter);

    ctx->data->item.history.ctx = NULL;
}

static
bool corto_selectIterMount(
    corto_select_data *data,
    corto_select_frame *frame)
{
    corto_id rpath;
    corto_mount mount = data->mounts[frame->currentMount - 1];

    corto_result *result = corto_iter_next(&frame->iter);
    if (!result) {
        corto_critical("mount iterator returned NULL");
    }

    corto_assert(result->id != NULL, "mount '%s' returns result without id", corto_fullpath(NULL, mount));
    corto_assert(result->parent != NULL, "mount '%s' returns result without parent", corto_fullpath(NULL, mount));
    corto_assert(result->type != NULL, "mount '%s' returns result without type", corto_fullpath(NULL, mount));
    corto_assert(result->type[0] != 0, "mount '%s' returns result with empty type", corto_fullpath(NULL, mount));

    char *local_parent = result->parent;

    /* Mounts never return absolute paths, so interpret '/' as '.' */
    if (local_parent[0] == '/') {
        local_parent ++;
    }
    if (!local_parent[0]) {
        local_parent = ".";
    }

    corto_debug(
        "mount returned (id = '%s', parent = '%s' type = '%s' leaf = '%s')",
        result->id, local_parent, result->type, result->flags & CORTO_RESULT_LEAF ? "true" : "false");

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

        if (strcmp(parent, local_parent)) {
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

    if (local_parent) {
        corto_id path;
        strcpy(path, data->scope ? data->scope : "");
        strcpy(rpath, corto_subscriber(mount)->query.from);
        strcat(rpath, "/");
        strcat(rpath, local_parent);
        corto_path_clean(rpath, rpath);
        corto_path_offset(data->item.parent, path, rpath, -1, true);
    } else {
        data->item.parent[0] = '\0';
    }

    if (result->type) {
        strcpy(data->item.type, result->type);
    } else {
        data->item.type[0] = '\0';
    }

    /* Translate format if necessary */
    if (corto_selectConvert(
      data,
      result->type, /* type of result */
      &data->item.value, /* src */
      result->value, /* dst */
      &data->valueAllocated)) /* converted or not */
    {
        corto_throw(NULL);
        goto error;
    }

    /* Wrap history iterator in other iterator that converts contentType */
    if (data->valueAllocated) {
        data->item.history.hasNext = corto_selectHistoryHasNext;
        data->item.history.next = corto_selectHistoryNext;
        data->item.history.release = corto_selectHistoryRelease;
        data->item.history.ctx = &data->historyIterData;
        data->historyIterData.iter = result->history;
        data->historyIterData.data = data;
        data->historyIterData.sample.value = 0;
    } else {
        /* Otherwise just assign iterator */
        data->item.history = result->history;
    }

    if (data->resume) {
        corto_type type = NULL;

        corto_trace("resuming '%s/%s' of type '%s'",
            local_parent, result->id, result->type);

        if (corto_observer(mount)->type) {
            corto_set_ref(&type, corto_observer(mount)->type);
        } else {
            if (!(type = corto_resolve(NULL, result->type))) {
                corto_warning(
                    "could not resume '%s/%s' from '%s': type '%s not found",
                  local_parent,
                  result->id,
                  corto_fullpath(NULL, mount),
                  result->type);
            }
        }

        corto_object parent = corto_lookup(NULL, rpath);
        if (!parent) {
            corto_warning(
              "could not resume '%s/%s' from '%s': parent '%s' not available",
              local_parent,
              result->id,
              corto_fullpath(NULL, mount),
              rpath);
            corto_release(type);
            goto error;
        }

        corto_fmt fmt_handle = (corto_fmt)mount->contentTypeOutHandle;
        corto_object prev = corto_set_source(mount);
        corto_object ref = corto(CORTO_DECLARE|CORTO_DEFINE|CORTO_FORCE_TYPE|CORTO_UNSECURED, {
            .parent = parent,
            .id = result->id,
            .type = type,
            .fmt = fmt_handle,
            .value = (void*)result->value
        });
        corto_set_source(prev);
        corto_release(type);
        corto_release(parent);

        if (!ref) {
            corto_warning(
              "could not resume '%s/%s' from mount '%s'",
              local_parent,
              result->id,
              corto_fullpath(NULL, mount));
            goto error;
        }

        corto_ok("resumed '%s'", corto_fullpath(NULL, ref));

        corto_set_ref(&data->item.object, ref);
        if (!data->resumeKeep) {
            corto_release(ref);
        }
    }

error:
    return true;
noMatch:
    return false;
}

static
bool corto_selectIterNext(
    corto_select_data *data,
    corto_select_frame *frame,
    corto_object *o_out,
    corto_string lastKey)
{
    bool hasData = FALSE;
    corto_object result = NULL;

    *o_out = NULL;

    /* Select data from scope */
    if (data->queryStore && frame->o) {

        /* Don't walk over objects if a frame contains a expr or if the
         * frame is already walking over a mount */
        if (!frame->cur->expr && (frame->currentMount == frame->firstMount)) {
            corto_scope_lock(frame->o);

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
            corto_scope_unlock(frame->o);
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
             * match the select query. Try next mount */
            if (!hasData) retry = true;
        }
    } while (retry);

    return hasData;
}

/* Evaluate whether mount for specific scope should be loaded */
static
int corto_selectLoadMountWalk(
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
    if (data->isHistoricalQuery) {
        if (!(mount->policy.mask & CORTO_MOUNT_HISTORY_QUERY)) {
            return 1;
        }
    } else if (data->mountMask) {
        if (!(mount->policy.mask & data->mountMask)) {
            return 1;
        }
    } else {
        /* If it is a normal query but the mask does not specify QUERY, the mount
         * should not be loaded */
        if (!(mount->policy.mask & CORTO_MOUNT_QUERY)) {
            return 1;
        }
    }

    /* If type is requested, test whether it matches with the mount type */
    corto_string rType = mount->super.query.type;
    if (data->typeFilter && strlen(data->typeFilter) && rType) {
        if (!data->typeFilterProgram) {
            corto_warning("type filter '%s' specified, but program is NULL", data->typeFilter);
        } else if (!corto_idmatch_run(data->typeFilterProgram, rType)) {
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
        corto_throw("number of mounts exceeded (%d) for request",
            CORTO_MAX_MOUNTS_PER_SELECT);
        return 0;
    }

    /* Mount should be loaded */
    data->mounts[data->mountsLoaded] = mount;
    data->mountsLoaded ++;

    corto_debug("add mount '%s' of type = '%s', mountsLoaded = %d",
      corto_fullpath(NULL, mount),
      corto_fullpath(NULL, corto_typeof(mount)),
      data->mountsLoaded);

    return 1;
}

/* Load mounts for a frame */
static
int16_t corto_selectLoadMounts(
    corto_select_data *data,
    corto_select_frame *frame)
{
    bool recursive = !frame->cur->expr && data->mask == CORTO_ON_TREE;
    data->mountsLoaded = 0;

    /* Count mounts registered on parent scopes. Mounts loaded for this frame
     * will be appended to the mounts array. */
    while (data->mounts[data->mountsLoaded]) {
        data->mountsLoaded ++;
    }

    /* Keep track of current mount and the first mount loaded by this frame */
    frame->currentMount = data->mountsLoaded;
    frame->firstMount = data->mountsLoaded;

    corto_debug("look for mounts in '%s'%s",
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
static
int16_t corto_selectTree(
    corto_select_data *data,
    corto_select_frame *frame)
{
    /* Keep track of the last key for when a tree changed while iterating over
     * it. When a change occurred, the iterator's current position can be no
     * longer valid. corto_selectIterNext will in that case iterate up to the
     * object after the last key. */
    corto_string lastKey = data->item.name;
    bool match = false;
    data->next = NULL;
    corto_object o = NULL;

    if (data->quit) {
        return 0;
    }

    corto_debug("iterate frame %d (scope = '%s', expr = '%s', location = '%s')",
            data->sp, frame->cur->scope, frame->cur->expr, data->location);

    do {
        corto_resultMask flags = CORTO_RESULT_LEAF, hasData = FALSE;

        /* Unwind stack for depleted iterators */
        while (!(hasData = corto_selectIterNext(data, frame, &o, lastKey)) &&
            data->sp && !data->quit)
        {
            /* Cache name as next line might delete object */
            if (frame->o) {
                strcpy(data->item.name, corto_idof(frame->o));
                corto_set_ref(&frame->o, NULL);
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
                    match = true;
                    corto_setItemData(o, data->next, data);
                    flags = data->next->flags;
                } else {
                    data->skip ++;
                    flags = 0;
                }
            } else {
                /* If doing a lookup on a tree, select requests all objects from
                 * a mount and thus needs to perform matching. If not, select
                 * will pass the filter to the mount, and the mount is expected
                 * to only return matching objects. */
                if (data->mask != CORTO_ON_TREE) {
                    match = true;
                } else {
                    match = corto_selectMatch(NULL, &data->item, data);
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
                corto_set_ref(&frame->o, o);

                if (o) {
                    corto_rb scope = corto_scopeof(o);
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

                    corto_debug("moved to '%s'", data->location);
                }
            }

            /* If result is hidden, skip */
            if (flags & CORTO_RESULT_HIDDEN) {
                match = false;
                if (data->mask == CORTO_ON_SELF) {
                    data->next = NULL;
                }
            }
        } else {
            data->next = NULL;
        }

        if (match && (data->mask == CORTO_ON_SELF)) {
            data->mask = 0;
        }

        if (o) corto_release(o);
    } while (!match && data->next && !data->quit);

    return 0;
}

/* Reset select data (either initially or when moving to next scope) */
static
void corto_selectReset(
    corto_select_data *data)
{
    if (data->item.value && data->dstSer && data->valueAllocated) {
        corto_fmt_release(data->dstSer, (void*)data->item.value);
    }

    if (data->item.object) {
        corto_set_ref(&data->item.object, NULL);
    }

    if (data->item.history.release) {
        data->item.history.release(&data->item.history);
        data->item.history.ctx = 0;
    }

    data->sp = 0;
    data->item.value = 0;
    data->mountsLoaded = -1;
}

static
int16_t corto_selectPrepareFrame(
    corto_select_data *data,
    corto_select_frame *frame,
    uint32_t segment)
{
    frame->cur = &data->segments[segment];
    corto_set_ref(&frame->o, frame->cur->o);
    frame->currentMount = 0;
    frame->firstMount = 0;

    if (frame->o) {
        corto_rb tree = corto_scopeof(frame->o);
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
static
void corto_selectFilterMounts(
    corto_select_data *data)
{
    int32_t i = 0;

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

static
void* corto_selectNext(
    corto_resultIter *iter)
{
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    corto_log_push("next");

    if (data->next) {
        corto_trace("yield (id: '%s', from: '%s', type: '%s', ref: %p)",
            data->next->id,
            data->next->parent,
            data->next->type,
            data->next->object);
        data->count ++;
    }

    corto_log_pop();

    return data->next;
}

static
void* corto_selectNextObjects(
    corto_objectIter *iter)
{
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    if (data->next) {
        corto_debug("NextObject (%s, %s)", data->next->id, data->next->parent);
        data->count ++;
    }

    return data->next->object;
}

static
void corto_selectRelease(
    corto_iter *iter)
{
    corto_select_data *data = iter->ctx;

    CORTO_UNUSED(iter);

    if (data->exprStart) corto_dealloc(data->exprStart);
    if (data->program.tokens) corto_dealloc(data->program.tokens);
    if (data->scope) corto_dealloc(data->scope);
    if (data->fullscope) corto_dealloc(data->fullscope);
    if (data->filterProgram) corto_idmatch_free(data->filterProgram);
    if (data->typeFilterProgram) corto_idmatch_free(data->typeFilterProgram);
    if (data->instanceof) corto_release(data->instanceof);

    /* Free iterators */
    int32_t i;
    for (i = 0; i <= data->sp; i ++) {
        corto_set_ref(&data->stack[i].o, NULL);
        corto_iter_release(&data->stack[i].iter);
    }

    /* Free segments */
    i = 0;
    while (data->segments[i].scope) {
        corto_set_str(&data->segments[i].scope, NULL);
        corto_set_str(&data->segments[i].expr, NULL);
        corto_set_ref(&data->segments[i].o, NULL);
        i++;
    }

    corto_selectReset(data);

    data->expr = NULL;
    data->program.tokens = NULL;
    data->item.value = 0;
    corto_dealloc(data);

    _corto_log_pop(__FILE__, __LINE__, "corto_select");
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
static
int16_t corto_selectSplitScope(
    corto_select_data *data)
{
    memset(data->segments, 0, sizeof(data->segments));

    char *ptr, ch;
    uint32_t current = 0;
    corto_id scope;
    strcpy(scope, data->fullscope);

    ptr = scope;

    if (ptr[0] == '/') {
        ptr ++;
    }

    /* Set first scope to root */
    corto_set_str(&data->segments[0].scope, "/");
    corto_set_str(&data->segments[0].expr, *ptr ? ptr : NULL);
    corto_set_ref(&data->segments[0].o, root_o);
    current ++;

    corto_debug("segment added: scope = '%s', expr = '%s', o = %p",
        data->segments[0].scope, data->segments[0].expr, data->segments[0].o);

    if (ptr[0]) {
        do {
            ch = *ptr;
            if ((!ch && ptr != scope) || ch == '/') {
                *ptr = '\0';

                corto_set_str(&data->segments[current].scope, scope);
                corto_set_str(&data->segments[current].expr, ch ? ptr + 1 : NULL);

                /* Lookup object in advance, if it exists */
                data->segments[current].o = corto(CORTO_LOOKUP|CORTO_UNSECURED, {
                    .parent = root_o, .id = data->segments[current].scope
                });

                *ptr = ch;

                corto_debug("segment added: scope = '%s', expr = '%s', o = %p",
                    data->segments[current].scope, data->segments[current].expr, data->segments[current].o);

                current++;
            }
            ptr++;
        } while (ch);
    }

    return 0;
}

/* Combine scope and expression, then split off id expression */
static
int16_t corto_selectRun(
    corto_select_data *data)
{
    corto_id fullscope;
    corto_string filter = NULL;
    corto_select_frame *frame = &data->stack[0];

    strcpy(fullscope, data->scope ? data->scope : "/");
    data->mask = CORTO_ON_SCOPE;

    if (*fullscope && strcmp(fullscope, "/") && (*data->expr != '/')) {
        strcat(fullscope, "/");
    }

    strcat(fullscope, data->expr ? data->expr : "");
    int scope = corto_idmatch_get_scope(&data->program);
    data->mask = scope == 2 ? CORTO_ON_TREE
               : scope == 1 ? CORTO_ON_SCOPE
               : CORTO_ON_SELF;

    corto_set_str(&data->fullscope, fullscope);
    corto_path_clean(data->fullscope, data->fullscope);

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

    corto_debug("id filter = '%s'", filter);

    return 0;
error:
    return -1;
}

static
corto_select_frame* corto_selectNextSegment(
    corto_select_data *data)
{
    if (data->segments[data->segment + 1].scope) {
        corto_debug("evaluate segment: scope = '%s', expr = '%s'",
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
static
bool corto_selectNextExpr(
    corto_select_data *data)
{
    bool result = FALSE;

    if (data->exprCurrent < data->exprCount) {
        data->expr = &data->expr[strlen(data->expr) + 1];
        data->exprCurrent ++;
        result = TRUE;

        corto_debug("evaluate expression '%s'", data->expr);

        corto_selectReset(data);
        data->segment = 0;

        if (data->program.tokens) corto_dealloc(data->program.tokens);
        if (corto_idmatchParseIntern(&data->program, data->expr, TRUE, FALSE)) {
            corto_throw("select '%s' failed", data->expr);
            goto error;
        }

        if (corto_selectRun(data)) {
            corto_throw("select '%s' failed", data->expr);
            goto error;
        }
    }

    return result;
error:
    return FALSE;
}

static
bool corto_selectHasNext(corto_resultIter *iter) {
    corto_select_data *data = iter->ctx;
    if (data->quit) {
        return 0;
    }

    corto_log_push("hasNext");

    corto_select_frame *frame = &data->stack[data->sp];

    CORTO_UNUSED(iter);

    if (data->limit) {
         if (data->limit <= data->count)
         {
              corto_debug("limit reached, stop iterating (%d)", data->limit);
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
        goto stop;
    }

    corto_log_pop();
    return data->quit ? 1 : data->next != NULL;
stop:
    corto_debug("no more data");
    corto_log_pop();
    return 0;
}

static
corto_resultIter corto_selectPrepareIterator (
    struct corto_selectRequest *r)
{
    corto_select_data *data = corto_calloc(sizeof(corto_select_data));

    corto_resultIter result;
    memset(&result, 0, sizeof(corto_resultIter));

    const char *scope = r->scope;

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
    if (r->type && strlen(r->type)) {
        data->typeFilter = strdup(r->type);
    } else {
        data->typeFilter = NULL;
    }
    if (r->instanceof) {
        data->instanceof = corto_resolve(NULL, r->instanceof);
        if (!data->instanceof) {
            corto_throw("type '%s' specified in instanceof not found", r->instanceof);
            goto error;
        }
    }
    data->soffset = r->soffset;
    data->slimit = r->slimit;
    data->from = r->from;
    data->to = r->to;
    data->isHistoricalQuery = r->isHistoricalQuery;
    data->queryStore = r->queryStore;
    data->queryVstore = r->queryVstore;
    data->yield_unknown = r->yield_unknown;
    data->item.parent = data->parent;
    data->item.name = data->name;
    data->item.type = data->type;
    data->item.id = data->id;
    data->item.flags = CORTO_RESULT_LEAF;
    data->mountAction = r->mountAction;
    data->instance = r->instance;
    data->mount = r->mount;
    data->valueAllocated = FALSE;
    data->mountMask = r->mountMask;

    if (data->contentType) {
        if (!(data->dstSer = corto_fmt_lookup(data->contentType))) {
            goto error;
        }
    }

    result.ctx = data;
    result.hasNext = corto_selectHasNext;
    result.next = corto_selectNext;
    result.release = corto_selectRelease;

    /* Split expression on ,. Expressions with multiple segments should be
     * evaluated sequentially. */
    char *ptr = data->expr, *prev = ptr;
    (void)prev;
    while ((ptr = strchr(ptr, ','))) {
        *ptr = '\0';
        ptr++;
        data->exprCount ++;
        corto_debug("expression added: '%s'", prev);
        prev = ptr;
    }
    if (!data->exprCount) {
        corto_debug("expression added: '%s'", data->expr);
    }
    data->exprCurrent = 0;

    if (corto_idmatchParseIntern(&data->program, data->expr, TRUE, FALSE)) {
        corto_throw("select failed");
        goto error;
    }

    /* Prepare type filter */
    if (data->typeFilter) {
        data->typeFilterProgram = corto_idmatch_compile(data->typeFilter, TRUE, TRUE);
    }

    if (corto_selectRun(data)) {
        goto error;
    }

    return result;
error:
    r->err = 1;
    return result;
}

static
corto_select__fluent corto_select__fluentGet(void);

static
corto_select__fluent corto_selectorContentType(
    const char *contentType)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("CONTENTTYPE '%s'", contentType);
        request->contentType = contentType;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorOffset(
    uint64_t offset)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->offset = offset;
        corto_debug("OFFSET %llu", offset);
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorLimit(
    uint64_t limit)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("LIMIT %llu", limit);
        request->limit = limit;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorSlimit(
    uint64_t limit)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->slimit = limit;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorSoffset(
    uint64_t offset)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->soffset = offset;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorType(
    const char *type)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("TYPE '%s'", type);
        request->type = type;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorInstanceof(
    const char *instanceof)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("INSTANCEOF '%s'", instanceof);
        request->instanceof = instanceof;
    }
    return corto_select__fluentGet();
}

static
int16_t corto_selectorIter(
    corto_resultIter *ret)
{
    corto_assert(ret != NULL, "no iterator provided to .iter()");

    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("ITER");
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

static
int corto_mountAction_id(
    corto_mount m,
    corto_query *r,
    void *ctx)
{
    CORTO_UNUSED(r);

    if (m->policy.ownership == CORTO_LOCAL_SOURCE) {
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

static
corto_string corto_selectorId(void)
{
    corto_string result = NULL;
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);

    if (request) {
        bool quit = FALSE;
        corto_debug("ID");
        request->mountMask = CORTO_MOUNT_ID;
        request->mountAction = corto_mountAction_id;
        request->queryStore = false;
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

static
int corto_mountAction_subscribe(
    corto_mount m,
    corto_query *r,
    void *ctx)
{
    CORTO_UNUSED(ctx);
    if (corto_get_source() != m) {
        _corto_mount_subscribe(m, r);
    }
    return 1;
}

static
int16_t corto_selectorSubscribe(
    corto_resultIter *ret)
{
    corto_assert(ret != NULL, "no iterator provided to .subscribe()");

    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("SUBSCRIBE");
        request->mountAction = corto_mountAction_subscribe;
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

static
int corto_mountAction_unsubscribe(
    corto_mount m,
    corto_query *r,
    void *ctx)
{
    CORTO_UNUSED(ctx);
    if (corto_get_source() != m) {
        _corto_mount_unsubscribe(m, r);
    }
    return 1;
}

static
int16_t corto_selectorUnsubscribe(void)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("UNSUBSCRIBE");
        request->mountAction = corto_mountAction_unsubscribe;
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

static
int16_t corto_selectorIterObjects(
    corto_objectIter *ret)
{
    corto_assert(ret != NULL, "no iterator provided to .iter()");

    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);

    if (request) {
        corto_debug("ITER_OBJECTS");
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
        *ret = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);

        corto_select_data *data = ret->ctx;
        data->resume = TRUE;

        /* Override iterator callbacks for object iterator */
        ret->next = corto_selectNextObjects;
    }

    return 0;
error:
    return -1;
}

static
int16_t corto_selectorResume(void)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);

    if (request) {
        corto_debug("RESUME");
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
        corto_iter it = corto_selectPrepareIterator(request);
        if (request->err) {
            goto error;
        }
        corto_dealloc(request);

        corto_select_data *data = it.ctx;
        data->resume = TRUE;
        data->resumeKeep = TRUE;

        /* Iterate over objects to resume them in the store */
        while (corto_iter_hasNext(&it)) {
            corto_result *r = corto_iter_next(&it);
            if (r->object) {
                corto_claim(r->object);
            }
        }
    }

    return 0;
error:
    return -1;
}

static
int64_t corto_selectorCount()
{
    corto_resultIter it;
    uint64_t count = 0;

    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);

    if (request) {
        corto_debug("COUNT");
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

static
corto_select__fluent corto_selectorFromNow(void)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorFromTime(
    corto_time t)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->from.kind = CORTO_FRAME_TIME;
        union {
            corto_time t;
            uint64_t i;
        } toInt;
        toInt.t = t;
        request->from.value = toInt.i;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorToNow(void)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_NOW;
        request->from.value = 0;
        request->isHistoricalQuery = true;

    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorToTime(
    corto_time t)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_TIME;
        union {
            corto_time t;
            uint64_t i;
        } toInt;
        toInt.t = t;
        request->to.value = toInt.i;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorForDuration(
    corto_time t)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->to.kind = CORTO_FRAME_DURATION;
        union {
            corto_time t;
            uint64_t i;
        } toInt;
        toInt.t = t;
        request->to.value = toInt.i;
        request->isHistoricalQuery = true;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorInstance(
    corto_object instance)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("INSTANCE '%s'", corto_fullpath(NULL, instance));
        request->instance = instance;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorMount(
    corto_mount mount)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        corto_debug("MOUNT '%s'", corto_fullpath(NULL, mount));
        request->mount = mount;
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorFrom(
    const char *scope)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->scope = scope;
        corto_debug("FROM '%s'", scope);
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorVstore(
    bool enable)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->queryVstore = enable;
        corto_debug("QUERY_VSTORE '%s'", enable ? "true" : "false");
    }
    return corto_select__fluentGet();
}

static
corto_select__fluent corto_selectorYieldUnknown(void)
{
    corto_selectRequest *request =
      corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->yield_unknown = true;
        corto_debug("YIELD_UNKNOWN 'true'");
    }
    return corto_select__fluentGet();
}

static corto_select__fluent corto_select__fluentGet(void)
{
    corto_select__fluent result;
    result.from = corto_selectorFrom;
    result.contentType = corto_selectorContentType;
    result.offset = corto_selectorOffset;
    result.limit = corto_selectorLimit;
    result.soffset = corto_selectorSoffset;
    result.slimit = corto_selectorSlimit;
    result.type = corto_selectorType;
    result.instanceof = corto_selectorInstanceof;
    result.fromNow = corto_selectorFromNow;
    result.fromTime = corto_selectorFromTime;
    result.toNow = corto_selectorToNow;
    result.toTime = corto_selectorToTime;
    result.forDuration = corto_selectorForDuration;
    result.iter = corto_selectorIter;
    result.subscribe = corto_selectorSubscribe;
    result.unsubscribe = corto_selectorUnsubscribe;
    result.id = corto_selectorId;
    result.resume = corto_selectorResume;
    result.iter_objects = corto_selectorIterObjects;
    result.count = corto_selectorCount;
    result.instance = corto_selectorInstance;
    result.mount = corto_selectorMount;
    result.vstore = corto_selectorVstore;
    result.yield_unknown = corto_selectorYieldUnknown;
    return result;
}

corto_select__fluent corto_select(
    const char *expr,
    ...)
{
    va_list arglist;

    corto_selectRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_selectRequest));
        corto_tls_set(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_selectRequest));
    }

    request->queryStore = true;
    request->queryVstore = true;

    if (expr) {
        va_start(arglist, expr);
        request->expr = corto_vasprintf(expr, arglist);
        va_end(arglist);
    }

    corto_log_push("select");
    corto_debug(strarg("SELECT '%s'", request->expr));

    request->scope = NULL;
    return corto_select__fluentGet();
}
