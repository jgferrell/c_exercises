#include "array.h"
#include <stdlib.h>

/* Initialization: list and node */
array_t * array_new(int length);

/* Node operations */
arvalptr_t array_get(const array_t *arr, int node_index);
void array_set(array_t *arr, int node_index, arvalptr_t value_ptr);


/* Array operations */
void array_delete(array_t *arr);
void array_expand(array_t *arr, int increase_by);
array_t * array_combine(const array_t *arr0, const array_t *arr1);

/*
** INITIALIZATION OPERATIONS
*/

/* Returns pointer to new list; allocates memory. */
array_t * array_new(int length) {
  array_t *arr = malloc(sizeof(array_t));
  size_t sz = sizeof(arvalptr_t);
  arr->start = malloc(sz * length);
  arr->length = length;
  return arr;
}

/*
** NODE OPERATIONS
*/

/* Returns the value-pointer of the specified array node. */
arvalptr_t array_get(const array_t* arr, int node_index) {
  return *(arr->start + node_index);
}

/* Returns the value-pointer of the specified array node. */
void array_set(array_t *arr, int node_index, arvalptr_t value_ptr) {
  arvalptr_t *dest = arr->start + node_index;
  *dest = value_ptr;
}

/*
** ARRAY OPERATIONS
*/

/* Deletes the array and frees all allocated memory. */
void array_delete(array_t *arr) {
  free(arr->start);
  free(arr);
}

/* Expands the size of the array by the provided int value. */
void array_expand(array_t *arr, int expand_by) {
  if (expand_by > 0) {
    arvalptr_t *old_block = arr->start;
    int newlen = arr->length + expand_by;
    arr->start = malloc(newlen * sizeof(arvalptr_t));
    for (int i = 0; i < arr->length; ++i)
      array_set(arr, i, *(old_block + i));
    free(old_block);
    arr->length = newlen;
  }
}

/* Combines the two provided arrays by appending the second array to
   the end of the first. Returns a pointer to the resulting array. */
array_t * array_combine(const array_t *arr0, const array_t *arr1) {
  array_t *new = array_new(arr0->length + arr1->length);
  for (int i = 0; i < new->length; ++i) {
    arvalptr_t vptr;
    if (i >= arr0->length) {
      vptr = array_get(arr1, i-arr0->length);
    } else {
      vptr = array_get(arr0, i);
    }
    array_set(new, i, vptr);
  }
  return new;
}
