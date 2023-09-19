#include "array.h"
#include <stdio.h>

#define SIZE 10

int val2i(arvalptr_t vp) {
  int *p = vp;
  return *p;
}

void parr(array_t *arr, int i) {
  int j = val2i(array_get(arr, i));
  printf("arr[%02d]: %i\n", i, j);
}

int main(void) {
  int a=10, b=11, c=12, d=13, e=14, f=15, g=16, h=17, i=18, j=19;

  printf("Creating an array:\n");
  array_t *arr = array_new(SIZE);  
  array_set(arr, 0, (arvalptr_t) &a);
  array_set(arr, 1, (arvalptr_t) &b);
  array_set(arr, 2, (arvalptr_t) &c);
  array_set(arr, 3, (arvalptr_t) &d);
  array_set(arr, 4, (arvalptr_t) &e);
  array_set(arr, 5, (arvalptr_t) &f);
  array_set(arr, 6, (arvalptr_t) &g);
  array_set(arr, 7, (arvalptr_t) &h);
  array_set(arr, 8, (arvalptr_t) &i);
  array_set(arr, 9, (arvalptr_t) &j);
  for (int i = 0; i < arr->length; ++i) parr(arr, i);

  int k=20, l=21, m=22, n=23, o=24, p=25, q=26, r=27, s=28, t=29;
  printf("\nExpanding array:\n");
  array_expand(arr, 10);
  array_set(arr, 10, &k);
  array_set(arr, 11, &l);
  array_set(arr, 12, &m);
  array_set(arr, 13, &n);
  array_set(arr, 14, &o);
  array_set(arr, 15, &p);
  array_set(arr, 16, &q);
  array_set(arr, 17, &r);
  array_set(arr, 18, &s);
  array_set(arr, 19, &t);  
  for (int i = 0; i < arr->length; ++i) parr(arr, i);

  printf("\nDeleting array.");  
  array_delete(arr);
  printf("\n\n");

  printf("Creating two new arrays.\n");
  array_t *arr0 = array_new(SIZE);  
  array_set(arr0, 0, (arvalptr_t) &a);
  array_set(arr0, 1, (arvalptr_t) &b);
  array_set(arr0, 2, (arvalptr_t) &c);
  array_set(arr0, 3, (arvalptr_t) &d);
  array_set(arr0, 4, (arvalptr_t) &e);
  array_set(arr0, 5, (arvalptr_t) &f);
  array_set(arr0, 6, (arvalptr_t) &g);
  array_set(arr0, 7, (arvalptr_t) &h);
  array_set(arr0, 8, (arvalptr_t) &i);
  array_set(arr0, 9, (arvalptr_t) &j);

  array_t *arr1 = array_new(SIZE);  
  array_set(arr1, 0, &k);
  array_set(arr1, 1, &l);
  array_set(arr1, 2, &m);
  array_set(arr1, 3, &n);
  array_set(arr1, 4, &o);
  array_set(arr1, 5, &p);
  array_set(arr1, 6, &q);
  array_set(arr1, 7, &r);
  array_set(arr1, 8, &s);
  array_set(arr1, 9, &t);

  printf("Combining arrays:\n");
  array_t *arr2 = array_combine(arr0, arr1);
  for (int i = 0; i < arr2->length; ++i) parr(arr2, i);
  
  printf("Deleting arrays.\n");
  array_delete(arr0);
  array_delete(arr1);
  array_delete(arr2);
  
  return 0;
}
