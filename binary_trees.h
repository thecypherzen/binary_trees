#ifndef B_TREES_H
#define B_TREES_H

#include <stddef.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;


binary_tree_t bst_t;
binary_tree_t avl_t;
binary_tree_t heap_t;
void binary_tree_print(const binary_tree_t *);

#endif /* B_TREES_H */
