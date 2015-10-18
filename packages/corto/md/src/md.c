/* md.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "md.h"

/* $header() */

#include "document.h"

#include "_md_callbacks.h"

hoedown_renderer* md_createRenderer(struct md_parseData* data) {
    cx_assert(data != NULL, "Parse data cannot be null");
    hoedown_renderer* renderer = cx_calloc(sizeof(hoedown_renderer));
    renderer->opaque = data;

    /* block level callbacks - NULL skips the block */
    renderer->blockcode = md_callbackBlockcode;
    renderer->blockquote = md_callbackBlockquote;
    renderer->header = md_callbackHeader;
    renderer->hrule = md_callbackHrule;
    renderer->list = md_callbackList;
    renderer->listitem = md_callbackListitem;
    renderer->paragraph = md_callbackParagraph;
    renderer->table = md_callbackTable;
    renderer->table_header = md_callbackTable_header;
    renderer->table_body = md_callbackTable_body;
    renderer->table_row = md_callbackTable_row;
    renderer->table_cell = md_callbackTable_cell;
    renderer->footnotes = md_callbackFootnotes;
    renderer->footnote_def = md_callbackFootnote_def;
    renderer->blockhtml = md_callbackBlockhtml;

    // /* span level callbacks - NULL or return 0 prints the span verbatim */
    // // renderer->autolink = md_callbackAutolink;
    // // renderer->codespan = md_callbackCodespan;
    // // renderer->double_emphasis = md_callbackDouble_emphasis;
    // // renderer->emphasis = md_callbackEmphasis;
    // // renderer->underline = md_callbackUnderline;
    // // renderer->highlight = md_callbackHighlight;
    // // renderer->quote = md_callbackQuote;
    // // renderer->image = md_callbackImage;
    // // renderer->linebreak = md_callbackLinebreak;
    // // renderer->link = md_callbackLink;
    // // renderer->triple_emphasis = md_callbackTriple_emphasis;
    // // renderer->strikethrough = md_callbackStrikethrough;
    // // renderer->superscript = md_callbackSuperscript;
    // // renderer->footnote_ref = md_callbackFootnote_ref;
    // // renderer->math = md_callbackMath;
    // // renderer->raw_html = md_callbackRaw_html;

    /* low level callbacks - NULL copies input directly into the output */
    // renderer->entity = md_callbackEntity;
    // renderer->normal_text = md_callbackNormal_text;

    /* miscellaneous callbacks */
    // renderer->doc_header = md_callbackDoc_header;
    // renderer->doc_footer = md_callbackDoc_footer;

    return renderer;
}

void md_freeRenderer(hoedown_renderer* renderer) {
    cx_dealloc(renderer);
}

int md_parseDoc(cx_string file, int argc, char* argv[], void *data) {
    cx_char* source;
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    CX_UNUSED(data);

    source = cx_fileLoad(file);
    if (source) {
        cx_object doc = cx_voidCreateChild(NULL, "doc");
        md_parse(doc, source);
        cx_dealloc(source);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}
/* $end */

/* ::corto::md::parse(object destination,string text) */
cx_void _md_parse(cx_object destination, cx_string text) {
/* $begin(::corto::md::parse) */
    if (destination == root_o || destination == NULL) {
        cx_seterr("must specify a destination different from root");
        goto error;
    }
    md_parseData parseData = {
        destination,
        {destination, NULL, NULL, NULL, NULL, NULL, NULL},
        NULL,
        NULL,
        0,
        0
    };
    hoedown_renderer *renderer = md_createRenderer(&parseData);
    hoedown_document *parser = hoedown_document_new(renderer, 0, 16);
    hoedown_buffer *buffer = hoedown_buffer_new(16);
    hoedown_document_render(parser, buffer, (const uint8_t *)text, strlen(text));

    hoedown_buffer_free(buffer);
    hoedown_document_free(parser);
    md_freeRenderer(renderer);
error:;
/* $end */
}

int mdMain(int argc, char* argv[]) {
/* $begin(main) */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    cx_loaderRegister("md", md_parseDoc, NULL);
    return 0;
/* $end */
}
