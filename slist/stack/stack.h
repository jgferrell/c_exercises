// stack.h

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>
#include "../slist/slist.h"

// slist AKA stack
typedef slnode_valptr_t stacknode_valptr_t;
typedef slnode_t stacknode_t;
typedef slist_t stack_t;

/* Remove top node from stack; return its value-pointer. */
stacknode_valptr_t stack_pop(stack_t *stack);

/* Adds a new value-pointer to the top of the stack. */
void stack_push(stack_t *stack, stacknode_valptr_t value_ptr);

/* Returns a stack of provided length, loaded with value-pointers
   provided. */
stack_t stack_build(int num_nodes, stacknode_valptr_t value_ptrs,
		    size_t value_size);

#endif /* STACK_H_ */
