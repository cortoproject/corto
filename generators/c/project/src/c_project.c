
#include "corto.h"
#include "c_common.h"

/* Generate file containing component loader */
static corto_int16 c_projectGenerateMainFile(corto_generator g) {
    corto_id filename;
    g_file file;
    corto_id topLevelName;
    corto_bool isComponent = !strcmp(gen_getAttribute(g, "component"), "true");

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
        c_writeExport(g, file);
        g_fileWrite(file, "int cortomain(int argc, char* argv[]) {\n");
        g_fileIndent(file);
        g_fileWrite(file, "int %s_load(void);\n", g_getName(g));
        g_fileWrite(file, "if (%s_load()) return -1;\n", g_getName(g));
        g_fileWrite(file, "int %sMain(int argc, char* argv[]);\n", g_getName(g));
        g_fileWrite(file, "if (%sMain(argc, argv)) return -1;\n", g_getName(g));
        g_fileWrite(file, "return 0;\n");
        g_fileDedent(file);
        g_fileWrite(file, "}\n\n");
    } else {
        g_fileWrite(file, "#include \"corto.h\"\n\n");
        if (isComponent) {
            g_fileWrite(file, "int cortomain(int argc, char* argv[]) {\n");
        } else {
            g_fileWrite(file, "int main(int argc, char* argv[]) {\n");
            g_fileWrite(file, "corto_start();\n");
        }
        g_fileIndent(file);
        g_fileWrite(file, "int %sMain(int argc, char* argv[]);\n", g_getName(g));
        g_fileWrite(file, "if (%sMain(argc, argv)) return -1;\n", g_getName(g));
        if (!isComponent) {
            g_fileWrite(file, "corto_stop();\n");
        }
        g_fileWrite(file, "return 0;\n");
        g_fileDedent(file);
        g_fileWrite(file, "}\n\n");
    }

    return 0;
error:
    return -1;
}

/* Generate main header containing includes to dependencies */
static corto_int16 c_projectGenerateMainHeaderFile(corto_generator g) {
    corto_id filename;
    g_file file;
    corto_ll packages, components;

    sprintf(filename, "include/%s.h", g_getName(g));

    file = g_fileOpen(g, filename);
    if(!file) {
        goto error;
    }

    g_fileWrite(file, "/* %s\n", filename);
    g_fileWrite(file, " *\n");
    g_fileWrite(file, " * This file is generated. Do not modify.\n");
    g_fileWrite(file, " */\n\n");

    g_fileWrite(file, "#ifndef %s_H\n", g_getName(g));
    g_fileWrite(file, "#define %s_H\n\n", g_getName(g));

    g_fileWrite(file, "#include \"corto.h\"\n");

    if ((packages = corto_loadGetPackages())) {
        corto_id path;
        corto_iter iter = corto_llIter(packages);
        while (corto_iterHasNext(&iter)) {
            corto_string str = corto_iterNext(&iter);
            corto_object package = corto_resolve(NULL, str);
            if (!package) {
                corto_error("corto: package.txt contains unresolved package '%s'", str);
                goto error;
            }
            g_fileWrite(file, "#include \"%s/%s.h\"\n", c_topath(package, path, '/'), corto_nameof(package));
            corto_release(package);
        }
        corto_loadFreePackages(packages);
    }

    if ((components = corto_loadGetComponents())) {
        corto_iter iter = corto_llIter(components);
        while (corto_iterHasNext(&iter)) {
            corto_string str = corto_iterNext(&iter);
            g_fileWrite(file, "#include \"%s.h\"\n", str);
        }
        corto_loadFreeComponents(components);
    }

    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "extern \"C\" {\n");
    g_fileWrite(file, "#endif\n");

    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* $header()");

    /* Lookup the header snippet */
    corto_string snippet = g_fileLookupHeader(file, "");
    if (snippet) {
        g_fileWrite(file, snippet);
    } else {
        g_fileWrite(file, " */\n");
        g_fileWrite(file, "/* You can put your own definitions here! */\n");
        g_fileWrite(file, "/* ");
    }
    g_fileWrite(file, "$end */\n");

    g_fileWrite(file, "\n");

    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");

    g_fileClose(file);

    return 0;
error:
    return -1;
}

typedef struct c_projectCleanInclude_t {
    corto_generator g;
    g_file file;
} c_projectCleanInclude_t;

static int c_projectCleanInclude(corto_object o, void *userData) {
    c_projectCleanInclude_t *data = userData;

    if (corto_instanceof(corto_type(corto_interface_o), o) || corto_instanceof(corto_type(corto_package_o), o)) {
        corto_id id;
        g_fileWrite(data->file, "CLOBBER.include(\"include/%s.h\")\n", g_fullOid(data->g, o, id));
    }

    return 1;
}

/* Generate dependency makefile for project */
static corto_int16 c_projectGenerateDepMakefile(corto_generator g) {
    g_file file;
    c_projectCleanInclude_t walkData;

    file = g_hiddenFileOpen(g, "dep.rb");
    if(!file) {
        goto error;
    }

    g_fileWrite(file, "require 'rake/clean'\n");

    g_fileWrite(file, "\n");
    g_fileWrite(file, "# Clobber generated header files\n");
    walkData.file = file;
    walkData.g = g;
    g_fileWrite(file, "\n");
    g_walkRecursive(g, c_projectCleanInclude, &walkData);
    g_fileWrite(file, "CLOBBER.include(\".corto/dep.rb\")\n");

    return 0;
error:
    return -1;
}

/* Generate dependency makefile for project */
static corto_int16 c_projectGeneratePackageFile(corto_generator g) {
    corto_file file = NULL;

    g_resolveImports(g);
    if (g->imports) {
        file = corto_fileAppend(".corto/packages.txt");
        corto_iter iter = corto_llIter(g->imports);

        while (corto_iterHasNext(&iter)) {
            corto_object import = corto_iterNext(&iter);
            corto_id id;
            corto_fullname(import, id);
            if (!corto_loadRequiresPackage(id)) {
                fprintf(corto_fileGet(file), "%s\n", id);
            }
        }

        corto_fileClose(file);
    }

    return 0;
}

/* Generator main */
corto_int16 corto_genMain(corto_generator g) {

    /* Create source and include directories */
    corto_mkdir("include");
    corto_mkdir("src");
    corto_mkdir(".corto");

    if(c_projectGenerateMainFile(g)) {
        goto error;
    }

    if (g->objects) {
        if(c_projectGenerateDepMakefile(g)) {
            goto error;
        }
        if(c_projectGeneratePackageFile(g)) {
            goto error;
        }
    } else {
        if(c_projectGenerateMainHeaderFile(g)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}
