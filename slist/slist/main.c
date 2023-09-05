#include "slist.h"
#include <stdio.h>

#define SIZE 10
#define br(i) { for(int j = 0; j < i; ++j) putchar('\n'); }

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

slnode_t * find_value(slist_t *list, int value) {
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

void populate_list(slist_t *list, int values[SIZE]) {
  printf("Populating linked list:\n");
  for (int i = 0; i < SIZE; ++i) {
    slnode_t *node = slist_insert_node(list, list->length, &values[i]);
    printf("%i ", get_node_val(node));
  }
  br(1);
}

void traverse(slist_t *list) {
  printf("Traversing linked list.\n");
  slnode_t *curnode = list->head;
  while (curnode != NULL) {
    printf("%i ", get_node_val(curnode));
    curnode = curnode->next;
  }
  br(1);
}

int main(void) {
  /* Array of arbitrary values. */
  int values[SIZE];
  for (int i = 0; i < SIZE; ++i) values[i] = i;

  /* Create & populate new list. */
  slist_t *list = slist_new_list();
  populate_list(list, values);
  traverse(list);
  br(1);

  /* Show that we can get a node by its index: */
  printf("Getting node by index:\n");
  for (int i = 0; i < list->length; ++i) {
    slnode_t *node = slist_get_node(list, i);
    printf("%i ", get_node_val(node));
  }
  br(2);

  /* DELETING NODES FROM THE LIST BY INDEX */
  
  /* We can delete an arbitrary middle node: */
  printf("Deleting node at index 4.\n");
  printf("Length before delete: %i\n", list->length);
  slist_delete_node_at(list, 4);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete the head node: */
  printf("Deleting head node at index 0:\n");
  printf("Length before delete: %i\n", list->length);
  slist_delete_node_at(list, 0);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete the tail node: */
  printf("Deleting tail node at index %i:\n", list->length-1);
  printf("Length before delete: %i\n", list->length);
  slist_delete_node_at(list, list->length-1);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete all nodes by index: */
  printf("Deleting all remaining nodes by index.\n");
  printf("Length before delete: %i\n", list->length);
  while (list->length > 0) {
    slist_delete_node_at(list, 0);
  }
  printf("Length after delete:  %i\n", list->length);
  br(1);

  printf("Repopulating list.\n");
  populate_list(list, values);
  traverse(list);
  br(1);

  /* DELETING NODES FROM THE LIST BY POINTER */

    /* We can delete an arbitrary middle node: */
  printf("Deleting node 4 steps away from head.\n");
  printf("Length before delete: %i\n", list->length);
  slist_delete_node(list, list->head->next->next->next->next);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete the head node: */
  printf("Deleting head node:\n");
  printf("Length before delete: %i\n", list->length);
  slist_delete_node(list, list->head);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete the tail node: */
  printf("Deleting tail node:\n");
  printf("Length before delete: %i\n", list->length);
  slist_delete_node(list, list->tail);
  printf("Length after delete:  %i\n", list->length);
  traverse(list);
  br(1);

  /* We can delete all nodes: */
  printf("Deleting all remaining nodes.\n");
  printf("Length before delete: %i\n", list->length);
  while (list->length > 0) {
    slist_delete_node(list, list->tail);
  }
  printf("Length after delete:  %i\n", list->length);
  br(1);

  printf("Repopulating list.\n");
  populate_list(list, values);
  traverse(list);
  br(1);

  /* INSERTING NEW NODES INTO AN EXISTING LIST */

  /* first create new pointers to new values */
  int new_nodes = 3;
  int new_nodes_arr[new_nodes];
  /* filling array with arbitrary int values */
  for (int i = 0; i < new_nodes; ++i) new_nodes_arr[i] = SIZE + i;
  
  printf("Insert new head node at index 0:\n");
  printf("Length before insert: %i\n", list->length);
  slist_insert_node(list, 0, &new_nodes_arr[0]);
  printf("Length after insert: %i\n", list->length);
  traverse(list);
  putchar('\n');

  printf("Insert new node at index 4:\n");
  printf("Length before insert: %i\n", list->length);
  slist_insert_node(list, 4, &new_nodes_arr[1]);
  printf("Length after insert: %i\n", list->length);
  traverse(list);
  putchar('\n');

  printf("Insert new tail node at index %i:\n", list->length);
  printf("Length before insert: %i\n", list->length);
  slist_insert_node(list, list->length, &new_nodes_arr[2]);
  printf("Length after insert: %i\n", list->length);
  traverse(list);
  putchar('\n');  

  /* DEMONSTRATION OF IMPLEMENTATION-LEVEL find_value FUNCTION. */
  slnode_t *result;
  int find;

  find = -1;
  printf("FIND ABSENT VALUE (%i):\n", find);
  result = find_value(list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list->head);
  printf("FIND FIRST VALUE (%i):\n", find);
  result = find_value(list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list->tail);
  printf("FIND LAST VALUE (%i):\n", find);
  result = find_value(list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');

  find = get_node_val(list->head->next->next->next->next);
  printf("FIND 5TH VALUE (%i):\n", find);
  result = find_value(list, find);  
  printf("result: %p -> %i\n", result, get_node_val(result));
  putchar('\n');
  
  printf("Emptying list.\n");
  slist_empty(list);
  printf("List length: %i\n", list->length);
  putchar('\n');
  
  printf("Deleting list.");
  slist_delete_list(list);
  putchar('\n');
 
  return 0;
}
