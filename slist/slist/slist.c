#include "slist.h"
#include <stdlib.h>

/* Initialization: list and node */
slist_t * slist_new_list(void);
slnode_t * slist_new_node(slnode_valptr_t value_ptr);

/* Node operations */
slnode_t * slist_get_node(slist_t* list, int node_index);
slnode_t * slist_insert_node(slist_t *list, int node_index, slnode_valptr_t value_ptr);
void slist_delete_node(slist_t *list, slnode_t *node);
void slist_delete_node_at(slist_t *list, int node_index);

/* List operations */
void slist_empty(slist_t *list);
void slist_delete_list(slist_t *list);


/*
** INITIALIZATION OPERATIONS
*/

/* Returns pointer to new list; allocates memory. */
slist_t * slist_new_list(void) {
  slist_t *list = malloc(sizeof(slist_t));
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;

  return list;
}

/* Returns pointer to new node; allocates memory. */
slnode_t * slist_new_node(slnode_valptr_t value_ptr) {
  slnode_t *node = malloc(sizeof(slnode_t));
  node->value_ptr = value_ptr;
  node->next = NULL;

  return node;
}

/*
** NODE OPERATIONS
*/

/* Returns pointer to node at specified index of given list. */
slnode_t * slist_get_node(slist_t* list, int node_index) {
  if (node_index == list->length - 1) return list->tail;

  slnode_t *curnode = list->head;
  for (int i = 0; i < node_index; ++i) {
    if (i == node_index) break;
    curnode = curnode->next;
  }
  
  return curnode;
}

/* Inserts a node at specified index of given list. Populates node
   with given value-pointer and returns pointer to new node. */
slnode_t * slist_insert_node(slist_t *list, int node_index, slnode_valptr_t value_ptr) {
  
  /* create new node & allocate memory */
  slnode_t *node = slist_new_node(value_ptr);  
  
  /* add new node at specified index */
  if (node_index == 0) {
    /* adding new head node */
    node->next = list->head;
    list->head = node;
    /* if this is the first node, also add it as a tail */
    if (list->length == 0) list->tail = node;
  } else if (node_index == list->length) {
    /* adding new tail node */
    list->tail->next = node;
    list->tail = node;
  } else {
    slnode_t *prev = slist_get_node(list, node_index - 1);
    node->next = prev->next;
    prev->next = node;
  }

  /* increment length of list */
  list->length = list->length + 1;

  return node;
}

void slist_delete_node(slist_t *list, slnode_t *node) {
  if (node != list->head) {
    slnode_t *prev = list->head;
    while (prev->next != node) prev = prev->next;
    prev->next = prev->next->next;
    if (node == list->tail) list->tail = prev;
  } else {
    list->head = list->head->next;
  }

  /* free target node memory */
  free(node);
  
  /* update list length */
  list->length = list->length - 1;
}

/* Delete the node at the given index and update the list. */
void slist_delete_node_at(slist_t *list, int node_index) {
  slnode_t *node = slist_get_node(list, node_index);
  slist_delete_node(list, node);
}

/*
** LIST OPERATIONS
*/

void slist_empty(slist_t *list) {
  while(list->length > 0) slist_delete_node(list, list->head);
}

void slist_delete_list(slist_t *list) {
  slist_empty(list);
  free(list);
}
