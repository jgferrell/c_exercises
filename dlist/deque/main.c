#include "deque.h"
#include <stdio.h>

#define SIZE 10

/* Convert value-pointer to int value. */
int vp2i(dequenode_valptr_t valptr) {
  int *p = valptr;  // cast void pointer to int pointer
  return *p;        // dereference int pointer to int
}

void to_top(deque_t *deque, int values[SIZE]) {
  printf("Adding to the TOP of the deque:\n");
  printf("1st-> ");
  for (int i = 0; i < SIZE; ++i) {
    deque_add_top(deque, &values[i]);
    printf("%i ", values[i]);
  }
  printf("<- Nth\n");
  
  printf("TOP-> ");
  for (dequenode_t *node = deque->dummy->next; node != deque->dummy; node = node->next)
    printf("%i ", vp2i(node->value_ptr));
  printf("<- BTM\n");    
}

void to_btm(deque_t *deque, int values[SIZE]) {
  printf("Adding to the BOTTOM of the deque:\n");
  printf("1st-> ");
  for (int i = 0; i < SIZE; ++i) {
    deque_add_bottom(deque, &values[i]);
    printf("%i ", values[i]);
  }
  printf("<- Nth\n");
  
  printf("TOP-> ");
  for (dequenode_t *node = deque->dummy->next; node != deque->dummy; node = node->next)
    printf("%i ", vp2i(node->value_ptr));
  printf("<- BTM\n");    
}

void rm_btm(deque_t *deque) {
  printf("Removing from the BOTTOM of the deque:\n");
  printf("1st-> ");
  while (deque->length > 0) printf("%i ", vp2i(deque_remove_bottom(deque)));
  printf("<- Nth\n");
}

void rm_top(deque_t *deque) {
  printf("Removing from the TOP of the deque:\n");
  printf("1st-> ");
  while (deque->length > 0) printf("%i ", vp2i(deque_remove_top(deque)));
  printf("<- Nth\n");
}

int main() {
  // array of arbitrary values
  int values[SIZE];
  for (int i = 0; i < SIZE; ++i) values[i] = i;

  // initialize the deque
  deque_t *deque = dlist_new_list();

  /* --------------------------------------
   * ADD TO TOP AND THEN REMOVE FROM BOTTOM 
   * --------------------------------------
   * Adding to the TOP of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * TOP-> 9 8 7 6 5 4 3 2 1 0 <- BTM
   * Removing from the BOTTOM of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * --------------------------------------
   */  
  to_top(deque, values);
  rm_btm(deque);
  putchar('\n');

  /* --------------------------------------
   * ADD TO BOTTOM AND THEN REMOVE FROM TOP 
   * --------------------------------------
   * Adding to the BOTTOM of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * TOP-> 0 1 2 3 4 5 6 7 8 9 <- BTM
   * Removing from the TOP of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * --------------------------------------
   */
  to_btm(deque, values);
  rm_top(deque);
  putchar('\n');


  /* --------------------------------------
   * ADD TO BOTTOM AND THEN REMOVE FROM BOTTOM 
   * --------------------------------------
   * Adding to the BOTTOM of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * TOP-> 0 1 2 3 4 5 6 7 8 9 <- BTM
   * Removing from the BOTTOM of the deque:
   * 1st-> 9 8 7 6 5 4 3 2 1 0 <- Nth
   * --------------------------------------
   */
  to_btm(deque, values);
  rm_btm(deque);
  putchar('\n');

  /* --------------------------------------
   * ADD TO TOP AND THEN REMOVE FROM TOP
   * --------------------------------------
   * Adding to the TOP of the deque:
   * 1st-> 0 1 2 3 4 5 6 7 8 9 <- Nth
   * TOP-> 9 8 7 6 5 4 3 2 1 0 <- BTM
   * Removing from the TOP of the deque:
   * 1st-> 9 8 7 6 5 4 3 2 1 0 <- Nth
   * --------------------------------------
   */
  to_top(deque, values);
  rm_top(deque);
  putchar('\n');
  
  return 0;
}
