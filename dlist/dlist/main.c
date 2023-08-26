#include "dlist.h"
#include <stdio.h>

int main(void) {
  int num_nodes = 10;

  /* We're building a linked list of integer values: */
  int node_values[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;

  
  dlist_t *list = dlist_new_list();
  dlnode_t *curnode = list->head;
  for (int i = 0; i < num_nodes; ++i) {
    curnode = dlist_add_node_after(list, curnode, &node_values[i]);    
  }

  /* Print the current state of the linked list: */
  printf("LIST INFO:\n");
  printf("ptr to head node:         %p\n",  list->head);
  printf("ptr to tail node:         %p\n",  list->tail);
  printf("list length:              %i\n", list->length);
  putchar('\n');

  dlist_delete_list(list);
  
  return 0;
}
