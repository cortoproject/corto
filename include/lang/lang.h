/* lang.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_H
#define CORTO_LANG_H

#include <corto/corto.h>
#include <corto/_project.h>

/* $header() */

/* Type flags. These flags are derived from metadata, and provide a method of
 * quickly checking whether a certain part of the code can be skipped. For
 * example: if a type does not have resources, copying an object can be reduced
 * to a memcopy instead of a deepcopy. */
#define CORTO_TYPE_HAS_RESOURCES (1)
#define CORTO_TYPE_NEEDS_INIT (2)
#define CORTO_TYPE_HAS_TARGET (4)
#define CORTO_TYPE_HAS_INIT (8)
#define CORTO_TYPE_HAS_DEINIT (16)
#define CORTO_TYPE_HAS_CONSTRUCT (32)
#define CORTO_TYPE_HAS_DEFINE (64)
#define CORTO_TYPE_HAS_VALIDATE (128)
#define CORTO_TYPE_HAS_UPDATE (256)
#define CORTO_TYPE_HAS_DESTRUCT (512)
#define CORTO_TYPE_HAS_DELETE (1024)
#define CORTO_TYPE_HAS_DELEGATE (2048)
#define CORTO_TYPE_IS_CONTAINER (4096)
/* $end */

#include <corto/lang/_type.h>
#include <corto/lang/_load.h>
#include <corto/lang/_interface.h>

/* $body() */
/* Enter code that requires types here */
/* $end */

#endif
