#include "dlist.h"
#include <stdio.h>

/* Dereference a node's value-pointer to an int value. */
int get_nodeval(dlnode_t *node) {
  int *p = node->value_ptr;
  int i = *p;
  return i;
}

int main(void) {
  /* Create list and array of arbitrary values. */
  dlist_t *list = dlist_new_list();
  dlnode_t *curnode; // for traversals
  
  int num_nodes = 10;
  int node_values[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;
  
  printf("Building list from top down with dlist_add_node_after.\n");
  curnode = list->head;
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_add_node_after(list, curnode, &node_values[i]);    
  }

  printf("Top down traversal : ");
  curnode = list->head;
  while (curnode != NULL) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->next;
  }
  putchar('\n');
  printf("Bottom up traversal: ");
  curnode = list->tail;
  while (curnode != NULL) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->prev;
  }
  putchar('\n');

  printf("Deleting all nodes from top down.\n");
  printf("List length: ");
  curnode = list->head;
  while (curnode != NULL) {
    printf("%i ", list->length);
    dlist_delete_node(list, curnode);
    curnode = list->head;
  }
  printf("%i ", list->length);
  putchar('\n');

  printf("Building list from bottom up with dlist_add_node_before.\n");
  curnode = list->tail;
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_add_node_after(list, curnode, &node_values[i]);    
  }

  printf("Top down traversal : ");
  curnode = list->head;
  while (curnode != NULL) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->next;
  }
  putchar('\n');
  printf("Bottom up traversal: ");
  curnode = list->tail;
  while (curnode != NULL) {
    printf("%i ", get_nodeval(curnode));
    curnode = curnode->prev;
  }
  putchar('\n');

  printf("Deleting all nodes from bottom up.\n");
  printf("List length: ");
  curnode = list->tail;
  while (curnode != NULL) {
    printf("%i ", list->length);
    dlist_delete_node(list, curnode);
    curnode = list->tail;
  }
  printf("%i ", list->length);
  putchar('\n');

  
  
  dlist_delete_list(list);
  
  return 0;
}
