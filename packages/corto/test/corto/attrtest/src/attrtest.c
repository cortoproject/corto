
#include "attrtest/attrtest.h"

/* Add implementation here */

/* cortomain is called when the package is loaded by Corto. It is a good
 * place for initialization code that needs to be executed once.
 * The function can be safely removed if not needed. */
int attrtestMain(int argc, char *argv[]) {
    return corto_getAttr() != CORTO_ATTR_DEFAULT;
}
