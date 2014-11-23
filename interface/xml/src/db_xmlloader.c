/*
 * db_xml_loader.c
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#include "db_def.h"
#include "db_xml_deser.h"
#include "db_loader.h"
#include "db_util.h"

int hyvemain(int argc, char* argv[]) {
	DB_UNUSED(argc);
	DB_UNUSED(argv);
	db_loaderRegister("xml", db_deserXml, NULL);
	return 0;
}

