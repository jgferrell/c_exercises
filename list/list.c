#include <stdlib.h>
#include <stdio.h>

// C programming & data structure exercise:
//  implementation of a singly-linked list 

/* slnode: the node of a singly-linked list; has a value (int) and a pointer
   to the next node in the list */
struct slnode {
  int value;
  struct slnode* next;
};
typedef struct slnode slnode;

/* linked_list: a singly-linked list; keeps track of how many nodes
   are in the list and points to the first node in the list */
typedef struct {
  int length;
  slnode* head;
} linked_list;

linked_list build_list(int num_nodes, int* node_values) {
  /* Builds a singly-linked list from an array of node values. */

  // initialize linked list to return
  linked_list list = list;
  list.length = num_nodes;
  list.head = NULL;

  // build linked list
  slnode *prev, *head;
  for (int i = 0; i < num_nodes; ++i) {
    
    // create new node
    slnode *node = malloc(sizeof(slnode));
    node->value = node_values[i];
    node->next = NULL;

    // connect new node to previous node
    if (i > 0) {
      prev->next = node;
    } else {
      list.head = node;
    }
    
    // prepare `prev` for next new node
    prev = node;
  }

  return list;
}

slnode* get_list_node(linked_list* list, int node_index) {
  /* Returns pointer to the node requested by index (index is the
     number of nodes between target node and head node). */
  
  slnode* curnode = list->head;  
  for (int i = 0; i < node_index; ++i) {
    if (i == node_index) break;
    curnode = curnode->next;
  }
  
  return curnode;
}

slnode* find_value(linked_list* list, int value) {
  /* Returns pointer to first node with specified value. If value is
     not found, returns NULL. */

  // return head node if it matches
  if (list->head->value == value) {
    return list->head;
  }

  // otherwise proceed until next node matches
  slnode* curnode = list->head;
  for (int i = 1; i < list->length; ++i) {
    if (curnode->next->value == value) break;
    curnode = curnode->next;
  }
  return curnode->next;
}

void insert_list_node(linked_list *list, int node_index, int value) {
  /* Insert a new node at specified index with specified value. */
  
  // create new node & allocate memory
  slnode *node = malloc(sizeof(slnode));
  node->value = value;
  node->next = NULL;

  // add new node at specified index
  slnode *curnode;
  if (node_index == 0) {
    node->next = list->head;
    list->head = node;
  } else {
    curnode = list->head;
    for (int i = 1; i < node_index; ++i) {
      curnode = curnode->next;
    }
    node->next = curnode->next;
    curnode->next = node;
  }
  list->length = list->length + 1;
}

void delete_list_node(linked_list *list, int node_index) {
  /* Delete the list node at specified index. */
  slnode *prev, *target;

  // remove target node from list
  if (node_index == 0) {
    target = list->head;
    list->head = target->next;
  } else {
    target = list->head;
    for (int i = 0; i < node_index; ++i) {
      prev = target;
      target = target->next;
    }
    prev->next = target->next;
  }

  // free target node memory
  free(target);

  // update list length
  list->length = list->length - 1;
}

void empty_list(linked_list* list) {
  /* Deletes all nodes from list and frees memory. */
  
  // build an array of pointers to list nodes
  slnode* arr[list->length];
  slnode* curnode = list->head;
  for (int i = 0; i < list->length; ++i) {
    arr[i] = curnode;
    curnode = curnode->next;
  }

  // free memory that was used by nodes
  for (int i = 0; i < list->length; ++i) free(arr[i]);

  // update list
  list->length = 0;
  list->head = NULL;
}

void main(void) {
  int num_nodes = 10;
  int node_values[num_nodes];
  for (int i = 0; i < num_nodes; ++i) node_values[i] = i;

  linked_list list = build_list(num_nodes, node_values);
  
  printf("ptr to node:         %p\n",  list.head);
  printf("node.value:          %i\n",  list.head->value);  
  printf("list.len:  %i\n", list.length);
  putchar('\n');
  
  printf("LINKED LIST TRAVERSAL:\n");
  slnode* curnode = list.head;
  while (curnode != NULL) {
    printf("%p->value = %i\n", curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');

  printf("GET NODE BY INDEX:\n");
  for (int i = 0; i < list.length; ++i) {
    slnode* node = get_list_node(&list, i);
    printf("[%i] %p->value = %i\n", i, node, node->value);
  }
  putchar('\n');

  printf("DELETE NODE [4]:\n");
  delete_list_node(&list, 4);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');
  
  printf("DELETE HEAD NODE:\n");
  delete_list_node(&list, 0);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');
  
  printf("DELETE LAST NODE [%i]:\n", list.length - 1);
  delete_list_node(&list, list.length - 1);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');

  printf("INSERT NEW HEAD NODE:\n");
  insert_list_node(&list, 0, 9);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');

  printf("INSERT NEW HEAD NODE [4]:\n");
  insert_list_node(&list, 4, 4);
    printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');

  printf("INSERT NEW TAIL NODE [%i]:\n", list.length);
  insert_list_node(&list, list.length, 0);
  printf("list.len:  %i\n", list.length);
  curnode = list.head;
  for (int i = 0; i < list.length; ++i) {
    printf("[%i] %p->value = %i\n", i, curnode, curnode->value);
    curnode = curnode->next;
  }
  putchar('\n');

  slnode *result;
  int find;

  find = 1123;
  printf("FIND ABSENT VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p\n", result);
  putchar('\n');

  find = 9;
  printf("FIND FIRST VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p\n", result);
  putchar('\n');

  find = 0;
  printf("FIND LAST VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p\n", result);
  putchar('\n');

  find = 4;
  printf("FIND 5TH VALUE (%i):\n", find);
  result = find_value(&list, find);  
  printf("result: %p\n", result);
  putchar('\n');
  
  printf("EMPTYING LIST:\n");
  empty_list(&list);
  printf("n = %i\n", list.length);
  printf("head = %p\n", list.head);
}
