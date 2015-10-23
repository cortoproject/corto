/*
 * corto_xml_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "corto_def.h"
#include "xml_deser.h"
#include "corto_loader.h"
#include "corto_util.h"

int xmlMain(int argc, char* argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    corto_loaderRegister("xml", corto_deserXml, NULL);
    return 0;
}
