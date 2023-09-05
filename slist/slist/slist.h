// slist.h

#ifndef SLIST_H_
#define SLIST_H_

/*
** DATA STRUCTURES & TYPES
*/

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

/*
** INITIALIZATION OPERATIONS
*/

/* Returns a pointer to a properly initialized singly-linked list. */
slist_t * slist_new_list();

/*
** NODE OPERATIONS
*/

/* Returns a pointer to the node requested by index (index is the
   number of nodes between target node and head node). */
slnode_t * slist_get_node(slist_t *list, int node_index);

/* Inserts a new node at specified index with specified value. Returns
   a pointer to the new node. */
slnode_t * slist_insert_node(slist_t *list, int node_index, slnode_valptr_t valptr);

/* Removes given node from given list and deletes node. */
void slist_delete_node(slist_t *list, slnode_t *node);

/* Removes node at index of given list and deletes node. */
void slist_delete_node_at(slist_t *list, int node_index);

/*
** LIST OPERATIONS
*/

/* Removes all nodes from list, but does not delete list. */
void slist_empty(slist_t *list);

/* Removes all nodes from list, and then deletes list. */
void slist_delete_list(slist_t *list);

#endif /* SLIST_H_ */
