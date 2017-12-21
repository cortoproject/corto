/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_ObjectMount_construct(
    test_ObjectMount this)
{
    corto_set_str(&corto_subscriber(this)->query.select, this->select);
    corto_set_str(&corto_subscriber(this)->query.from, this->from);
    corto_set_str(&corto_subscriber(this)->query.type, this->item.type);

    return corto_mount_construct(this);
}


struct iterCtx {
    corto_result *result;
    int count;
};

static
bool hasNext(
    corto_iter *it)
{
    struct iterCtx *ctx = it->ctx;
    return !ctx->count;
}

static
void* next(
    corto_iter *it)
{
    struct iterCtx *ctx = it->ctx;
    ctx->count ++;
    return ctx->result;
}

static
void release(
    corto_iter *it)
{
    corto_dealloc(it->ctx);
}

corto_resultIter test_ObjectMount_onQuery(
    test_ObjectMount this,
    corto_query *query)
{
    corto_iter result;

    struct iterCtx *ctx = corto_alloc(sizeof(struct iterCtx));
    ctx->result = &this->item;
    ctx->count = 0;

    result.hasNext = hasNext;
    result.next = next;
    result.release = release;
    result.ctx = ctx;

    return result;
}
