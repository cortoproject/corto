#include "corto_util.h"

corto_string corto_pathFromFullname(corto_id buffer) {
    char *ptr = buffer, *bptr, ch;
    bptr = ptr;

    for (; (ch = *ptr); ptr++, bptr++) {
        if (ch == ':') {
            *bptr = '/';
            ptr++;
        } else {
            *bptr = ch;
        }
    }

    *bptr = '\0';

    return buffer;
}

corto_string corto_nameFromFullname(corto_id buffer) {
    char *ptr = buffer, *name = buffer, ch;

    for (; (ch = *ptr); ptr++) {
        if (ch == ':') {
            ptr ++;
            name = ptr + 1;
        }
    }

    memmove(buffer, name, strlen(name) + 1);

    return buffer;
}
