// stack.h

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

/* Use void pointer as stack value type, so that we can create a stack
   of generic pointers. */
typedef void * stack_val_t;

/* Each stack node contains a "value-pointer" (a pointer to some
   arbitrary value) and links to the previous node in the stack. If
   the node is at the top of the stack, it's `prev` value will be
   NULL. */
struct stack_node {
  stack_val_t value_ptr;
  struct stack_node *prev;
};
typedef struct stack_node stack_node;

/* The stack structure itself. */
typedef struct stack_t {
  int length;
  stack_node *top;
} stack_t;

/* Remove top node from stack; return its value. */
stack_val_t stack_pop(stack_t *stack);

/* Adds a new value-pointer to the top of the stack. */
void stack_push(stack_t *stack, stack_val_t value_ptr);

/* Returns a stack of provided length, loaded with value-pointers provided. */
stack_t stack_build(int length, stack_val_t value_ptrs, size_t value_size);

#endif /* STACK_H_ */
