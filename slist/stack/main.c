#include "stack.h"
#include <stdio.h>

int main() {
  int size = 10;
  int values[size];
  printf("Pushing to the stack:\n");
  for (int i = 0; i < size; ++i) {
    printf("%i ", i);
    values[i] = i;
  }
  putchar('\n');

  // build a stack; tests the push function
  stack_t stack = stack_build(size, values, sizeof(int));

  // empty the stack; tests the pop function
  // should print: 9 8 7 6 5 4 3 2 1 0
  printf("Popping from the stack:\n");
  while (stack.head != NULL) {
    int *val = stack_pop(&stack);  // cast void pointer to int pointer
    printf("%i ", *val);           // dereference int pointer to int
  }
  putchar('\n');
  
  return 0;
}
