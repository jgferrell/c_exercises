#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

/* Testing script for dlist. */

#define br(i) for(int j = 0; j < i; ++j) putchar('\n');

/* 
** AUXILLARY FUNCTION DECLARATIONS 
*/

/* Traverse list down from head and then up from tail, printing a
   report each way. */
void trav(dlist_t *list);

/* Traverse down from head and print report. */
void trav_down(dlist_t *list);

/* Traverse up from tail and print report. */
void trav_up(dlist_t *list);

/* Empty list and print report. */
void empty(dlist_t *list);

/* Dereference a node's value-pointer to an int value. */
int get_nodeval(dlnode_t *node);

/*
** AUXILLARY FUNCTION DEFINITIONS
*/

void trav(dlist_t *list) {
  trav_down(list);
  trav_up(list);
  br(1);
}

void trav_down(dlist_t *list) {
  dlnode_t *curnode;
  
  printf("Top down traversal : ");
  curnode = list->dummy->next;
  while (curnode != list->dummy) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->next;
  }
  br(1);
}

void trav_up(dlist_t *list) {
  dlnode_t *curnode;

  printf("Bottom up traversal: ");
  curnode = list->dummy->prev;
  while (curnode != list->dummy) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->prev;
  }
  br(1);
}

int get_nodeval(dlnode_t *node) {
  int *p = node->value_ptr;
  int i = *p;
  return i;
}

void empty(dlist_t *list) {
  printf("Emptying list with dlist_empty.\n");
  dlist_empty(list);
  printf("List length: %i", list->length);
  br(2);
}

/*
** MAIN TESTING FUNCTION
*/

int main(void) {
  /* Create list and array of arbitrary values. */
  dlist_t *list = dlist_new_list();

  int num_nodes = 10;
  int node_values[num_nodes];
  int storage[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;
  
  printf("Building list with dlist_add.\n");
  for (int i = 0; i < num_nodes; ++i) {
    dlist_add(list, i, &node_values[i]);    
  }
  trav(list);
  
  printf("Getting node by index: ");
  for (int i = 0; i < list->length; ++i) {
    printf("%i ", get_nodeval(dlist_get_node(list, i)));
  }
  br(2);
  
  printf("Deleting each node from top down with dlist_delete_node.\n");
  printf("List length: ");
  for (int i; list->length > 0; ++i) {
    printf("%i ", list->length);
    storage[i] = get_nodeval(list->dummy->next);
    dlist_delete_node(list, list->dummy->next);
  }
  printf("%i ", list->length);
  br(1);
  printf("List head value: ");
  for (int i = 0; i < num_nodes; ++i) {
    printf("%i ", storage[i]);
  }
  if (list->dummy->next == list->dummy) printf("<NULL>");
  br(2);

  printf("Building list with dlist_add.\n");
  for (int i = 0; i < num_nodes; ++i) {
    dlist_add(list, i, &node_values[i]);    
  }
  trav(list);
  
  printf("Deleting each node from bottom up with dlist_delete_node.\n");
  printf("List length: ");
  for (int i; list->length > 0; ++i) {
    printf("%i ", list->length);
    storage[i] = get_nodeval(list->dummy->prev);
    dlist_delete_node(list, list->dummy->prev);
  }
  printf("%i ", list->length);
  br(1);
  printf("List tail value: ");
  for (int i = 0; i < num_nodes; ++i) {
    printf("%i ", storage[i]);
  }
  if (list->dummy->prev == list->dummy) printf("<NULL>");
  br(2);

  printf("Building list with dlist_add.\n");
  for (int i = 0; i < num_nodes; ++i) {
    dlist_add(list, i, &node_values[i]);    
  }
  trav(list);
  
  printf("Adding nodes at arbitrary locations with dlist_add.\n");
  int arr0[num_nodes];
  for (int i = 0; i < num_nodes; ++i) arr0[i] = node_values[i] + num_nodes;
  printf("Inserting (i, v): ");
  for (int i = 0; i < num_nodes; ++i) {
    int j = rand() % (list->length + 1);
    printf("(%i, %i) ", j, arr0[i]);
    dlist_add(list, j, &arr0[i]);
  }
  br(1);
  trav(list);

  printf("Deleting nodes at arbitrary locations with dlist_delete_node_at.\n");
  printf("Deleting (i, v): ");
  for (int i = 0; i < num_nodes; ++i) {
    int j = rand() % (list->length + 1);
    dlnode_t *n = dlist_get_node(list, j);
    printf("(%i, %i) ", j, get_nodeval(n));
    dlist_delete_node_at(list, j);
  }
  br(1);
  trav(list);

  printf("Changing node values with dlist_get_val_at and dlist_set_val_at.\n");
  printf("New values: ");
  int arr1[list->length];
  for (int i = 0; i < list->length; ++i) {
    int *p = dlist_get_val_at(list, i);
    int j = *p;
    arr1[i] = j * -1;
    dlist_set_val_at(list, i, &arr1[i]);
  }
  br(1);
  trav(list);

  printf("Deleting list.");
  dlist_delete_list(list);
  br(1);
  
  return 0;
}
