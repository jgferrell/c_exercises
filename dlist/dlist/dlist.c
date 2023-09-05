#include "dlist.h"
#include <stdlib.h>

/*
** INITIALIZATION OPERATIONS
*/

/* Create new list. */
dlist_t * dlist_new_list();

/* Create new node. Allocates memory. Returns pointer to new node. */
dlnode_t * dlist_new_node(dlnode_valptr_t value_ptr);

/*
** NODE OPERATIONS
*/

/* Add new node at index. Returns pointer to new node. */
dlnode_t * dlist_add(dlist_t *list, int i, dlnode_valptr_t newval);

/* Get node by index. Returns pointer. */
dlnode_t * dlist_get_node(dlist_t *list, int node_index);

/* Delete provided node from list. Frees memory. */
void dlist_delete_node(dlist_t *list, dlnode_t *node);

/* Delete node at specified index from list. Frees memory. */
void dlist_delete_node_at(dlist_t *list, int i);

/* Add new node before next_node. Returns pointer to new node. */
dlnode_t * dlist_add_before(dlist_t *list, dlnode_t * next_node, dlnode_valptr_t value_ptr);

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


/*****************************************
 *                                       *
 * DEFINITIONS                           *
 *                                       *
 *****************************************/

/*
** INITIALIZATION OPERATIONS
*/

dlist_t * dlist_new_list() {
  dlist_t *list = malloc(sizeof(dlist_t));
  // prep dummy node
  dlnode_t *dummy = dlist_new_node(0x0);
  dummy->prev = dummy;
  dummy->next = dummy;
  // prep list
  list->dummy = dummy;
  list->length = 0;
  return list;
}

dlnode_t * dlist_new_node(dlnode_valptr_t value_ptr) {
  dlnode_t *new_node = malloc(sizeof(dlnode_t));
  new_node->value_ptr = value_ptr;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}


/*
** NODE OPERATIONS
*/

/* Adding nodes. */

dlnode_t * dlist_add(dlist_t *list, int i, dlnode_valptr_t newval) {
  return dlist_add_before(list, dlist_get_node(list, i), newval);
}

dlnode_t * dlist_add_before(dlist_t *list, dlnode_t * next_node, dlnode_valptr_t newval) {
  dlnode_t *newnode = dlist_new_node(newval);
  newnode->prev = next_node->prev;
  newnode->next = next_node;
  newnode->next->prev = newnode;
  newnode->prev->next = newnode;
  list->length = list->length + 1;
  return newnode;
}

/* Retrieving nodes. */

dlnode_t * dlist_get_node(dlist_t *list, int node_index) {
  dlnode_t *curnode;
  if (node_index < list->length/2) {
    curnode = list->dummy->next;
    for (int i = 0; i < node_index; ++i) {
      curnode = curnode->next;
    }
  } else {
    curnode = list->dummy;
    for (int i = 0; i < list->length - node_index; ++i) {
      curnode = curnode->prev;
    }
  }
  
  return curnode;
}

/* Deleting nodes. */

void dlist_delete_node(dlist_t *list, dlnode_t *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  list->length = list->length - 1;  
  free(node);
}

void dlist_delete_node_at(dlist_t *list, int i) {
  dlist_delete_node(list, dlist_get_node(list, i));
}

/*
** VALUE OPERATIONS
*/

dlnode_valptr_t dlist_get_val_at(dlist_t *list, int i) {
  dlnode_t *node = dlist_get_node(list, i);
  return node->value_ptr;
}

dlnode_valptr_t dlist_set_val_at(dlist_t *list, int i, dlnode_valptr_t newval) {
  dlnode_t *node = dlist_get_node(list, i);
  dlnode_valptr_t oldval = node->value_ptr;
  node->value_ptr = newval;
  return oldval;
}


/*
** LIST OPERATIONS
*/

void dlist_empty(dlist_t *list) {
  dlnode_t *node = list->dummy->next;
  while (node->next->prev != list->dummy) {
    node = node->next;
    dlist_delete_node(list, node->prev);
  }
}

void dlist_delete_list(dlist_t *list) {
  dlist_empty(list);
  free(list->dummy);
  free(list);
}
