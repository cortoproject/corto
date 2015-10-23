#include "md.h"

#include "_md_callbacks.h"

#include "_md_resolvers.h"

#define MAX_OBJECT_HEADER (4)

void md_callbackBlockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(lang);
    CORTO_UNUSED(data);
}

void md_callbackBlockquote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackHeader(hoedown_buffer *ob, const hoedown_buffer *content, int level, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    corto_id name;
    md_parseData* _data = data->opaque;

    corto_object o;
    strncpy(name, (char*)content->data, content->size)[content->size] = '\0';

    md_Doc doc = NULL;
    corto_object previous = NULL;
    if (level <= MAX_OBJECT_HEADER) {
        /* `o` can well be null when not documenting an object store */
        o = md_resolve(level, name, &previous, _data);
        if (!corto_instanceof(md_Doc_o, previous) && (level > 1)) {
            corto_seterr("H1 header missing (a level %d header as document root is illegal)", level);
            goto error;
        }
        
        /* Isolate name from scoped name */
        char *ptr = name, ch, *bptr;
        corto_id id; 
        bptr = id;
        for (; (ch = *ptr); ptr++, bptr++) {
            if (ch == ':') {
                *bptr = '_';
                ptr++;
            } else {
                *bptr = ch;
            }
        }
        *bptr = '\0';

        doc = md_DocCreateChild(previous, id, o, level);
        _data->headers[level] = doc;
    } else {
        /* TODO just append like text */
    }
error:
    return;
}

void md_callbackHrule(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(data);
}

void md_callbackList(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(flags);
    CORTO_UNUSED(data);
}

void md_callbackListitem(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(flags);
    CORTO_UNUSED(data);
}

void md_callbackParagraph(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    md_Doc lastHeader = NULL;
    corto_uint32 i = 0;
    md_parseData* _data = data->opaque;
    corto_string str = NULL, buff = NULL;

    CORTO_UNUSED(ob);

    for (i = 1; i <= MAX_OBJECT_HEADER; i++) {
        if (_data->headers[i]) {
            lastHeader = _data->headers[i];
        }
    }

    buff = corto_calloc(content->size + 1);
    memcpy(buff, content->data, content->size);

    if (lastHeader) {
        if (lastHeader->description) {
            if (lastHeader->text) {
                corto_asprintf(&str, "%s\n%s\n", lastHeader->text, buff);
            } else { 
                corto_asprintf(&str, "%s\n", buff);
            }
            corto_setstr(&lastHeader->text, str);
        } else {
            corto_asprintf(&str, "%s\n", buff);
            corto_setstr(&lastHeader->description, str);
        }
    }

    corto_dealloc(str);
    corto_dealloc(buff);
}

void md_callbackTable(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackTable_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackTable_body(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackTable_row(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackTable_cell(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(flags);
    CORTO_UNUSED(data);
}

void md_callbackFootnotes(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackFootnote_def(hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(num);
    CORTO_UNUSED(data);
}

void md_callbackBlockhtml(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
}

int md_callbackAutolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(link);
    CORTO_UNUSED(type);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackCodespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackDouble_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackEmphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackUnderline(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackHighlight(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackQuote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackImage(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(link);
    CORTO_UNUSED(title);
    CORTO_UNUSED(alt);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackLinebreak(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackLink(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(link);
    CORTO_UNUSED(title);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackTriple_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackStrikethrough(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackSuperscript(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackFootnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(num);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackMath(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(displaymode);
    CORTO_UNUSED(data);
    return 0;
}

int md_callbackRaw_html(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    return 0;
}

void md_callbackEntity(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
}

void md_callbackNormal_text(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
}

void md_callbackDoc_header(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(inline_render);
    CORTO_UNUSED(data);
}

void md_callbackDoc_footer(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(inline_render);
    CORTO_UNUSED(data);
}
