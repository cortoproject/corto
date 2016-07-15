
#include "attrtest/attrtest.h"

int attrtestMain(int argc, char *argv[]) {
    return corto_getAttr() != CORTO_ATTR_DEFAULT;
}
