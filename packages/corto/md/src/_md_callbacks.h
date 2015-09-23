#ifndef _MD_CALLBACKS_H
#define _MD_CALLBACKS_H

#include "document.h"

#ifdef __cplusplus
extern "C" {
#endif

void md_callbackBlockcode (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_renderer_data *data);
void md_callbackBlockquote (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackHeader(hoedown_buffer *ob, const hoedown_buffer *content, int level, const hoedown_renderer_data *data);
void md_callbackHrule (hoedown_buffer *ob, const hoedown_renderer_data *data);
void md_callbackList (hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data);
void md_callbackListitem (hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data);
void md_callbackParagraph(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackTable (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackTable_header (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackTable_body (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackTable_row (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackTable_cell (hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data);
void md_callbackFootnotes (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
void md_callbackFootnote_def (hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data);
void md_callbackBlockhtml (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data);
int md_callbackAutolink (hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data);
int md_callbackCodespan (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data);
int md_callbackDouble_emphasis (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackEmphasis (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackUnderline (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackHighlight (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackQuote (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackImage (hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_renderer_data *data);
int md_callbackLinebreak (hoedown_buffer *ob, const hoedown_renderer_data *data);
int md_callbackLink (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_renderer_data *data);
int md_callbackTriple_emphasis (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackStrikethrough (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackSuperscript (hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data);
int md_callbackFootnote_ref (hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data);
int md_callbackMath (hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data);
int md_callbackRaw_html (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data);
void md_callbackEntity (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data);
void md_callbackNormal_text (hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data);
void md_callbackDoc_header (hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data);
void md_callbackDoc_footer (hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data);


#ifdef __cplusplus
}
#endif

#endif /* _MD_CALLBACKS_H */
