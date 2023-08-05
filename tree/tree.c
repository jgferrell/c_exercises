#include <stdio.h>

struct binary_tree {
  int value;
  struct binary_tree* left;
  struct binary_tree* right;
};

void initialize_binary_tree(struct binary_tree* tree, int num_nodes) {
  for (int i = 0; i < num_nodes; ++i) {
    tree[i].value = -1;
    tree[i].left = NULL;
    tree[i].right = NULL;
  }
}

void complete_binary_tree(struct binary_tree* tree, int num_nodes, int* node_values) {
  /* Populates a complete binary tree from provided node
     values. Assembles the tree in a breadth-first manner. */  
  tree[0].value = node_values[0];
  
  for (int curnode = 1; curnode < num_nodes; ++curnode) {
    // set value of current node
    tree[curnode].value = node_values[curnode];
    
    // connect current node to its parent
    int parent = curnode/2 - 1 + curnode%2;
    if (curnode % 2) {
      tree[parent].left = &tree[curnode];
    } else {
      tree[parent].right = &tree[curnode];
    }
  }
}

void binary_inorder(struct binary_tree* tree, int* inorder, int* visited) {
  /* Populates `inorder` array with binary tree values in inorder form. */ 
  struct binary_tree curnode = *tree;

  // proceed with inorder; first do left subtree
  if (curnode.left != NULL)
    binary_inorder(curnode.left, inorder, visited);

  // add current node value to inorder array
  inorder[*visited] = curnode.value;
  *visited = *visited + 1;

  // visit right subtree
  if (curnode.right != NULL)
    binary_inorder(curnode.right, inorder, visited);
}

void binary_preorder(struct binary_tree* tree, int* preorder, int* visited) {
  /* Populates `preorder` array with binary tree values in preorder form. */
  struct binary_tree curnode = *tree;
  
  // add current node value to preorder array
  preorder[*visited] = curnode.value;
  *visited = *visited + 1;

  // proceed with preorder; first do left subtree, then right
  if (curnode.left != NULL)
    binary_preorder(curnode.left, preorder, visited);
  if (curnode.right != NULL)
    binary_preorder(curnode.right, preorder, visited);
}

void binary_postorder(struct binary_tree* tree, int* postorder, int* visited) {
  /* Populates `postorder` array with binary tree values in postorder form. */
  struct binary_tree curnode = *tree;
  
  // proceed with postorder; first do left subtree, then right
  if (curnode.left != NULL)
    binary_postorder(curnode.left, postorder, visited);
  if (curnode.right != NULL)
    binary_postorder(curnode.right, postorder, visited);

  // add current node value to postorder array
  postorder[*visited] = curnode.value;
  *visited = *visited + 1;
}


int main() { 
  int num_nodes = 10;
  int nodevals[num_nodes];
  struct binary_tree tree[num_nodes];
  initialize_binary_tree(tree, num_nodes);
  
  // populate node value array
  for (int i = 0; i < num_nodes; ++i) nodevals[i] = i;
  printf("\n%s\n", "NODE VALUES:");
  for (int i = 0; i < num_nodes; ++i) printf("%i ", nodevals[i]);
  putchar('\n');

  // test ipow function
  // for (int i = 0; i < 5; ++i) printf("2^%i = %i\n", i, ipow(2, i));

  complete_binary_tree(tree, num_nodes, nodevals);
  printf("\n%s\n", "COMPLETE BINARY TREE:");
  for (int i = 0; i < num_nodes; ++i)
    printf("%p: {value: %i; left: %p; right: %p}\n",
	   &tree[i], tree[i].value, tree[i].left, tree[i].right
	   );

  int i;
  
  // DEMONSTRATE INORDER
  int inorder[num_nodes];
  i = 0;
  binary_inorder(tree, inorder, &i);
  
  printf("\n%s\n", "INORDER:");  
  for (int i = 0; i < num_nodes; ++i) printf("%i ", inorder[i]);
  putchar('\n');  

  // DEMONSTRATE PREORDER
  int preorder[num_nodes];
  i = 0;
  binary_preorder(tree, preorder, &i);
  
  printf("\n%s\n", "PREORDER:");  
  for (int i = 0; i < num_nodes; ++i) printf("%i ", preorder[i]);
  putchar('\n');

  // DEMONSTRATE POSTORDER
  int postorder[num_nodes];
  i = 0;
  binary_postorder(tree, postorder, &i);
  
  printf("\n%s\n", "POSTORDER:");  
  for (int i = 0; i < num_nodes; ++i) printf("%i ", postorder[i]);
  putchar('\n');  
  
  return 0;
};
