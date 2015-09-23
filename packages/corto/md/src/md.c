/* md.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_md_LIB
#include "md.h"

/* $header() */

#include "document.h"

#include "_md_callbacks.h"

struct md_parseData {
    cx_object destination;
    cx_string text;
    cx_object lastScope;
};

typedef struct md_parseData md_parseData;

int md_renderPackage(cx_string name, md_parseData* data) {
    data->lastScope = md_PackageDocCreateChild(data->lastScope, name);
    return 0;
}

int md_renderType(cx_string name, md_parseData* data) {
    data->lastScope = md_TypeDocCreateChild(data->lastScope, name);
    return 0;
}

int md_renderProcedure(cx_string name, md_parseData* data) {
    data->lastScope = md_ProcedureDocCreateChild(data->lastScope, name);
    return 0;
}

int md_renderArgument(cx_string name, md_parseData* data) {
    cx_assertType(data->lastScope, md_ProcedureDoc_o);
    data->lastScope = md_ParameterDocCreateChild(data->lastScope, name);
    return 0;
}

/* $end */

/* ::corto::md::parse(object destination,string text) */
cx_void _md_parse(cx_object destination, cx_string text) {
/* $begin(::corto::md::parse) */
    cx_object scope = destination ? destination : root_o;
    md_parseData parseData = {scope, text, scope};
    hoedown_renderer renderer = {
        /* state object */
        &parseData,

        /* block level callbacks - NULL skips the block */
        md_callbackBlockcode,
        md_callbackBlockquote,
        md_callbackHeader,
        md_callbackHrule,
        md_callbackList,
        md_callbackListitem,
        md_callbackParagraph,
        md_callbackTable,
        md_callbackTable_header,
        md_callbackTable_body,
        md_callbackTable_row,
        md_callbackTable_cell,
        md_callbackFootnotes,
        md_callbackFootnote_def,
        md_callbackBlockhtml,

        /* span level callbacks - NULL or return 0 prints the span verbatim */
        md_callbackAutolink,
        md_callbackCodespan,
        md_callbackDouble_emphasis,
        md_callbackEmphasis,
        md_callbackUnderline,
        md_callbackHighlight,
        md_callbackQuote,
        md_callbackImage,
        md_callbackLinebreak,
        md_callbackLink,
        md_callbackTriple_emphasis,
        md_callbackStrikethrough,
        md_callbackSuperscript,
        md_callbackFootnote_ref,
        md_callbackMath,
        md_callbackRaw_html,

        /* low level callbacks - NULL copies input directly into the output */
        md_callbackEntity,
        md_callbackNormal_text,

        /* miscellaneous callbacks */
        md_callbackDoc_header,
        md_callbackDoc_footer,
    };

    hoedown_document *document = hoedown_document_new(&renderer, 0, 16);
    hoedown_buffer *buffer = hoedown_buffer_new(16);
    hoedown_document_render(document, buffer, (const uint8_t *)text, strlen(text));
    hoedown_buffer_free(html);
    hoedown_document_free(document);
    hoedown_html_renderer_free(renderer);
/* $end */
}

int mdMain(int argc, char* argv[]) {
/* $begin(main) */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    return 0;
/* $end */
}
