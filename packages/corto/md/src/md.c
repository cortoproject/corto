/* $CORTO_GENERATED
 *
 * md.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "md.h"

/* $header() */
#include "html.h"
#include "document.h"
#include "_md_callbacks.h"

hoedown_renderer* md_createRenderer(struct md_parseData* data) {
    corto_assert(data != NULL, "Parse data cannot be null");
    hoedown_renderer* renderer = corto_calloc(sizeof(hoedown_renderer));
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
    corto_dealloc(renderer);
}

int md_parseDoc(corto_string file, int argc, char* argv[], void *data) {
    corto_char* source;
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    CORTO_UNUSED(data);

    source = corto_fileLoad(file);
    if (source) {
        corto_object doc = corto_voidCreateChild(NULL, "doc");
        md_parseToCorto(doc, source);
        corto_dealloc(source);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}
/* $end */

corto_string _md_parse(corto_string text) {
/* $begin(::corto::md::parse) */
    corto_string result = NULL;

    hoedown_renderer *renderer = hoedown_html_renderer_new(0, 0);
    hoedown_document *document = hoedown_document_new(renderer, HOEDOWN_EXT_BLOCK, 16);
    hoedown_buffer *html = hoedown_buffer_new(16);
    hoedown_document_render(document, html, (uint8_t*)text, strlen(text));

    result = corto_strdup(hoedown_buffer_cstr(html));

    hoedown_buffer_free(html);
    hoedown_document_free(document);
    hoedown_html_renderer_free(renderer);

    return result;
/* $end */
}

corto_void _md_parseToCorto(corto_object destination, corto_string text) {
/* $begin(::corto::md::parseToCorto) */

    if (destination == root_o || destination == NULL) {
        corto_seterr("must specify a destination different from root");
        return;
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

/* $end */
}

int mdMain(int argc, char* argv[]) {
/* $begin(main) */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    corto_loaderRegister("md", md_parseDoc, NULL);
    return 0;
/* $end */
}
