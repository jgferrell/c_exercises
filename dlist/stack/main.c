#include "stack.h"
#include <stdio.h>

#define SIZE 10

void build_stack(stack_t *stack, int values[SIZE]) {
  printf("Pushing to the stack:\n");
  for (int i = 0; i < SIZE; ++i) {
    printf("%i ", i);
    stack_push(stack, &values[i]);
  }
  putchar('\n');  
}

void empty_stack(stack_t * stack) {
  printf("Popping from the stack:\n");
  while (stack->length > 0) {
    int *val = stack_pop(stack);  // cast void pointer to int pointer
    printf("%i ", *val);           // dereference int pointer to int
  }
  putchar('\n');
}

int main() {
  // array of arbitrary values
  int values[SIZE];
  for (int i = 0; i < SIZE; ++i) values[i] = i;

  // get new stack
  stack_t *stack = dlist_new_list();

  // fill stack; tests push function
  build_stack(stack, values);
  
  // empty the stack; tests pop function
  // should print: 9 8 7 6 5 4 3 2 1 0
  empty_stack(stack);

  printf("Deleting list.\n");
  dlist_delete_list(stack);
  
  return 0;
}
