// deque.h

#ifndef DEQUE_H_
#define DEQUE_H_

#include <stddef.h>
#include "../dlist/dlist.h"

// dlist AKA deque
typedef dlnode_valptr_t dequenode_valptr_t;
typedef dlnode_t dequenode_t;
typedef dlist_t deque_t;

/* Remove top node from deque; return its value-pointer. */
dequenode_valptr_t deque_remove_top(deque_t *deque);

/* Remove bottom node from deque; return its value-pointer. */
dequenode_valptr_t deque_remove_bottom(deque_t *deque);

/* Adds a new value-pointer to the top of the deque. */
void deque_add_top(deque_t *deque, dequenode_valptr_t value_ptr);

/* Adds a new value-pointer to the bottom of the deque. */
void deque_add_bottom(deque_t *deque, dequenode_valptr_t value_ptr);

#endif /* DEQUE_H_ */
