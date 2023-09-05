// queue.h

#ifndef QUEUE_H_
#define QUEUE_H_

#include "../slist/slist.h"

// slist AKA queue
typedef slnode_valptr_t queuenode_valptr_t;
typedef slnode_t queuenode_t;
typedef slist_t queue_t;

/* Remove top node from queue; return its value-pointer. */
queuenode_valptr_t queue_remove(queue_t *queue);

/* Adds a new value-pointer to the top of the queue. */
void queue_add(queue_t *queue, queuenode_valptr_t value_ptr);

/* Returns a queue of provided length, loaded with value-pointers
   provided. */
queue_t queue_build(int num_nodes, queuenode_valptr_t value_ptrs,
		    size_t value_size);

#endif /* QUEUE_H_ */
