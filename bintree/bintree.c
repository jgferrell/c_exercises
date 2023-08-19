#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

bintree_t * bintree_build_complete(int num_nodes, bintree_val_t value_ptrs, size_t value_size) {
  bintree_t *tree[num_nodes], *curnode_ptr;
  
  for (int i = 0; i < num_nodes; ++i) {
    /* create a new node */
    curnode_ptr = malloc(sizeof(bintree_t));
    curnode_ptr->value_ptr = value_ptrs + i * value_size;
    curnode_ptr->left = NULL;
    curnode_ptr->right = NULL;

    /* save ptr to array so it can later connect with children (if it
       ends up with any) */
    tree[i] = curnode_ptr;

    /* if we're at the root, we're done */
    if (i == 0) continue;
    
    /* connect current node to its parent */
    int parent = i/2 - 1 + i%2;
    if (i % 2) {
      tree[parent]->left = curnode_ptr;
    } else {
      tree[parent]->right = curnode_ptr;
    }
  }

  return tree[0];
}

void bintree_length_helper(bintree_t *node, int *n){
  /* postorder traversal */
  if (node->left != NULL) bintree_length_helper(node->left, n);
  if (node->right != NULL) bintree_length_helper(node->right, n);
  *n = *n + 1;
}

int bintree_length(bintree_t *root) {
  int length = 0;
  bintree_length_helper(root, &length);
  return length;
}

bintree_t * bintree_inorder(bintree_t *root, bintree_node_fn node_action) {
  bintree_t curnode = *root;
  
  /* first do left subtree */
  if (curnode.left != NULL) bintree_inorder(curnode.left, node_action);
  
  /* then act on current node */
  node_action(&curnode);

  /* finally visit right subtree */
  if (curnode.right != NULL) bintree_inorder(curnode.right, node_action);
}

bintree_t * bintree_preorder(bintree_t *root, bintree_node_fn node_action) {
  bintree_t curnode = *root;
  
  /* act on current node */
  node_action(&curnode);

  /* then do left subtree */
  if (curnode.left != NULL) bintree_preorder(curnode.left, node_action);
  /* finally do right subtree */
  if (curnode.right != NULL) bintree_preorder(curnode.right, node_action);
}

bintree_t * bintree_postorder(bintree_t *root, bintree_node_fn node_action) {
  bintree_t curnode = *root;
  
  /* proceed with postorder; first do left subtree, then right */
  if (curnode.left != NULL)
    bintree_postorder(curnode.left, node_action);
  if (curnode.right != NULL)
    bintree_postorder(curnode.right, node_action);

  /* finally act on current node */
  node_action(&curnode);
}

void bintree_free(bintree_t *root) {
  /* proceed with postorder; first do left subtree, then right */
  if (root->left != NULL) bintree_free(root->left);
  if (root->right != NULL) bintree_free(root->right);
  
  /* finally treat current node */
  free(root);
}

