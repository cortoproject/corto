#include <errno.h>
#include <stdio.h>

#include "corto.h"

#include "cx_files.h"
#include "cx_generator.h"
#include "corto/md/md.h"

typedef struct html_data {
    g_file f;
    cx_generator g;
} html_data;

static cx_int16 html_copy(const char* path, const char *name) {
    /* TODO  */
    // char sourcePath[PATH_MAX];
    // char destinationPath[PATH_MAX];
    char* cortoHome = getenv("CORTO_HOME");
    char* sourcePath;
    char* destinationPath;
    cx_asprintf(&sourcePath, "%s/generators/html/%s", cortoHome, name);
    cx_asprintf(&destinationPath, "%s/%s", path, name);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    cx_dealloc(sourcePath);
    cx_dealloc(destinationPath);
    return 0;
error:
    return -1;
}

static int html_dumpMdObject(md_Doc doc, html_data* data, cx_ll ll) {
    /* TODO get relative name */
    int i = 0;
    while (i++ < doc->level) {
        if (doc->level > 6) {
            cx_seterr("doc has more than 6 levels but HTML headings only allow for 6 levels");
            goto error;
        }
        g_fileWrite(data->f, "#");
    }

    cx_id relativeName;
    cx_fullname(doc, relativeName); /* TODO get relative name */
    g_fileWrite(data->f, " %s\n", relativeName); /* Notice the space */
    g_fileWrite(data->f, "<div class=\"doc-description\">\n");
    g_fileWrite(data->f, "%s", doc->description);
    g_fileWrite(data->f, "</div>\n");
    g_fileWrite(data->f, "<div class=\"doc-text\">\n");
    g_fileWrite(data->f, "%s", doc->text);
    g_fileWrite(data->f, "</div>\n");

    {
        cx_objectseq scope = cx_scopeClaim(doc);
        cx_objectseqForeach(scope, child) {
            cx_llAppend(ll, child);
        }
        cx_scopeRelease(scope);
    }
    return 1;
error:
    return 0;
}

static int html_dumpMd(md_Doc doc, html_data* data) {
    cx_ll ll = cx_llNew();
    cx_llAppend(ll, doc);
    while (cx_llSize(ll)) {
        if (html_dumpMdObject(md_Doc(cx_llTakeFirst(ll)), data, ll) == 0) {
            goto error;
        }
    }
    cx_llFree(ll);
    return 0;
error:
    return 1;
}

static int html_htmlScaffold(md_Doc doc, void* data) {
    html_data* _data = data;
    g_fileWrite(_data->f, "<!DOCTYPE html>\n");
    g_fileWrite(_data->f, "<html>\n");
    g_fileWrite(_data->f, "<head>\n");
    g_fileWrite(_data->f, "<meta charset=\"UTF-8\">\n");
    g_fileWrite(_data->f, "</head>\n");
    g_fileWrite(_data->f, "<body>\n");
    html_dumpMd(doc, data);
    g_fileWrite(_data->f, "</body>\n");
    g_fileWrite(_data->f, "</html>\n");
    return 0;
}

cx_int16 corto_genMain(cx_generator g) {
    /*
     * Check if *.md file exists.
     * If not, generate the md scaffold.
     * Once it exists, parse it and generate the doc tree.
     * Copy css and js files.
     */

    char* filename = "docs.html";
    cx_object o = cx_createChild(root_o, "docs", cx_void_o);
    if (!o) {
        cx_seterr("could not create docs object for parsing markdown");
        goto error;
    }

    cx_string docName = gen_getAttribute(g, "doc");
    if (docName == NULL) {
        cx_seterr("please define target doc with --attr doc=::path::to::doc");
        goto error;
    }
    cx_object doc = cx_resolve(NULL, docName);
    if (doc == NULL) {
        cx_seterr("could not find %s", docName);
        goto error;
    }

    g_file file = g_fileOpen(g, filename);
    html_data data = {file, g};
    html_htmlScaffold(doc, &data);
    g_fileClose(file);

    return 0;
error:
    return 1;
}
