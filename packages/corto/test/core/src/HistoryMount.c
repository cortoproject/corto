/* $CORTO_GENERATED
 *
 * HistoryMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_HistoryMount_construct(
    test_HistoryMount this)
{
/* $begin(test/HistoryMount/construct) */
    corto_ll samples;
    corto_result r;

    corto_mount(this)->policy.readWrite = CORTO_HISTORY;
    corto_mount_setContentType(this, "text/corto");

    samples = corto_ll_new();
    corto_stringListAppend(samples, "{10,11}");
    corto_stringListAppend(samples, "{20,22}");

    r = (corto_result){"a", NULL, ".", "/test/Point", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    corto_ll_clear(samples);
    corto_stringListAppend(samples, "{30,33}");
    corto_stringListAppend(samples, "{40,44}");
    corto_stringListAppend(samples, "{50,55}");

    r = (corto_result){"b", NULL, ".", "/test/Point", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    corto_ll_clear(samples);
    corto_stringListAppend(samples, "{60,66}");
    corto_stringListAppend(samples, "{70,77}");
    corto_stringListAppend(samples, "{80,88}");
    corto_stringListAppend(samples, "{90,99}");

    r = (corto_result){"c", NULL, ".", "/test/Point", 0, TRUE};
    test_HistoryMount_dataAssign(
        test_HistoryMount_dataListAppendAlloc(this->history),
        &r,
        samples
    );

    return corto_mount_construct(this);
/* $end */
}

/* $header(test/HistoryMount/onQuery) */
typedef struct iterData {
    test_HistoryMount this;
    corto_frame from, to;
    corto_ll history;
    corto_iter iter;
} iterData;

static int hasNext(corto_iter *it) {
    iterData *ctx = it->ctx;
    return corto_iter_hasNext(&ctx->iter);
}

static void* next(corto_iter *it) {
    int start, stop, i;

    iterData *ctx = it->ctx;
    test_HistoryMount_data *data = corto_iter_next(&ctx->iter);
    corto_result *result = &data->result;

    /* Clear previous history */
    corto_sample *s;
    while ((s = corto_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    /* Populate history list, only supporting indexes, the oldest sample being
     * index 0 */
    if (ctx->from.kind == CORTO_FRAME_NOW) {
        start = corto_ll_size(data->history) - 1;
    } else if (ctx->from.kind == CORTO_FRAME_SAMPLE) {
        start = ctx->from.value;
        if (start >= corto_ll_size(data->history)) {
            start = corto_ll_size(data->history) - 1;
        }
    }
    if (ctx->to.kind == CORTO_FRAME_SAMPLE) {
        stop = ctx->to.value;
    } else if (ctx->to.kind == CORTO_FRAME_DEPTH) {
        stop = start - ctx->to.value + 1;
    }

    if (stop < 0) {
        stop = 0;
    }

    for (i = start; i >= stop; i--) {
        corto_sample *s = corto_alloc(sizeof(corto_sample));
        s->timestamp.sec = i;
        s->timestamp.nanosec = 0;
        s->value = (corto_word)corto_ll_get(data->history, i);
        corto_ll_append(ctx->history, s);
    }

    result->history = corto_ll_iterAlloc(ctx->history);
    return result;
}

static void release(corto_iter *it) {
    iterData *ctx = it->ctx;
    corto_sample *s;
    while ((s = corto_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }
    corto_ll_free(ctx->history);
    corto_dealloc(ctx);
}
/* $end */
corto_resultIter _test_HistoryMount_onQuery(
    test_HistoryMount this,
    corto_query *query)
{
/* $begin(test/HistoryMount/onQuery) */
    corto_resultIter it;

    iterData *data = corto_alloc(sizeof(iterData));
    data->this = this;
    data->from = query->timeBegin;
    data->to = query->timeEnd;
    data->iter = corto_ll_iterAlloc(this->history);
    data->history = corto_ll_new();

    it.next = next;
    it.hasNext = hasNext;
    it.release = release;
    it.ctx = data;
    
    return it;
/* $end */
}
