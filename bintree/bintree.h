// tree.h

#ifndef BINTREE_H_
#define BINTREE_H_

typedef void * bintree_val_t;
/* Value of binary tree node. */

struct bintree_t {
  bintree_val_t *value;
  struct bintree_t *left;
  struct bintree_t *right;
};
typedef struct bintree_t bintree_t;
/* Binary tree structure. */


bintree_t * bintree_build_complete(bintree_val_t *node_values, int num_nodes);
/* Populates a complete binary tree from provided node
   values. Assembles the tree in a breadth-first manner. Returns a
   pointer to the tree's root node. */

void bintree_inorder(bintree_t *tree, bintree_val_t *inorder, int *visited);
/* Populates `inorder` array with binary tree values in inorder form. */

void bintree_preorder(bintree_t *tree, bintree_val_t *preorder, int *visited);
/* Populates `preorder` array with binary tree values in preorder form. */

void bintree_postorder(bintree_t *tree, bintree_val_t *postorder, int *visited);
/* Populates `postorder` array with binary tree values in postorder form. */

void bintree_delete(bintree_t *tree);
/* Frees memory previously allocated to the tree. */

#endif
