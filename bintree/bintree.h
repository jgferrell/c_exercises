// tree.h

#ifndef BINTREE_H_
#define BINTREE_H_

#include <stddef.h>

/* Value of binary tree node. Use void pointer so that we can create a
   stack of generic pointers. */
typedef void * bintree_val_t;

/* Binary tree structure. Each tree node contains a "value-pointer" (a
   pointer to some arbitrary value) and possible pointers to a left
   child node and a right child node. Left and right can be a pointer
   to another bintree_t or NULL. */
struct bintree_t {
  bintree_val_t value_ptr;
  struct bintree_t *left;
  struct bintree_t *right;
};
typedef struct bintree_t bintree_t;

/* Convenience type for passing a function that acts on a tree node. */
typedef void bintree_node_fn(bintree_t*);

/* Populates a complete binary tree from provided node
   values. Assembles the tree in a breadth-first manner. Returns a
   pointer to the tree's root node. */
bintree_t * bintree_build_complete(int num_nodes, bintree_val_t value_ptrs, size_t value_size);

/* Equal to the number of nodes in the binary tree. */
int bintree_length(bintree_t *root);

/* Traverse the tree using inorder; applies node_action function to
   each node. */
bintree_t * bintree_inorder(bintree_t *root, bintree_node_fn node_action);

/* Traverse the tree using preorder; applies node_action function to
   each node. */
bintree_t * bintree_preorder(bintree_t *root, bintree_node_fn node_action);

/* Traverse the tree using postorder; applies node_action function to
   each node. */
bintree_t * bintree_postorder(bintree_t *root, bintree_node_fn node_action);

/* Frees memory previously allocated to the tree. */
void bintree_free(bintree_t *root);

#endif
