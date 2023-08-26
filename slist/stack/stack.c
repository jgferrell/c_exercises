#include "stack.h"
#include "../slist/slist.h"
#include <stdio.h>
#include <stdlib.h>

stacknode_valptr_t stack_pop(stack_t *stack) {
  // make sure stack is not empty before proceeding
  if (stack->length == 0) return NULL;
  
  // store current stack top and its value
  stacknode_t *popped = stack->head;
  stacknode_valptr_t val = popped->value_ptr;
  
  slist_delete_node(stack, 0);
  
  return val;
}

void stack_push(stack_t *stack, stacknode_valptr_t value_ptr) {
  slist_insert_node(stack, 0, value_ptr);
}

stack_t stack_build(int num_nodes, stacknode_valptr_t value_ptrs, size_t value_size) {
  return slist_build(num_nodes, value_ptrs, value_size);
}
