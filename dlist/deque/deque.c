#include "deque.h"
#include "../dlist/dlist.h"
#include <stdio.h>
#include <stdlib.h>

dequenode_valptr_t deque_remove_top(deque_t *deque) {
  // make sure deque is not empty before proceeding
  if (deque->length == 0) return NULL;
  
  // store current deque top and its value
  dequenode_t *head = deque->dummy->next;
  dequenode_valptr_t val = head->value_ptr;
  
  dlist_delete_node(deque, head);
  
  return val;
}

dequenode_valptr_t deque_remove_bottom(deque_t *deque) {
  // make sure deque is not empty before proceeding
  if (deque->length == 0) return NULL;
  
  // store current deque bottom and its value
  dequenode_t *tail = deque->dummy->prev;
  dequenode_valptr_t val = tail->value_ptr;
  
  dlist_delete_node(deque, tail);
  
  return val;
}

void deque_add_top(deque_t *deque, dequenode_valptr_t value_ptr) {
  dlist_add(deque, 0, value_ptr);
}

void deque_add_bottom(deque_t *deque, dequenode_valptr_t value_ptr) {
  dlist_add_before(deque, deque->dummy, value_ptr);
}
