#include "stack.h"
#include "../dlist/dlist.h"
#include <stddef.h>

stacknode_valptr_t stack_pop(stack_t *stack) {
  // make sure stack is not empty before proceeding
  if (stack->length == 0) return NULL;
  
  // store current stack top and its value
  stacknode_t *head = stack->dummy->next;
  stacknode_valptr_t val = head->value_ptr;
  
  dlist_delete_node(stack, head);
  
  return val;
}

void stack_push(stack_t *stack, stacknode_valptr_t value_ptr) {
  dlist_add(stack, 0, value_ptr);
}
