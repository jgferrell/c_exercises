#include "dlist.h"
#include <stdio.h>

#define trav_down() {				\
    printf("Top down traversal : ");		\
    curnode = list->head;			\
    while (curnode != NULL) {			\
      printf("%i ", get_nodeval(curnode));	\
      curnode = curnode->next;			\
    }						\
    putchar('\n');				\
  }

#define trav_up() {\
    printf("Bottom up traversal: ");		\
    curnode = list->tail;			\
    while (curnode != NULL) {			\
      printf("%i ", get_nodeval(curnode));	\
      curnode = curnode->prev;			\
    }						\
    putchar('\n');				\
  }

#define br(i) {					\
    for(int j = 0; j < i; ++j) {		\
      putchar('\n');				\
    }						\
  }


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
  int storage[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;
  
  printf("Building list from top down with dlist_add_node_after.\n");
  curnode = list->head;
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_add_node_after(list, curnode, &node_values[i]);    
  }
  trav_down();
  trav_up();
  br(1);
  
  printf("Getting node by index: ");
  for (int i = 0; i < list->length; ++i) {
    curnode = dlist_get_node(list, i);
    printf("%i ", get_nodeval(curnode));
  }
  br(2);
  
  printf("Deleting each node from top down with dlist_delete_node.\n");
  printf("List length: ");
  curnode = list->head;
  for (int i = 0; curnode != NULL; ++i) {
    printf("%i ", list->length);
    storage[i] = get_nodeval(list->head);
    dlist_delete_node(list, curnode);
    curnode = list->head;
  }
  printf("%i ", list->length);
  br(1);
  printf("List->head value: ");
  for (int i = 0; i < num_nodes; ++i) {
    printf("%i ", storage[i]);
  }
  if (list->head == NULL) printf("<NULL>");
  br(2);

  printf("Building list from bottom up with dlist_add_node_before.\n");
  curnode = list->tail;
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_add_node_after(list, curnode, &node_values[i]);    
  }
  trav_down();
  trav_up();
  br(1);
  
  printf("Deleting each node from bottom up with dlist_delete_node.\n");
  printf("List length: ");
  curnode = list->tail;
  for (int i = 0; curnode != NULL; ++i) {
    printf("%i ", list->length);
    storage[i] = get_nodeval(list->tail);
    dlist_delete_node(list, curnode);
    curnode = list->tail;
  }
  printf("%i ", list->length);
  br(1);
  printf("List->tail value: ");
  for (int i = 0; i < num_nodes; ++i) {
    printf("%i ", storage[i]);
  }
  if (list->tail == NULL) printf("<NULL>");
  br(2);

  printf("Building list with dlist_insert_node_at_index.\n");
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_insert_node_at_index(list, i, &node_values[i]);
  }
  trav_down();
  trav_up();
  br(1);
  
  printf("Emptying list with dlist_empty.\n");
  dlist_empty(list);
  printf("List length: %i", list->length);
  br(2);
  
  printf("Deleting list.");
  dlist_delete_list(list);
  br(1);
  
  return 0;
}
