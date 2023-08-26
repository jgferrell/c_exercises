#include "queue.h"
#include <stdio.h>

int main() {
  int size = 10;
  int values[size];

  // array of arbitrary values
  for (int i = 0; i < size; ++i) {
    values[i] = i;
  }

  queue_t queue = { .length = 0, .head = NULL, .tail = NULL};
  printf("Adding to the queue:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    queue_add(&queue, &values[i]);
  }
  putchar('\n');

  // should print: 0 1 2 3 4 5 6 7 8 9
  printf("Removing from the queue:\n");
  while (queue.head != NULL) {
    int *val = queue_remove(&queue);  // cast void pointer to int pointer
    printf("%i ", *val);              // dereference int pointer to int
  }
  putchar('\n');
  
  return 0;
}
