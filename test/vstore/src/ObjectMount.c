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
    corto_record *result;
    int count;
};

static
bool hasNext(
    ut_iter *it)
{
    struct iterCtx *ctx = it->ctx;
    return !ctx->count;
}

static
void* next(
    ut_iter *it)
{
    struct iterCtx *ctx = it->ctx;
    ctx->count ++;
    return ctx->result;
}

static
void release(
    ut_iter *it)
{
    corto_dealloc(it->ctx);
}

corto_recordIter test_ObjectMount_on_query(
    test_ObjectMount this,
    corto_query *query)
{
    ut_iter result;

    struct iterCtx *ctx = corto_alloc(sizeof(struct iterCtx));
    ctx->result = &this->item;
    ctx->count = 0;

    result.hasNext = hasNext;
    result.next = next;
    result.release = release;
    result.ctx = ctx;

    return result;
}
