/* $CORTO_GENERATED
 *
 * HistoryMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_int16 _test_HistoryMount_construct(
    test_HistoryMount this)
{
/* $begin(test/HistoryMount/construct) */
    corto_ll samples;
    corto_result r;

    corto_mount(this)->kind = CORTO_HISTORIAN;
    corto_mount_setContentType(this, "text/corto");

    samples = corto_llNew();
    corto_stringListAppend(samples, "10");
    corto_stringListAppend(samples, "20");

    r = (corto_result){"a", NULL, ".", "int32", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    corto_llClear(samples);
    corto_stringListAppend(samples, "30");
    corto_stringListAppend(samples, "40");
    corto_stringListAppend(samples, "50");

    r = (corto_result){"b", NULL, ".", "int32", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    corto_llClear(samples);
    corto_stringListAppend(samples, "60");
    corto_stringListAppend(samples, "70");
    corto_stringListAppend(samples, "80");
    corto_stringListAppend(samples, "90");

    r = (corto_result){"c", NULL, ".", "int32", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/HistoryMount/onRequest) */
typedef struct iterData {
    test_HistoryMount this;
    corto_frame from, to;
    corto_ll history;
    corto_iter iter;
} iterData;

int hasNext(corto_iter *it) {
    iterData *ctx = it->udata;
    return corto_iterHasNext(&ctx->iter);
}

void* next(corto_iter *it) {
    int start, stop, i;

    iterData *ctx = it->udata;
    test_HistoryMount_data *data = corto_iterNext(&ctx->iter);
    corto_result *result = &data->result;

    /* Clear previous history */
    corto_sample *s;
    while ((s = corto_llTakeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    /* Populate history list, only supporting indexes, the oldest sample being
     * index 0 */
    if (ctx->from.kind == CORTO_FRAME_NOW) {
        start = corto_llSize(data->history);
    } else if (ctx->from.kind == CORTO_FRAME_SAMPLE) {
        start = ctx->from.value;
    }
    if (ctx->to.kind == CORTO_FRAME_SAMPLE) {
        stop = ctx->to.value;
    } else if (ctx->to.kind == CORTO_FRAME_DEPTH) {
        stop = start - ctx->to.value;
    }

    for (i = start - 1; i >= stop; i--) {
        corto_sample *s = corto_alloc(sizeof(corto_sample));
        s->timestamp.sec = i;
        s->timestamp.nanosec = 0;
        s->value = (corto_word)corto_llGet(data->history, i);
        corto_llAppend(ctx->history, s);
    }

    result->history = corto_llIterAlloc(ctx->history);
    return result;
}

void release(corto_iter *it) {
    iterData *ctx = it->udata;
    corto_sample *s;
    while ((s = corto_llTakeFirst(ctx->history))) {
        corto_dealloc(s);
    }
    corto_llFree(ctx->history);
    corto_dealloc(ctx);
}
/* $end */
corto_resultIter _test_HistoryMount_onRequest(
    test_HistoryMount this,
    corto_request *request)
{
/* $begin(test/HistoryMount/onRequest) */
    corto_resultIter it;

    iterData *data = corto_alloc(sizeof(iterData));
    data->this = this;
    data->from = request->from;
    data->to = request->to;
    data->iter = corto_llIterAlloc(this->history);
    data->history = corto_llNew();

    it.next = next;
    it.hasNext = hasNext;
    it.release = release;
    it.udata = data;
    
    return it;
/* $end */
}
