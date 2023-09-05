#include "queue.h"
#include "../dlist/dlist.h"
#include <stdlib.h>

queuenode_valptr_t queue_remove(queue_t *queue) {
  // make sure queue is not empty before proceeding
  if (queue->length == 0) return NULL;
  
  // store current queue top and its value
  queuenode_t *head = queue->dummy->next;
  queuenode_valptr_t val = head->value_ptr;
  
  dlist_delete_node(queue, head);
  
  return val;
}

void queue_add(queue_t *queue, queuenode_valptr_t value_ptr) {
  dlist_add(queue, queue->length, value_ptr);
}

