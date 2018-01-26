/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
void corto_invokeEvent_handle_v(
    corto_invokeEvent* this)
{

    corto_mount_on_invoke(this->mount, this->instance, this->function, this->args);

}

