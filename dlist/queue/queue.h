// queue.h

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>
#include "../dlist/dlist.h"

// dlist AKA queue
typedef dlnode_valptr_t queuenode_valptr_t;
typedef dlnode_t queuenode_t;
typedef dlist_t queue_t;

/* Remove top node from queue; return its value-pointer. */
queuenode_valptr_t queue_remove(queue_t *queue);

/* Adds a new value-pointer to the top of the queue. */
void queue_add(queue_t *queue, queuenode_valptr_t value_ptr);

#endif /* QUEUE_H_ */
