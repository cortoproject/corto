
#include "cx.h"
#include "cx_generator.h"
#include "cx_files.h"
#include "cx_file.h"
#include "c_common.h"

/* Generate file containing component loader */
static cx_int16 c_projectGenerateMainFile(cx_generator g) {
    cx_id filename;
    g_file file;
    cx_string snippet;

    sprintf(filename, "%s__load.c", g_getName(g));

    file = g_fileOpen(g, filename);
    if(!file) {
        goto error;
    }
    g_fileWrite(file, "/** \n");
    g_fileWrite(file, " * This file is generated. Only insert code in appropriate places\n");
    g_fileWrite(file, " */\n\n");

    g_fileWrite(file, "#include \"%s__meta.h\"\n\n", g_getName(g));

    if ((snippet = g_fileLookupHeader(file, ""))) {
        g_fileWrite(file, "/* $header()");
        g_fileWrite(file, "%s", snippet);
        g_fileWrite(file, "$end */\n\n");
    } else {
        g_fileWrite(file, "/* $header() */\n");
        g_fileWrite(file, "/* Insert user-includes here */\n");
        g_fileWrite(file, "/* $end */\n\n");    
    }

    g_fileWrite(file, "/* This function is the entrypoint for the library and");
    g_fileWrite(file, " * loads definitions of the '%s' scope */\n", g_getName(g));
    g_fileWrite(file, "int cortexmain(int argc, char* argv[]) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "CX_UNUSED(argc);\n");
    g_fileWrite(file, "CX_UNUSED(argv);\n");

    g_fileWrite(file, "\n");
    g_fileWrite(file, "int result = %s_load();\n", g_getName(g));

    if ((snippet = g_fileLookupSnippet(file, "cortexmain"))) {
        g_fileWrite(file, "\n");
        g_fileWrite(file, "/* $begin(cortexmain)");
        g_fileWrite(file, "%s", snippet);
        g_fileWrite(file, "$end */\n\n");
    } else {
        g_fileWrite(file, "\n");
        g_fileWrite(file, "/* $begin(cortexmain) */\n");
        g_fileWrite(file, "/* Insert user-code here */\n");
        g_fileWrite(file, "/* $end */\n\n");
    }

    g_fileWrite(file, "return result;\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n\n");

    return 0;
error:
    return -1;
}

/* Generate makefile for project */
static cx_int16 c_projectGenerateMakefile(cx_generator g) {
    g_file file;

    /* Only generate makefile when no makefile is present */
    if(!cx_fileTest("rakefile")) {
        file = g_fileOpen(g, "rakefile");
        if(!file) {
            goto error;
        }

        g_fileWrite(file, "\n");
        g_fileWrite(file, "TARGET = :%s\n\n", g_getName(g));
        g_fileWrite(file, "require \"#{ENV['CORTEX_HOME']}/build/package\"\n\n");
    }

    return 0;
error:
    return -1;
}

/* Generate dependency makefile for project */
static cx_int16 c_projectGenerateDepMakefile(cx_generator g) {
    g_file file;
    cx_iter iter;

    file = g_fileOpen(g, "dep.rb");
    if(!file) {
        goto error;
    }

    g_fileWrite(file, "\n");
    g_fileWrite(file, "# include paths for dependent packages\n");

    /* Add include path for dependent packages */
    g_resolveImports(g);
    if (g->imports) {
        iter = cx_llIter(g->imports);
        while (cx_iterHasNext(&iter)) {
            cx_object import;
            cx_id toRoot, path;
            cx_object o = g_getCurrent(g);
            *toRoot = '\0';
            while (o) {
                o = cx_parentof(o);
                strcat(toRoot, "../");
            }
            import = cx_iterNext(&iter);
            c_topath(import, path);
            g_fileWrite(file, "INCLUDE << \"%spackages/%s/include\"\n", toRoot, path, cx_nameof(import));
            g_fileWrite(file, "LIBPATH << \"%spackages/%s/bin\"\n", toRoot, path, cx_nameof(import));
            g_fileWrite(file, "CORTEX_LIB << \"%s\"\n", cx_nameof(import));
        }
    }

    return 0;
error:
    return -1;
}

/* Generator main */
cx_int16 cortex_genMain(cx_generator g) {

    /* Create source and include directories */
    cx_mkdir("src");
    cx_mkdir("include");

    if(c_projectGenerateMainFile(g)) {
        goto error;
    }
    if(c_projectGenerateMakefile(g)) {
        goto error;
    }
    if(c_projectGenerateDepMakefile(g)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
