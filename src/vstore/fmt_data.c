/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

void corto_fmt_data_deinit(
    corto_fmt_data* this)
{
    bool should_free = true;
    if (this->shared_count) {
        int32_t *counter = (int32_t*)this->shared_count;
        int32_t result;
        result = corto_adec(counter);

        corto_assert(result >= 0, "counter should not go below zero");
        if (result) {
            should_free = false;
        } else {
            free(counter);
            /* When counter is 0, counter should no longer be accessed */
        }
    }
    if (this->ptr && should_free) {
        corto_fmt fmt = (corto_fmt)this->handle;
        corto_fmt_release(fmt, (void*)this->ptr);
    }
}
