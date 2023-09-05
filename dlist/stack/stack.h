// stack.h

#ifndef STACK_H_
#define STACK_H_

#include "../dlist/dlist.h"

// dlist AKA stack
typedef dlnode_valptr_t stacknode_valptr_t;
typedef dlnode_t stacknode_t;
typedef dlist_t stack_t;

/* Remove top node from stack; return its value-pointer. */
stacknode_valptr_t stack_pop(stack_t *stack);

/* Adds a new value-pointer to the top of the stack. */
void stack_push(stack_t *stack, stacknode_valptr_t value_ptr);

#endif /* STACK_H_ */
