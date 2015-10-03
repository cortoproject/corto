#include "md.h"

#include "_md_callbacks.h"

#include "_md_renderers.h"

static cx_object md_resolvePackage(cx_string name, md_parseData* data) {
    CX_UNUSED(data);
    cx_string fullnameNoRoot = NULL;
    if (name[0] == ':') {
        fullnameNoRoot = name + 2;
    } else {
        fullnameNoRoot = name;
    }
    cx_object o = cx_resolve(root_o, fullnameNoRoot);
    /* TODO double check that the name is effectively in root */
    if (!o) {
        cx_error("Cannot find %s", fullnameNoRoot);
        goto error;
    }
    if (!cx_instanceof(cx_package_o, o)) {
        cx_error("%s is not a package", fullnameNoRoot);
        goto error;
    }
    return o;
error:
    return NULL;
}

static cx_object md_resolveType(cx_string name, md_parseData* data) {
    if (!cx_instanceof(md_PackageDoc_o, data->lastScope)) {
        cx_error("%s not in the scope of a PackageDoc");
        goto error;
    }
    cx_package package = md_Doc(data->lastScope)->o;
    
    cx_object o = cx_resolve(package, name);
    /*
     * TODO This checks if cx_resolve did not resolve from special scopes
     * like ::corto::lang and ::corto
     */
    if (!o || cx_parentof(o) != package) {
        cx_id packageFullname;
        cx_fullname(package, packageFullname);
        cx_error("Cannot find %s::%s", packageFullname, name);
        goto error;
    }
    if (!cx_instanceof(cx_type_o, o)) {
        cx_id fullname;
        cx_fullname(o, fullname);
        cx_error("%s is not a type", fullname);
        goto error;
    }
    return o;
error:
    return NULL;
}

void md_callbackBlockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(lang);
    CX_UNUSED(data);
}

void md_callbackBlockquote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackHeader(hoedown_buffer *ob, const hoedown_buffer *content, int level, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    cx_id name;
    md_parseData* _data = data->opaque;
    int error = 0;
    cx_object o;
    strncpy(name, (char*)content->data, content->size)[content->size] = '\0';
    switch (level) {
        case 1:
            if ((o = md_resolvePackage(name, _data)) == NULL) {
                goto error;
            }
            error = md_renderPackage(o, _data);
            break;
        case 2:
            if ((o = md_resolveType(name, _data)) == NULL) {
                goto error;
            }
            error = md_renderType(o, _data);
            break;
        case 3: error = md_renderProcedure(name, _data); break;
        case 4: error = md_renderArgument(name, _data); break;
    }
    if (error) {
        /* TODO propagate error to other places */
        goto error;
    }
error:;
}

void md_callbackHrule(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(data);
}

void md_callbackList(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(flags);
    CX_UNUSED(data);
}

void md_callbackListitem(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(flags);
    CX_UNUSED(data);
}

void md_callbackParagraph(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackTable(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackTable_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackTable_body(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackTable_row(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackTable_cell(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(flags);
    CX_UNUSED(data);
}

void md_callbackFootnotes(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
}

void md_callbackFootnote_def(hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(num);
    CX_UNUSED(data);
}

void md_callbackBlockhtml(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(data);
}

int md_callbackAutolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(link);
    CX_UNUSED(type);
    CX_UNUSED(data);
    return 0;
}

int md_callbackCodespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(data);
    return 0;
}

int md_callbackDouble_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackEmphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackUnderline(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackHighlight(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackQuote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackImage(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(link);
    CX_UNUSED(title);
    CX_UNUSED(alt);
    CX_UNUSED(data);
    return 0;
}

int md_callbackLinebreak(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(data);
    return 0;
}

int md_callbackLink(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(link);
    CX_UNUSED(title);
    CX_UNUSED(data);
    return 0;
}

int md_callbackTriple_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackStrikethrough(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackSuperscript(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(content);
    CX_UNUSED(data);
    return 0;
}

int md_callbackFootnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(num);
    CX_UNUSED(data);
    return 0;
}

int md_callbackMath(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(displaymode);
    CX_UNUSED(data);
    return 0;
}

int md_callbackRaw_html(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(data);
    return 0;
}

void md_callbackEntity(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(data);
}

void md_callbackNormal_text(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(text);
    CX_UNUSED(data);
}

void md_callbackDoc_header(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(inline_render);
    CX_UNUSED(data);
}

void md_callbackDoc_footer(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CX_UNUSED(ob);
    CX_UNUSED(inline_render);
    CX_UNUSED(data);
}
