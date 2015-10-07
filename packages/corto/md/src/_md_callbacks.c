#include "md.h"

#include "_md_callbacks.h"

#include "_md_appendstr.h"
#include "_md_resolvers.h"

#define MAX_OBJECT_HEADER (3)

/*
 * The newlines parameter is important because hoedown strips the block element
 * of any newlines that appeared before or after. If we appended all text,
 * the format would be broken. Things like paragraphs would often use 2 newlines
 * whereas list elements would use 1.
 */
static int md_appendStrToHeading(cx_string text, size_t newlines, md_parseData* data) {
    size_t i;
    if (!md_appendstr(data, "%s", text)) {
        cx_seterr("could not append string to parse data");
        goto error;
    }
    for (i = 0; i < newlines; i++) {
        if (!md_appendstr(data, "\n")) {
            cx_seterr("could not append string to parse data");
            goto error;
        }
    }
    cx_print("<<<%s>>>", data->buffer);
    return 0;
error:
    return 1;
}

static int md_flushStrToHeading(cx_object lastHeader, md_parseData* data) {
    cx_int8 i = 1;
    // cx_object lastHeader;
    // do {
    //     lastHeader = data->headers[i++];
    // } while (i <= 6 && data->headers[i]);
    // if (lastHeader == NULL) {
    //     cx_seterr("could not append to any heading");
    //     goto error;
    // }
    // cx_assert(md_Doc(lastHeader)->text == NULL, "Doc text is not NULL");
    if (data->buffer) {
        puts("buffer not null!");
        md_Doc(lastHeader)->text = strdup(data->buffer);
    } else {
        goto finished;
    }
    //
    cx_print("==================");
    cx_print(cx_nameof(lastHeader));
    cx_print(md_Doc(lastHeader)->text);
    cx_print("==================");
    //
    cx_dealloc(data->buffer);
    data->buffer = NULL;
    data->ptr = NULL;
    data->length = 0;
    data->maxlength = 0;
finished:
    return 0;
error:
    return 1;
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

    cx_object o;
    strncpy(name, (char*)content->data, content->size)[content->size] = '\0';


    md_Doc doc = NULL, previous = NULL;
    if (level <= MAX_OBJECT_HEADER) {
        /* `o` can well be null when not documenting an object store */
        o = md_resolve(level, name, &previous, _data);
        /* Flush any text from previous heading */
        if (level > 1 || previous != _data->destination) {
            md_flushStrToHeading(previous, _data);
        }
        if (!previous && (level > 1)) {
            cx_seterr("H1 header missing (a level %d header as document root is illegal)", level);
            goto error;
        }
        doc = md_DocCreateChild(previous, name, o, level);
        _data->headers[level] = doc;
    } else {
        /* TODO just append like text */
    }
error:
    return;
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
    md_parseData* _data = data->opaque;
    cx_string s = cx_alloc(content->size + 1);
    strncpy(s, (cx_string)content->data, content->size)[content->size] = '\0';
    md_appendStrToHeading(s, 2, _data);
    cx_dealloc(s);
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
    md_parseData* _data = data->opaque;
    cx_int8 i = 1;
    cx_object lastHeader;
    puts("the end!");
    do {
        lastHeader = _data->headers[i];
    } while (i <= 6 && _data->headers[++i]);
    if (lastHeader && _data->buffer) {
        puts("last headers!!!");
        md_flushStrToHeading(lastHeader, _data);
    }
}
