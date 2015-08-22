
#include "cx.h"
#include "cx_generator.h"
#include "cx_files.h"
#include "cx_file.h"
#include "c_common.h"

/* Generate file containing component loader */
static cx_int16 c_projectGenerateMainFile(cx_generator g) {
    cx_id filename;
    g_file file;
    cx_id topLevelName;

    sprintf(filename, "%s__load.c", g_getName(g));

    file = g_hiddenFileOpen(g, filename);
    if(!file) {
        goto error;
    }

    g_fileWrite(file, "/* %s\n", filename);
    g_fileWrite(file, " *\n");
    g_fileWrite(file, " * This file is generated. Do not modify.\n");
    g_fileWrite(file, " */\n\n");

    if (g_getCurrent(g)) {
        g_fileWrite(file, "#include \"%s.h\"\n\n", g_fullOid(g, g_getCurrent(g), topLevelName));
        g_fileWrite(file, "int cortexmain(int argc, char* argv[]) {\n");
        g_fileIndent(file);
        g_fileWrite(file, "if (%s_load()) return -1;\n", g_getName(g));
        g_fileWrite(file, "int %smain(int argc, char* argv[]);\n", g_getName(g));
        g_fileWrite(file, "if (%smain(argc, argv)) return -1;\n", g_getName(g));
        g_fileWrite(file, "return 0;\n");
        g_fileDedent(file);
        g_fileWrite(file, "}\n\n");
    } else {
        g_fileWrite(file, "#include \"cortex.h\"\n\n");
        g_fileWrite(file, "int main(int argc, char* argv[]) {\n");
        g_fileIndent(file);
        g_fileWrite(file, "cx_start();\n");
        g_fileWrite(file, "int %smain(int argc, char* argv[]);\n", g_getName(g));
        g_fileWrite(file, "if (%smain(argc, argv)) return -1;\n", g_getName(g));
        g_fileWrite(file, "cx_stop();\n");
        g_fileWrite(file, "return 0;\n");
        g_fileDedent(file);
        g_fileWrite(file, "}\n\n");
    }

    return 0;
error:
    return -1;
}

typedef struct c_projectCleanInclude_t {
    cx_generator g;
    g_file file;
} c_projectCleanInclude_t;

static int c_projectCleanInclude(cx_object o, void *userData) {
    c_projectCleanInclude_t *data = userData;

    if (cx_instanceof(cx_type(cx_interface_o), o) || cx_instanceof(cx_type(cx_package_o), o)) {
        cx_id id;
        g_fileWrite(data->file, "CLOBBER.include(\"include/%s.h\")\n", g_fullOid(data->g, o, id));
    }

    return 1;
}

/* Generate dependency makefile for project */
static cx_int16 c_projectGenerateDepMakefile(cx_generator g) {
    g_file file;
    cx_iter iter;
    c_projectCleanInclude_t walkData;

    file = g_hiddenFileOpen(g, "dep.rb");
    if(!file) {
        goto error;
    }

    g_fileWrite(file, "require 'rake/clean'\n");
    g_fileWrite(file, "\n");

    g_resolveImports(g);
    if (g->imports) {
        g_fileWrite(file, "# Include paths and libraries of dependent packages\n");
        iter = cx_llIter(g->imports);
        g_fileWrite(file, "INCLUDE ||= []\n");
        g_fileWrite(file, "LIBPATH ||= []\n");
        g_fileWrite(file, "CORTEX_LIB ||= []\n");
        g_fileWrite(file, "LFLAGS ||= []\n");
        g_fileWrite(file, "USE_PACKAGE ||= []\n");
        while (cx_iterHasNext(&iter)) {
            cx_object import;
            cx_id toRoot, path, id;
            cx_object o = g_getCurrent(g);
            *toRoot = '\0';
            while (o) {
                o = cx_parentof(o);
                strcat(toRoot, "../");
            }
            import = cx_iterNext(&iter);
            c_topath(import, path);
            g_fileWrite(file, "# %s\n", cx_nameof(import));
            g_fileWrite(file, "USE_PACKAGE << '%s'\n", cx_fullname(import, id));
        }
    }

    walkData.file = file;
    walkData.g = g;
    g_fileWrite(file, "\n");
    g_walkRecursive(g, c_projectCleanInclude, &walkData);
    g_fileWrite(file, "CLOBBER.include(\".cortex/dep.rb\")\n");

    return 0;
error:
    return -1;
}

/* Generator main */
cx_int16 cortex_genMain(cx_generator g) {

    /* Create source and include directories */
    cx_mkdir("src");
    cx_mkdir(".cortex");

    if(c_projectGenerateMainFile(g)) {
        goto error;
    }

    if (g_getCurrent(g)) {
        cx_mkdir("include");
        if(c_projectGenerateDepMakefile(g)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}
