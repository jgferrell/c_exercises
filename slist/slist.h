// slist.h

#ifndef SLIST_H_
#define SLIST_H_

#include <stddef.h>

/* slnode_valptr_t: a pointer to a node-value */
typedef void * slnode_valptr_t;

/* slnode_t: the node of a singly-linked list; has a value-pointer and
   a pointer to the next node in the list */
struct slnode_t {
  slnode_valptr_t value_ptr;
  struct slnode_t *next;
};
typedef struct slnode_t slnode_t;

/* slist_t: a singly-linked list; `length` keeps track of how many
   nodes are in the list, `head` points to the first node in the list,
   and `tail` points to the last node. */
typedef struct {
  int length;
  slnode_t *head;
  slnode_t *tail;
} slist_t;

/* Builds a singly-linked list from an array of node
   value-pointers. */
slist_t slist_build(int num_nodes, slnode_valptr_t value_ptrs, size_t value_size);

/* Returns a pointer to the node requested by index (index is the
   number of nodes between target node and head node). */
slnode_t * slist_get_node(slist_t *list, int node_index);

/* Inserts a new node at specified index with specified value. Returns
   a pointer to the new node. */
slnode_t * slist_insert_node(slist_t *list, int node_index, slnode_valptr_t valptr);

/* Delete the list node at specified index. */
void slist_delete_node(slist_t *list, int node_index);

/* Deletes all nodes from list, freeing allocated memory. */
void slist_empty(slist_t *list);

#endif /* SLIST_H_ */
