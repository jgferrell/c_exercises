#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

# define bt_init_node(bt, val) {		\
    bt->value = val;				\
    bt->left = NULL;				\
    bt->right = NULL;				\
  }

bintree_t * bintree_build_complete(bintree_val_t *node_values, int num_nodes) {
  bintree_t *tree[num_nodes], *curnode;
     
  for (int i = 0; i < num_nodes; ++i) {
    // create a new node
    curnode = malloc(sizeof(bintree_t));
    bt_init_node(curnode, node_values + i);
    tree[i] = curnode;

    // if we're at the root, we're done
    if (i == 0) continue;
    
    // connect current node to its parent
    int parent = i/2 - 1 + i%2;
    if (i % 2) {
      tree[parent]->left = curnode;
    } else {
      tree[parent]->right = curnode;
    }
  }

  return tree[0];
}

void bintree_inorder(bintree_t *tree, bintree_val_t *inorder, int *visited) {
  /* Populates `inorder` array with binary tree values in inorder form. */ 
  bintree_t curnode = *tree;

  // first do left subtree
  if (curnode.left != NULL) bintree_inorder(curnode.left, inorder, visited);

  // then add current node value to inorder array
  inorder[*visited] = *curnode.value; // <-- this is where we actually treat each node
  *visited = *visited + 1;

  // finally visit right subtree
  if (curnode.right != NULL) bintree_inorder(curnode.right, inorder, visited);
}

void bintree_preorder(bintree_t *tree, bintree_val_t *preorder, int *visited) {
  /* Populates `preorder` array with binary tree values in preorder form. */
  bintree_t curnode = *tree;
  
  // add current node value to preorder array
  preorder[*visited] = *curnode.value; // <-- this is where we actually treat each node
  *visited = *visited + 1;

  // then do left subtree
  if (curnode.left != NULL) bintree_preorder(curnode.left, preorder, visited);
  // finally do right subtree
  if (curnode.right != NULL) bintree_preorder(curnode.right, preorder, visited);
}

void bintree_postorder(bintree_t *tree, bintree_val_t *postorder, int *visited) {
  /* Populates `postorder` array with binary tree values in postorder form. */
  bintree_t curnode = *tree;
  
  // proceed with postorder; first do left subtree, then right
  if (curnode.left != NULL)
    bintree_postorder(curnode.left, postorder, visited);
  if (curnode.right != NULL)
    bintree_postorder(curnode.right, postorder, visited);

  // finally add current node value to postorder array
  postorder[*visited] = *curnode.value; // <-- this is where we actually treat each node
  *visited = *visited + 1;
}

void bintree_delete(bintree_t *tree) {
  // proceed with postorder; first do left subtree, then right
  if (tree->left != NULL) bintree_delete(tree->left);
  if (tree->right != NULL) bintree_delete(tree->right);
  
  // finally treat current node
  free(tree);
}

