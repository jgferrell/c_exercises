#include "queue.h"
#include "../slist/slist.h"
#include <stdio.h>
#include <stdlib.h>

queuenode_valptr_t queue_remove(queue_t *queue) {
  // make sure queue is not empty before proceeding
  if (queue->length == 0) return NULL;
  
  // store current queue top and its value
  queuenode_t *popped = queue->head;
  queuenode_valptr_t val = popped->value_ptr;
  
  slist_delete_node(queue, 0);
  
  return val;
}

void queue_add(queue_t *queue, queuenode_valptr_t value_ptr) {
  slist_insert_node(queue, queue->length, value_ptr);
}

queue_t queue_build(int num_nodes, queuenode_valptr_t value_ptrs, size_t value_size) {
  return slist_build(num_nodes, value_ptrs, value_size);
}
