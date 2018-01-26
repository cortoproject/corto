/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_HistoryMount_construct(
    test_HistoryMount this)
{
    corto_ll samples;
    corto_result r;

    corto_mount_setContentType(this, "text/corto");

    samples = corto_ll_new();
    corto_stringList__append(samples, "{10,11}");
    corto_stringList__append(samples, "{20,22}");

    r = (corto_result){"a", NULL, ".", "/test/Point", 0, CORTO_RESULT_LEAF};
    test_HistoryMount_data__assign(
        test_HistoryMount_dataList__append_alloc(this->history),
        &r,
        samples
    );
    corto_ll_clear(samples);
    corto_stringList__append(samples, "{30,33}");
    corto_stringList__append(samples, "{40,44}");
    corto_stringList__append(samples, "{50,55}");
    r = (corto_result){"b", NULL, ".", "/test/Point", 0, CORTO_RESULT_LEAF};
    test_HistoryMount_data__assign(
        test_HistoryMount_dataList__append_alloc(this->history),
        &r,
        samples
    );
    corto_ll_clear(samples);
    corto_stringList__append(samples, "{60,66}");
    corto_stringList__append(samples, "{70,77}");
    corto_stringList__append(samples, "{80,88}");
    corto_stringList__append(samples, "{90,99}");
    r = (corto_result){"c", NULL, ".", "/test/Point", 0, CORTO_RESULT_LEAF};
    test_HistoryMount_data__assign(
        test_HistoryMount_dataList__append_alloc(this->history),
        &r,
        samples
    );

    return corto_mount_construct(this);
}

typedef struct iterData {
    test_HistoryMount this;
    corto_frame from, to;
    uint64_t soffset, slimit;
    corto_ll history;
    corto_iter iter;
} iterData;
static
bool hasNext(
    corto_iter *it)
{
    iterData *ctx = it->ctx;
    return corto_iter_hasNext(&ctx->iter);
}

static
void* next(
    corto_iter *it)
{
    int start = 0, stop = 0, i;
    iterData *ctx = it->ctx;
    test_HistoryMount_data *data = corto_iter_next(&ctx->iter);
    corto_result *result = &data->result;
    /* Clear previous history */
    corto_sample *s;
    while ((s = corto_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    int sampleCount = corto_ll_count(data->history);

    /* Populate history list, only supporting indexes, the oldest sample being
     * index 0 */
    start = sampleCount - ctx->soffset;
    if (ctx->slimit) {
        stop = start - ctx->slimit;
    } else {
        stop = 0;
    }

    if (start < 0) start = 0;
    if (start > sampleCount) start = sampleCount;
    if (stop < 0) stop = 0;
    if (stop > sampleCount) stop = sampleCount;

    for (i = start - 1; i >= stop; i--) {
        corto_sample *s = corto_alloc(sizeof(corto_sample));
        s->timestamp.sec = i;
        s->timestamp.nanosec = 0;
        s->value = (corto_word)corto_ll_get(data->history, i);
        corto_ll_append(ctx->history, s);
    }

    result->history = corto_ll_iterAlloc(ctx->history);
    return result;
}

static
void release(
    corto_iter *it)
{
    iterData *ctx = it->ctx;
    corto_sample *s;
    while ((s = corto_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    corto_ll_free(ctx->history);
    corto_dealloc(ctx);
}

corto_resultIter test_HistoryMount_onHistoryQuery(
    test_HistoryMount this,
    corto_query *query)
{
    corto_resultIter it;

    iterData *data = corto_alloc(sizeof(iterData));
    data->this = this;
    data->from = query->timeBegin;
    data->to = query->timeEnd;
    data->soffset = query->soffset;
    data->slimit = query->slimit;
    data->iter = corto_ll_iterAlloc(this->history);
    data->history = corto_ll_new();

    it.next = next;
    it.hasNext = hasNext;
    it.release = release;
    it.ctx = data;

    return it;
}
