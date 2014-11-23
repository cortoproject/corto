/*
 * sigar_main.c
 *
 *  Created on: Jan 7, 2013
 *      Author: sander
 */

#include "Sigar__meta.h"

int hyvemain(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);

    Sigar_load();

    return 0;
}
