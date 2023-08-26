#include "slist.h"
#include <stdio.h>

/******************************************************
 * HOW TO PROPERLY RETRIEVE VALUE FROM A VALUE-POINTER:
 *   (implementation-level logic)
 */
int get_node_val(slnode_t *node) {
  if (node == NULL) return -1;
  
  /* The next line is not strictly required; it's here solely for
     clarity; `slnode_t *node->value_ptr` is type slnode_valptr_t
     (i.e., a void pointer; cannot be directly dereferenced). */
  slnode_valptr_t value_ptr = node->value_ptr;
  
  /* First we cast the void pointer. What we cast to depends on the
     actual values we used for building the linked list. In this
     implementation, we're creating a list of int values, so we cast
     to an int pointer here: */
  int *p = value_ptr;
  
  /* Then we can dereference the int pointer to an int: */
  int i = *p;
  
  /* And we're done. */
  return i;
}


/* Example of a search function. This is implementation-level
   because it's not agnostic with regards to the type of value to
   which value-pointers point.

   find_value: Returns a pointer to first node whose value-pointer
   points to an int equal to the provided value. If no such node
   exists, returns NULL. */

slnode_t * find_value(slist_t* list, int value) {
  // return head node if it matches
  if (get_node_val(list->head) == value) {
    return list->head;
  } 

  // otherwise proceed until next node matches
  slnode_t *curnode = list->head;
  for (int i = 1; i < list->length; ++i) {
    if (get_node_val(curnode->next) == value) break;
    curnode = curnode->next;
  }
  return curnode->next;
}



int main(void) {
  int num_nodes = 10;

  /* We're building a linked list of integer values: */
  int node_values[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;
  slist_t list = slist_build(num_nodes, node_values, sizeof(int));

  /* Print the current state of the linked list: */
  printf("LIST INFO:\n");
  printf("ptr to head node:         %p\n",  list.head);
  printf("ptr to tail node:         %p\n",  list.tail);
  printf("list length:              %i\n", list.length);
  putchar('\n');

  /* TRAVERSING LIST AND ACCESSING SPECIFIC NODES */

  /* Traverse the linked list and print pointers and values: */
  printf("LINKED LIST TRAVERSAL:\n");
  slnode_t *curnode = list.head;
  while (curnode != NULL) {
    printf("%p->value = %i\n", curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');

  /* Show that we can get a node by its index: */
  printf("GET NODE BY INDEX:\n");
  for (int i = 0; i < list.length; ++i) {
    slnode_t *node = slist_get_node(&list, i);
    printf("[%i] %p->value = %i\n", i, node, get_node_val(node));
  }
  putchar('\n');

  /* DELETING NODES FROM THE LIST */
  
  /* We can delete an arbitrary node: */
  printf("DELETE NODE [4]:\n");
  slist_delete_node(&list, 4);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = ", i, curnode);
    printf("%i\n", get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');

  /* We can delete the head node: */
  printf("DELETE HEAD NODE:\n");
  slist_delete_node(&list, 0);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');

  /* We can delete the tail node: */
  printf("DELETE LAST NODE [%i]:\n", list.length - 1);
  slist_delete_node(&list, list.length - 1);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');


  /* INSERTING NEW NODES INTO AN EXISTING LIST */

  /* first create new pointers to new values */
  int new_nodes = 3;
  int new_nodes_arr[new_nodes];
  /* filling array with arbitrary int values */
  for (int i = 0; i < new_nodes; ++i) new_nodes_arr[i] = num_nodes + i;
  /* create a slnode_valptr_t to deliver the value-pointer */
  slnode_valptr_t valptr;
  
  printf("INSERT NEW HEAD NODE:\n");
  valptr = &new_nodes_arr[0];
  slist_insert_node(&list, 0, valptr);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');

  printf("INSERT NEW HEAD NODE [4]:\n");
  valptr = &new_nodes_arr[1];
  slist_insert_node(&list, 4, valptr);
    printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');

  printf("INSERT NEW TAIL NODE [%i]:\n", list.length);
  valptr = &new_nodes_arr[2];
  slist_insert_node(&list, list.length, valptr);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, get_node_val(curnode));
    curnode = curnode->next;
  }
  putchar('\n');


  /* DEMONSTRATION OF IMPLEMENTATION-LEVEL find_value FUNCTION. */
  slnode_t *result;
  int find;

  find = -1;
  printf("FIND ABSENT VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list.head);
  printf("FIND FIRST VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list.tail);
  printf("FIND LAST VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list.head->next->next->next->next);
  printf("FIND 5TH VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');
  
  printf("EMPTYING LIST:\n");
  slist_empty(&list);
  printf("LIST INFO:\n");
  printf("ptr to head node:         %p\n",  list.head);
  printf("ptr to tail node:         %p\n",  list.tail);
  printf("list length:              %i\n", list.length);

  return 0;
}
