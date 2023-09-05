#include "slist.h"
#include <stdlib.h>

slist_t slist_build(int num_nodes, slnode_valptr_t value_ptrs, size_t value_size) {
  // initialize linked list to return
  slist_t list = list;
  list.length = num_nodes;
  list.head = NULL;
  list.tail = NULL;

  // build linked list
  slnode_t *prev, *node;
  for (int i = 0; i < num_nodes; ++i) {
    
    // create new node
    node = malloc(sizeof(slnode_t));
    node->value_ptr = value_ptrs + i * value_size;
    node->next = NULL;

    // connect new node to previous node
    if (i > 0) {
      prev->next = node;
    } else {
      list.head = node;
    }
  
    // prepare `prev` for next new node
    prev = node;

    if (i + 1 == num_nodes) {
      list.tail = node;
    }
  }
  
  return list;
}

slnode_t * slist_get_node(slist_t* list, int node_index) {
  if (node_index == list->length - 1) return list->tail;

  slnode_t *curnode = list->head;
  for (int i = 0; i < node_index; ++i) {
    if (i == node_index) break;
    curnode = curnode->next;
  }
  
  return curnode;
}

slnode_t * slist_insert_node(slist_t *list, int node_index, slnode_valptr_t value_ptr) {
  // create new node & allocate memory
  slnode_t *node = malloc(sizeof(slnode_t));
  node->value_ptr = value_ptr;
  node->next = NULL;

  // add new node at specified index
  slnode_t *curnode;
  if (node_index == 0) {
    /* adding new head node */
    node->next = list->head;
    list->head = node;
    /* if this is the first node, add a tail */
    if (list->length == 0) list->tail = node;
  } else if (node_index == list->length) {
    /* adding new tail node */
    list->tail->next = node;
    list->tail = node;
  } else {
    curnode = list->head;
    for (int i = 1; i < node_index; ++i) {
      curnode = curnode->next;
    }
    node->next = curnode->next;
    curnode->next = node;
  }
  list->length = list->length + 1;

  return node;
}

void slist_delete_node(slist_t *list, int node_index) {
  slnode_t *prev, *target;

  if (node_index == 0) {
    /* deleting head node and updating pointer */
    target = list->head;
    list->head = target->next;
  } else {
    /* list traversal to node preceding target index */
    target = list->head;
    for (int i = 0; i < node_index; ++i) {
      prev = target;
      target = target->next;
    }
    prev->next = target->next;
    
    if (node_index == list->length - 1) {
      /* updating tail pointer if we deleted a tail node */
      list->tail = prev;
    }
  }

  /* free target node memory */
  free(target);
  
  /* update list length */
  list->length = list->length - 1;
}

void slist_empty(slist_t *list) {
  slnode_t *prev, *curnode;
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
