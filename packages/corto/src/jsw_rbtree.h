#ifndef JSW_RBTREE_H
#define JSW_RBTREE_H

/*
  Red Black balanced tree library

    > Created (Julienne Walker): August 23, 2003
    > Modified (Julienne Walker): March 14, 2008

  This code is in the public domain. Anyone may
  use it or change it in any way that they see
  fit. The author assumes no responsibility for
  damages incurred through use of the original
  code or any variations thereof.

  It is requested, but not required, that due
  credit is given to the original author and
  anyone who has modified the code through
  a header comment, such as this one.
*/

#include "corto/object.h"
#include "corto/rbtree.h"

#ifdef __cplusplus
#include <cstddef>

using std::size_t;

extern "C" {
#else
#include <stddef.h>
#endif

/* User-defined item handling */
typedef void *(*dup_f) ( void *p );
typedef void  (*rel_f) ( void *p );

/* Red Black tree functions */
jsw_rbtree_t *jsw_rbnew ( corto_type type, corto_equals_cb cmp);
void          jsw_rbdelete ( jsw_rbtree_t *tree );
corto_type    jsw_rbtype( jsw_rbtree_t *tree);
void         *jsw_rbfind ( jsw_rbtree_t *tree, void *key );
void         *jsw_rbfindPtr ( jsw_rbtree_t *tree, void *key );
int           jsw_rbhaskey ( jsw_rbtree_t *tree, const void *key, void** data );
int           jsw_rbhaskey_w_cmp ( jsw_rbtree_t *tree, const void *key, void** data, corto_equals_cb f_cmp );
int           jsw_rbinsert ( jsw_rbtree_t *tree, void* key, void *data, void **old_out, corto_bool overwrite );
int           jsw_rberase ( jsw_rbtree_t *tree, void *key );
size_t        jsw_rbsize ( jsw_rbtree_t *tree );

/* Get minimum and maximum */
void         *jsw_rbgetmin ( jsw_rbtree_t *tree, void** key_out);
void         *jsw_rbgetmax ( jsw_rbtree_t *tree, void** key_out);

/* Get next and prev */
void         *jsw_rbgetnext ( jsw_rbtree_t *tree, void* key, void** key_out);
void         *jsw_rbgetprev ( jsw_rbtree_t *tree, void* key, void** key_out);

/* Traversal functions */
jsw_rbtrav_t *jsw_rbtnew ( void );
void          jsw_rbtdelete ( jsw_rbtrav_t *trav );
void         *jsw_rbtfirst ( jsw_rbtrav_t *trav, jsw_rbtree_t *tree );
void         *jsw_rbtfirstptr ( jsw_rbtrav_t *trav, jsw_rbtree_t *tree );
void         *jsw_rbtlast ( jsw_rbtrav_t *trav, jsw_rbtree_t *tree );
void         *jsw_rbtnext ( jsw_rbtrav_t *trav );
void         *jsw_rbtnextptr ( jsw_rbtrav_t *trav );
void         *jsw_rbtprev ( jsw_rbtrav_t *trav );
corto_bool    jsw_rbtchanged( jsw_rbtrav_t *trav );

void *jsw_rbnodedata(jsw_rbnode_t *node);

#ifdef __cplusplus
}
#endif

#endif
