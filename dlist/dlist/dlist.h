// dlist.h

#ifndef DLIST_H_
#define DLIST_H_

/*
** DATA STRUCTURES & TYPES
*/

/* dlnode_valptr_t: a pointer to a node-value */
typedef void * dlnode_valptr_t;

/* dlnode_t: the node of a doubly-linked list; has a value-pointer, a
   pointer to the next node in the list, and a pointer to the previous
   node in the list. */
struct dlnode_t {
  dlnode_valptr_t value_ptr;
  struct dlnode_t *prev;
  struct dlnode_t *next;
};
typedef struct dlnode_t dlnode_t;

/* dlist_t: a doubly-linked list; `length` keeps track of how many
   nodes are in the list; `dummy` node is always `prev` to the head of
   the list and `next` to tail of the list. */
typedef struct {
  int length;
  dlnode_t *dummy;
} dlist_t;

/*
** INITIALIZATION OPERATIONS
*/

/* Returns a pointer to a properly initialized double-linked
   list. Allocates memory. */
dlist_t * dlist_new_list();

/*
** NODE OPERATIONS
*/

/* Add a new node to the provided list at the specified index. After the
   new node is added, it precedes the node previously at the specified
   index. Returns pointer to the new node. */
dlnode_t * dlist_add(dlist_t *list, int i, dlnode_valptr_t newval);

/* Returns a pointer to the node at the specified index of the
   provided list. */
dlnode_t * dlist_get_node(dlist_t *list, int node_index);

/* Inserts a new node into the list before `next_node`. */
dlnode_t * dlist_add_before(dlist_t *list, dlnode_t *next_node,
			    dlnode_valptr_t value_ptr);

/* Delete the given node and update the list. */
void dlist_delete_node(dlist_t *list, dlnode_t *node);

/* Delete the node at the given index and update the list. */
void dlist_delete_node_at(dlist_t *list, int i);

/*
** VALUE OPERATIONS
*/

/* Get value-pointer at list index. */
dlnode_valptr_t dlist_get_val_at(dlist_t *list, int i);

/* Set value-pointer at list index. Returns previous value-pointer. */
dlnode_valptr_t dlist_set_val_at(dlist_t *list, int i, dlnode_valptr_t newval);

/*
** LIST OPERATIONS
*/

/* Removes all nodes from list, but does not delete list. */
void dlist_empty(dlist_t *list);

/* Removes all nodes from list, and then deletes list. */
void dlist_delete_list(dlist_t *list);

#endif /* DLIST_H_ */
