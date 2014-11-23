/* src/hyve/lang/_type.cpp
 *
 *  Generated on Oct 28 2014
 *    Type-definitions for C++ language.
 *    This file contains generated code. Do not modify!
 */

#include "hyve/lang/_type.hpp"

namespace hyve {
    namespace lang {
        int32_t VALID = 0x1;
        int32_t DECLARED = 0x2;
        int32_t DEFINED = 0x4;
        int32_t ATTR_SCOPED = 0x1;
        int32_t ATTR_WRITABLE = 0x2;
        int32_t ATTR_OBSERVABLE = 0x4;
        int32_t GLOBAL = 0x0;
        int32_t LOCAL = 0x1;
        int32_t PRIVATE = 0x2;
        int32_t READONLY = 0x4;
        int32_t CONST = 0x8;
        int32_t ON_DECLARE = 0x1;
        int32_t ON_DEFINE = 0x2;
        int32_t ON_DESTRUCT = 0x4;
        int32_t ON_INVALIDATE = 0x8;
        int32_t ON_UPDATE = 0x10;
        int32_t ON_SELF = 0x20;
        int32_t ON_SCOPE = 0x40;
        int32_t ON_VALUE = 0x80;
        int32_t ON_METAVALUE = 0x100;
    }
}
