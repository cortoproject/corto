/* _binding.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_NATIVE_BINDING_H
#define CORTO_NATIVE_BINDING_H

/* -- Type casting -- */
#define corto_native_type(o) ((corto_native_type)corto_assert_type((corto_type)corto_native_type_o, o))

/* -- Non-expanding typedefs -- */
typedef corto_native_type _type_corto_native_type;

/* -- Argument type casting -- */
#ifndef CORTO_IMPL
#define corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))
#else
/* Can't use argument type casting macro's within project, as they would
 * substitute headers in implementation files. */
#define corto_native_type_init _corto_native_type_init
/* Macro for doing argument type casting within project. */
#define safe_corto_native_type_init(_this) _corto_native_type_init(corto_native_type(_this))
#endif

/* -- Overridable methods -- */

/* -- Short identifier translation -- */

/* -- Short object variable translation -- */

#endif

