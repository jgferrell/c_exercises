// dlist.h

#ifndef DLIST_H_
#define DLIST_H_

#include <stddef.h>

/* dlnode_valptr_t: a pointer to a node-value */
typedef void * dlnode_valptr_t;

/* dlnode_t: the node of a doubly-linked list; has a value-pointer and
   a pointer to the next node in the list */
struct dlnode_t {
  dlnode_valptr_t value_ptr;
  struct dlnode_t *prev;
  struct dlnode_t *next;
};
typedef struct dlnode_t dlnode_t;

/* dlist_t: a doubly-linked list; `length` keeps track of how many
   nodes are in the list, `head` points to the first node in the list,
   and `tail` points to the last node. */
typedef struct {
  int length;
  dlnode_t *head;
  dlnode_t *tail;
} dlist_t;

/* Returns a properly initialized double-linked list. Allocates
   memory. */
dlist_t * dlist_new_list();

/* Returns a pointer to the node requested by index (index is the
   number of nodes between target node and head node). */
dlnode_t * dlist_get_node(dlist_t *list, int node_index);

/* Inserts a new node at specified index with specified value. Returns
   a pointer to the new node. */
dlnode_t * dlist_insert_node_at_index(dlist_t *list, int node_index, dlnode_valptr_t value_ptr);

/* Inserts a new node into the list after `prev_node`. */
dlnode_t * dlist_add_node_after(dlist_t *list, dlnode_t *prev_node, dlnode_valptr_t value_ptr);

/* Inserts a new node into the list before `next_node`. */
dlnode_t * dlist_add_node_before(dlist_t *list, dlnode_t *next_node, dlnode_valptr_t value_ptr);

/* Delete the given node and update the list. */
void dlist_delete_node(dlist_t *list, dlnode_t *node);

/* Delete the node at the given index and update the list. */
void dlist_delete_node_at_index(dlist_t *list, int node_index);

/* Deletes all nodes from list, freeing allocated memory. */
void dlist_empty(dlist_t *list);

/* Deletes all nodes from list and deletes list, freeing allocated
   memory. */
void dlist_delete_list(dlist_t *list);

#endif /* DLIST_H_ */
