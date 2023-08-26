#include "stack.h"
#include <stdio.h>

int main() {
  int size = 10;
  int values[size];

  // array of arbitrary values
  for (int i = 0; i < size; ++i) {
    values[i] = i;
  }

  // build a stack; tests the push function
  stack_t stack = { .length = 0, .head = NULL, .tail = NULL };  
  printf("Pushing to the stack:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    stack_push(&stack, &values[i]);
  }
  putchar('\n');

  // empty the stack; tests the pop function
  // should print: 9 8 7 6 5 4 3 2 1 0
  printf("Popping from the stack:\n");
  while (stack.head != NULL) {
    int *val = stack_pop(&stack);  // cast void pointer to int pointer
    printf("%i ", *val);           // dereference int pointer to int
  }
  putchar('\n');


  // test the stack_build function
  printf("\nRepopulating the stack with `stack_build` function.\n");
  stack = stack_build(size, values, sizeof(int));

  printf("Popping from the stack:\n");
  while (stack.head != NULL) {
    int *val = stack_pop(&stack);  // cast void pointer to int pointer
    printf("%i ", *val);           // dereference int pointer to int
  }
  putchar('\n');
  
  return 0;
}
