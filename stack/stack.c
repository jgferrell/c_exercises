#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_val stack_pop(stack_t *stack) {
  // store current stack top and its value
  stack_node *popped = stack->top;
  stack_val *val = popped->value_ptr;
  
  // move stack top pointer down by one
  stack->top = popped->prev;

  // reduce stack length
  stack->length = stack->length - 1;

  // get rid of old stack top
  free(popped);
  
  return val;
}

void stack_push(stack_t *stack, stack_val value_ptr) {
  // create new node with provided value
  stack_node *pushed = malloc(sizeof(stack_node));
  pushed->value_ptr = value_ptr;

  // push to top of stack
  if (0 != stack->length) {
    pushed->prev = stack->top;
  } else { // link to previous node
    pushed->prev = NULL;
  } // already at top of stack
  stack->top = pushed;

  // increase stack length
  stack->length = stack->length + 1;
}

stack_t stack_build(int length, stack_val value_ptrs, size_t value_size) {
  // initialize new stack
  stack_t stack;
  stack.length = 0;

  // push values onto stack
  for (int i = 0; i < length; ++i) stack_push(&stack, value_ptrs + i * value_size);

  // return stack
  return stack;
}
