#include "dlist.h"
#include <stddef.h>
#include <stdlib.h>

dlnode_t * dlist_get_node(dlist_t* list, int node_index) {
  dlnode_t *curnode;
  if (node_index < list->length/2) {
    curnode = list->head;
    for (int i = 0; i < node_index; ++i) {
      curnode = curnode->next;
    }
  } else {
    curnode = list->tail;
    for (int i = 0; i < node_index-1; ++i) {
      curnode = curnode->prev;
    }
  }
  
  return curnode;
}

dlist_t * dlist_new_list() {
  dlist_t *list = malloc(sizeof(dlist_t));
  list->head = NULL;
  list->tail = NULL;
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

void dlist_add_first_node(dlist_t *list, dlnode_t *node) {
  list->head = node;
  list->tail = node;
  list->length = 1;
}

dlnode_t * dlist_add_node_after(dlist_t *list, dlnode_t *prev_node,
				dlnode_valptr_t value_ptr)
{
  dlnode_t *new_node = dlist_new_node(value_ptr);
  if (list->length > 0) {
    new_node->prev = prev_node;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    list->length = list->length + 1;
    if (list->tail == prev_node) list->tail = new_node;
  } else {
    dlist_add_first_node(list, new_node);
  }
  return new_node;
}


dlnode_t * dlist_add_node_before(dlist_t *list, dlnode_t *next_node,
				 dlnode_valptr_t value_ptr)
{
  dlnode_t *new_node = dlist_new_node(value_ptr);
  if (list->length > 0) {
    new_node->next = next_node;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    list->length = list->length + 1; 
    if (list->head == next_node) list->head = new_node;
  } else {
    dlist_add_first_node(list, new_node);
  }
  return new_node;
}

dlnode_t * dlist_insert_node_at_index(dlist_t *list, int node_index,
				      dlnode_valptr_t value_ptr)
{
  // add new node at specified index
  dlnode_t *new_node;
  if (node_index == 0) {
    new_node = dlist_add_node_before(list, list->head, value_ptr);
  } else {
    dlnode_t *prev_node = dlist_get_node(list, node_index-1);
    new_node = dlist_add_node_after(list, prev_node, value_ptr);
  }
  return new_node;
}

void dlist_delete_node(dlist_t *list, dlnode_t *node) {
  if (node == list->head) {
    list->head = node->next;
    if (list->head != NULL) list->head->prev = NULL;
  } else if (node == list->tail) {
    list->tail = node->prev;
    if (list->tail != NULL) list->tail->next = NULL;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  list->length = list->length - 1;  
  free(node);
}

void dlist_empty(dlist_t *list) {
  dlnode_t *prev, *curnode;
  prev = list->head;
  while (prev->next != NULL) {
    curnode = prev->next;
    free(prev);
    prev = curnode;
  }
  free(prev);

  /* update list info */
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;
}

void dlist_delete_list(dlist_t *list) {
  dlist_empty(list);
  free(list);
}
