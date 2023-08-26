#include "deque.h"
#include "../slist/slist.h"
#include <stdio.h>
#include <stdlib.h>

dequenode_valptr_t deque_remove_top(deque_t *deque) {
  // make sure deque is not empty before proceeding
  if (deque->length == 0) return NULL;
  
  // store current deque top and its value
  dequenode_t *popped = deque->head;
  dequenode_valptr_t val = popped->value_ptr;
  
  slist_delete_node(deque, 0);
  
  return val;
}

dequenode_valptr_t deque_remove_bottom(deque_t *deque) {
  // make sure deque is not empty before proceeding
  if (deque->length == 0) return NULL;
  
  // store current deque bottom and its value
  dequenode_t *popped = deque->tail;
  dequenode_valptr_t val = popped->value_ptr;
  
  slist_delete_node(deque, deque->length - 1);
  
  return val;
}

void deque_add_top(deque_t *deque, dequenode_valptr_t value_ptr) {
  slist_insert_node(deque, 0, value_ptr);
}

void deque_add_bottom(deque_t *deque, dequenode_valptr_t value_ptr) {
  if (deque->length > 0) {
    slist_insert_node(deque, deque->length, value_ptr);
  } else {
    slist_insert_node(deque, 0, value_ptr);
  }
}

deque_t deque_build(int num_nodes, dequenode_valptr_t value_ptrs, size_t value_size) {
  return slist_build(num_nodes, value_ptrs, value_size);
}
