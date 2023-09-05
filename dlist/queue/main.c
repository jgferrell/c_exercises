#include "queue.h"
#include <stdio.h>

#define SIZE 10

void queue_build(queue_t *queue, int values[SIZE]) {
  printf("Adding to the queue:\n");
  for (int i = 0; i < SIZE; ++i) {
    printf("%i ", i);
    queue_add(queue, &values[i]);
  }
  putchar('\n');
}

void queue_empty(queue_t *queue) {  
  printf("Removing from the queue:\n");
  while (queue->length > 0) {
    int *val = queue_remove(queue);  // cast void pointer to int pointer
    printf("%i ", *val);              // dereference int pointer to int
  }
  putchar('\n');
}

int main() {
  // array of arbitrary values
  int values[SIZE];
  for (int i = 0; i < SIZE; ++i) values[i] = i;

  // new queue
  queue_t *queue = dlist_new_list();

  // build queue; tests add function
  queue_build(queue, values);

  // empty queue; tests remove function
  // should print: 0 1 2 3 4 5 6 7 8 9
  queue_empty(queue);

  dlist_delete_list(queue);
  
  return 0;
}
