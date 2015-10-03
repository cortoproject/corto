#include "md.h"

#include "_md_callbacks.h"

#include "_md_renderers.h"
#include "_md_resolvers.h"

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
        case 3:
            if ((o = md_resolveMethod(name, _data)) == NULL) {
                goto error;
            }
            error = md_renderMethod(o, _data);
            break;
        case 4:
            // error = md_renderArgument(o, _data);
            break;
    }
    if (error) {
        /* TODO propagate error to other callbacks? */
        cx_seterr("could not resolve: %s", name);
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
