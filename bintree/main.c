#include "bintree.h"
#include <stdio.h>

# define bt_test_report(fn, name, exp, obs) {				\
    i = 0;								\
    fn(tree, obs, &i);							\
    printf("\n---------------------------\n");				\
    printf("%s:", name);						\
    printf("\n---------------------------\n");				\
    printf("expctd: %s\nobsrvd: ", exp);				\
    for (int i = 0; i < num_nodes; ++i) printf("%i ", obs[i]);		\
    putchar('\n');							\
}

int main() {

  // prepare an array of tree node-values
  int num_nodes = 10;
  bintree_val_t nodevals[num_nodes];
  
  // populate node-value array
  printf("\n%s\n", "NODE VALUES:");
  for (int i = 0; i < num_nodes; ++i) nodevals[i] = i;  
  for (int i = 0; i < num_nodes; ++i) printf("%i ", nodevals[i]);
  putchar('\n');

  // get a tree
  bintree_t *tree = bintree_build_complete(nodevals, num_nodes);

  // TRAVERSAL DEMONSTRATIONS
  int i;
  
  // DEMONSTRATE INORDER: 7 3 8 1 9 4 0 5 2 6 
  int inorder[num_nodes];
  bt_test_report(bintree_inorder, "INORDER", "7 3 8 1 9 4 0 5 2 6", inorder);

  // DEMONSTRATE PREORDER: 0 1 3 7 8 4 9 2 5 6
  int preorder[num_nodes];
  bt_test_report(bintree_preorder, "PREORDER", "0 1 3 7 8 4 9 2 5 6", preorder);

  // DEMONSTRATE POSTORDER: 7 8 3 9 4 1 5 6 2 0
  int postorder[num_nodes];
  bt_test_report(bintree_postorder, "POSTORDER", "7 8 3 9 4 1 5 6 2 0", postorder);

  bintree_delete(tree);  
  return 0;
};
