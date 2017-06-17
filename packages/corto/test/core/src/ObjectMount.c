/* $CORTO_GENERATED
 *
 * ObjectMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_ObjectMount_construct(
    test_ObjectMount this)
{
/* $begin(test/ObjectMount/construct) */

    corto_ptr_setstr(&corto_subscriber(this)->query.select, this->select);
    corto_ptr_setstr(&corto_subscriber(this)->query.from, this->from);
    corto_ptr_setstr(&corto_subscriber(this)->query.type, this->item.type);

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/ObjectMount/onQuery) */
struct iterCtx {
    corto_result *result;
    int count;
};

static int hasNext(corto_iter *it) {
    struct iterCtx *ctx = it->ctx;
    return !ctx->count;
}

static void* next(corto_iter *it) {
    struct iterCtx *ctx = it->ctx;
    ctx->count ++;
    return ctx->result;
}

static void release(corto_iter *it) {
    corto_dealloc(it->ctx);
}
/* $end */
corto_resultIter _test_ObjectMount_onQuery(
    test_ObjectMount this,
    corto_query *query)
{
/* $begin(test/ObjectMount/onQuery) */
    corto_iter result;

    struct iterCtx *ctx = corto_alloc(sizeof(struct iterCtx));
    ctx->result = &this->item;
    ctx->count = 0;

    result.hasNext = hasNext;
    result.next = next;
    result.release = release;
    result.ctx = ctx;

    return result;
/* $end */
}
