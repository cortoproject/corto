/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_HistoryMount_construct(
    test_HistoryMount this)
{
    ut_ll samples;
    corto_record r;

    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (!this->mount && corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_set_ref(&this->mount, this);
    }
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_mount_set_format(this, "text/corto");

    samples = ut_ll_new();
    corto_stringList__append(samples, "{10,11}");
    corto_stringList__append(samples, "{20,22}");

    r = (corto_record){"a", NULL, ".", "/test/Point", 0, CORTO_RECORD_LEAF};
    test_HistoryMount_data__assign(
        test_HistoryMount_dataList__append_alloc(this->history),
        &r,
        samples
    );
    ut_ll_clear(samples);
    corto_stringList__append(samples, "{30,33}");
    corto_stringList__append(samples, "{40,44}");
    corto_stringList__append(samples, "{50,55}");
    r = (corto_record){"b", NULL, ".", "/test/Point", 0, CORTO_RECORD_LEAF};
    test_HistoryMount_data__assign(
        test_HistoryMount_dataList__append_alloc(this->history),
        &r,
        samples
    );
    ut_ll_clear(samples);
    corto_stringList__append(samples, "{60,66}");
    corto_stringList__append(samples, "{70,77}");
    corto_stringList__append(samples, "{80,88}");
    corto_stringList__append(samples, "{90,99}");
    r = (corto_record){"c", NULL, ".", "/test/Point", 0, CORTO_RECORD_LEAF};
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
    ut_ll history;
    ut_iter iter;
} iterData;
static
bool hasNext(
    ut_iter *it)
{
    iterData *ctx = it->ctx;
    return ut_iter_hasNext(&ctx->iter);
}

static
void* next(
    ut_iter *it)
{
    int start = 0, stop = 0, i;
    iterData *ctx = it->ctx;
    test_HistoryMount_data *data = ut_iter_next(&ctx->iter);
    corto_record *result = &data->result;
    /* Clear previous history */
    corto_sample *s;
    while ((s = ut_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    int sampleCount = ut_ll_count(data->history);

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
        s->value = (corto_word)ut_ll_get(data->history, i);
        ut_ll_append(ctx->history, s);
    }

    result->history = ut_ll_iterAlloc(ctx->history);
    return result;
}

static
void release(
    ut_iter *it)
{
    iterData *ctx = it->ctx;
    corto_sample *s;
    while ((s = ut_ll_takeFirst(ctx->history))) {
        corto_dealloc(s);
    }

    ut_ll_free(ctx->history);
    corto_dealloc(ctx);
}

corto_recordIter test_HistoryMount_on_history_query(
    test_HistoryMount this,
    corto_query *query)
{
    corto_recordIter it;

    iterData *data = corto_alloc(sizeof(iterData));
    data->this = this;
    data->from = query->frame_begin;
    data->to = query->frame_end;
    data->soffset = query->soffset;
    data->slimit = query->slimit;
    data->iter = ut_ll_iterAlloc(this->history);
    data->history = ut_ll_new();

    it.next = next;
    it.hasNext = hasNext;
    it.release = release;
    it.ctx = data;

    return it;
}
