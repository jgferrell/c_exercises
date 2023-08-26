#include "deque.h"
#include <stdio.h>

int main() {
  int size = 10;
  int values[size];

  // array of arbitrary values
  for (int i = 0; i < size; ++i) {
    values[i] = i;
  }

  // initialize the deque
  deque_t deque = { .length = 0, .head = NULL, .tail = NULL};

  /* ADD TO TOP AND THEN REMOVE FROM BOTTOM 
     [bottom] 0 1 2 3 4 5 6 7 8 9 [top]
     [first] 0 1 2 3 4 5 6 7 8 9 [last]
   */  
  printf("Adding to the TOP of the deque:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    deque_add_top(&deque, &values[i]);
  }
  putchar('\n');
  
  // should print: 
  printf("Removing from the BOTTOM of the deque:\n");
  while (deque.head != NULL) {
    int *val = deque_remove_bottom(&deque);  // cast void pointer to int pointer
    printf("%i ", *val);                     // dereference int pointer to int
  }
  putchar('\n');

  /* ADD TO BOTTOM AND THEN REMOVE FROM TOP 
     [top] 0 1 2 3 4 5 6 7 8 9 [bottom]
     [first] 0 1 2 3 4 5 6 7 8 9 [last]
   */

  printf("Adding to the BOTTOM of the deque:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    deque_add_top(&deque, &values[i]);
  }
  putchar('\n');

  printf("Removing from the TOP of the deque:\n");
  while (deque.head != NULL) {
    int *val = deque_remove_bottom(&deque);  // cast void pointer to int pointer
    printf("%i ", *val);                     // dereference int pointer to int
  }
  putchar('\n');


  /* ADD TO BOTTOM AND THEN REMOVE FROM BOTTOM 
     [top] 0 1 2 3 4 5 6 7 8 9 [bottom]
     [first] 9 8 7 6 5 4 3 2 1 0 [last]
   */
  
  printf("Adding to the BOTTOM of the deque:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    deque_add_bottom(&deque, &values[i]);
  }
  putchar('\n');
  
  printf("Removing from the BOTTOM of the deque:\n");
  while (deque.head != NULL) {
    int *val = deque_remove_bottom(&deque);  // cast void pointer to int pointer
    printf("%i ", *val);                     // dereference int pointer to int
  }
  putchar('\n');

  /* ADD TO TOP AND THEN REMOVE FROM TOP
     [bottom] 0 1 2 3 4 5 6 7 8 9 [top]
     [first] 9 8 7 6 5 4 3 2 1 0 [last]
  */
  printf("Adding to the TOP of the deque:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    deque_add_top(&deque, &values[i]);
  }
  putchar('\n');

  printf("Removing from the TOP of the deque:\n");
  while (deque.head != NULL) {
    int *val = deque_remove_top(&deque);  // cast void pointer to int pointer
    printf("%i ", *val);                     // dereference int pointer to int
  }
  putchar('\n');
  
  return 0;
}
