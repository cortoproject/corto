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
#ifdef __cplusplus
#include <cstddef>

using std::size_t;

extern "C" {
#else
#include <stddef.h>
#endif

#include "db__type.h"

#ifndef HEIGHT_LIMIT
#define HEIGHT_LIMIT 64 /* Tallest allowable tree */
#endif

/* Opaque types */
typedef struct jsw_rbtree jsw_rbtree_t;
typedef struct jsw_rbtrav jsw_rbtrav_t;
typedef struct jsw_rbnode jsw_rbnode_t;

/* Make this structure opaque as this will
 * eliminate the need for an allocation when
 * traversing the tree */
struct jsw_rbtrav {
  jsw_rbtree_t *tree;               /* Paired tree */
  jsw_rbnode_t *it;                 /* Current node */
  jsw_rbnode_t *path[HEIGHT_LIMIT]; /* Traversal path */
  size_t        top;                /* Top of stack */
};

/* User-defined item handling */
typedef void *(*dup_f) ( void *p );
typedef void  (*rel_f) ( void *p );

/* Red Black tree functions */
jsw_rbtree_t *jsw_rbnew ( db_type type, db_equalsAction cmp);
void          jsw_rbdelete ( jsw_rbtree_t *tree );
db_type       jsw_rbtype( jsw_rbtree_t *tree);
void         *jsw_rbfind ( jsw_rbtree_t *tree, void *key );
void         *jsw_rbfindPtr ( jsw_rbtree_t *tree, void *key );
int           jsw_rbhaskey ( jsw_rbtree_t *tree, const void *key, void** data );
int           jsw_rbinsert ( jsw_rbtree_t *tree, void* key, void *data );
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

#ifdef __cplusplus
}
#endif

#endif
