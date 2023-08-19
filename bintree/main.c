#include "bintree.h"
#include <stdio.h>

void print_node(bintree_t *node) {
  int *p = node->value_ptr;
  printf("%i ", *p);
}

/* convenience type for passing function pointers to bt_test_report */
typedef bintree_t* node_fn(bintree_t *, bintree_node_fn);

void bt_test_report(node_fn fn, bintree_t *root, char *name, char *exp) {
  printf("\n---------------------------\n");
  printf("%s:", name);
  printf("\n---------------------------\n");
  printf("expctd: %s\nobsrvd: ", exp);
  fn(root,  &print_node);  
  putchar('\n');
}

int main() {

  /* prepare an array of tree node-values */
  int num_nodes = 10;
  int nodeval_int[num_nodes];
  
  /* populate node-value array */
  printf("\n%s\n", "NODE VALUES:");
  for (int i = 0; i < num_nodes; ++i) nodeval_int[i] = i;
  for (int i = 0; i < num_nodes; ++i) printf("%i ", nodeval_int[i]);
  putchar('\n');

  /* get a tree */
  bintree_t *tree = bintree_build_complete(num_nodes, nodeval_int, sizeof(int));

  int len = bintree_length(tree);
  printf("\nTree length: %i\n", len);

  /* TRAVERSAL DEMONSTRATIONS WITH FUNCTION PASSING */
 
  /* DEMONSTRATE INORDER: 7 3 8 1 9 4 0 5 2 6 */
  bt_test_report(&bintree_inorder, tree, "INORDER", "7 3 8 1 9 4 0 5 2 6");

  
  /* DEMONSTRATE PREORDER: 0 1 3 7 8 4 9 2 5 6 */
  bt_test_report(&bintree_preorder, tree, "PREORDER", "0 1 3 7 8 4 9 2 5 6");

  /* DEMONSTRATE POSTORDER: 7 8 3 9 4 1 5 6 2 0 */
  int postorder[num_nodes];
  bt_test_report(bintree_postorder, tree, "POSTORDER", "7 8 3 9 4 1 5 6 2 0");

  /* free memory */
  bintree_free(tree);  
  return 0;
};
