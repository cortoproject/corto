
#include "db.h"
#include "db_generator.h"
#include "db_files.h"

/* Generate file containing component loader */
static db_int16 c_projectGenerateMainFile(db_generator g) {
	db_id filename;
	g_file file;
	sprintf(filename, "%s__main.c", g_getName(g));

	file = g_fileOpen(g, filename);
	if(!file) {
		goto error;
	}
	g_fileWrite(file, "/** \n");
	g_fileWrite(file, " * This file is fully generated. Do not modify!\n");
	g_fileWrite(file, " */\n\n");

	g_fileWrite(file, "#include \"%s__meta.h\"\n\n", g_getName(g));

    g_fileWrite(file, "/* This function is the entrypoint for the library and");
    g_fileWrite(file, " * loads definitions of the '%s' scope */\n", g_getName(g));
	g_fileWrite(file, "int hyvemain(int argc, char* argv[]) {\n");
	g_fileIndent(file);
	g_fileWrite(file, "DB_UNUSED(argc);\n");
	g_fileWrite(file, "DB_UNUSED(argv);\n");
	g_fileWrite(file, "return %s_load();\n", g_getName(g));
	g_fileDedent(file);
	g_fileWrite(file, "}\n\n");

	return 0;
error:
	return -1;
}

/* Generate makefile for project */
static db_int16 c_projectGenerateMakefile(db_generator g) {
	g_file file;
	file = g_fileOpen(g, "makefile");
	if(!file) {
		goto error;
	}

    g_fileWrite(file, "\n");
    g_fileWrite(file, "TARGET = %s\n\n", g_getName(g));
    g_fileWrite(file, "LIBS = lang\n\n");
    g_fileWrite(file, "include $(HYVE_HOME)/build/component.makefile\n\n");

	return 0;
error:
	return -1;
}

/* Generator main */
db_int16 hyve_genMain(db_generator g) {

    /* Create source and include directories */
    db_mkdir("src");
    db_mkdir("include");

	if(c_projectGenerateMainFile(g)) {
		goto error;
	}
	if(c_projectGenerateMakefile(g)) {
		goto error;
	}

	return 0;
error:
    return -1;
}