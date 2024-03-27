#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
	binary_tree_insert_left(root->left->right, 33);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);

	printf("=============== *** ===============\n");
    depth = binary_tree_depth(NULL);
    printf("Depth of NULL: %lu\n", depth);
    depth = binary_tree_depth(root->left);
    printf("Depth of %d: %lu\n", root->left->n, depth);
    depth = binary_tree_depth(root->left->right->left);
    printf("Depth of %d: %lu\n", root->left->right->left->n, depth);
    return (0);
}
