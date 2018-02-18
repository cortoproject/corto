/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
void corto_invoke_event_handle_v(
    corto_invoke_event* this)
{
    corto_mount_on_invoke(this->mount, this->instance, this->function, this->args);
}
