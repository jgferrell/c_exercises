// array.h

#ifndef ARRAY_H_
#define ARRAY_H_

/*
** DATA STRUCTURES & TYPES
*/

/* arvalptr_t: a pointer to a value */
typedef void * arvalptr_t;

/* array_t: an array; `length` records the capacity of the array,
   `start` points to the beginning of array memory. */
typedef struct {
  int length;
  arvalptr_t *start;
} array_t;

/*
** INITIALIZATION OPERATIONS
*/

/* Returns a pointer to a properly initialized singly-linked list. */
array_t * array_new(int length);

/*
** NODE OPERATIONS
*/

/* Returns the value-pointer of the specified array node. */
arvalptr_t array_get(const array_t *arr, int node_index);

/* Sets the value-pointer of the specified array node. */
void array_set(array_t *arr, int node_index, arvalptr_t value_ptr);

/*
** ARRAY OPERATIONS
*/

/* Deletes an array. */
void array_delete(array_t *arr);
/* Increases the capacity of the array by specified amount. */
void array_expand(array_t *arr, int increase_by);
/* Combines the two provided arrays by appending the second array to
   the end of the first. Returns a pointer to the resulting array. */
array_t * array_combine(const array_t *arr0, const array_t *arr1);

#endif /* ARRAY_H_ */
