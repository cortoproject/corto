/*
 * cx_xml_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "cx_def.h"
#include "cx_xml_deser.h"
#include "cx_loader.h"
#include "cx_util.h"

int cortexmain(int argc, char* argv[]) {
	DB_UNUSED(argc);
	DB_UNUSED(argv);
	cx_loaderRegister("xml", cx_deserXml, NULL);
	return 0;
}

