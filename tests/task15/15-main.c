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
    int full;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    binary_tree_print(root);

    full = binary_tree_is_full(root);
    printf("Is %d full: %d\n", root->n, full);
    full = binary_tree_is_full(root->left);
    printf("Is %d full: %d\n", root->left->n, full);
    full = binary_tree_is_full(root->right);
    printf("Is %d full: %d\n", root->right->n, full);
	printf("============ **** =============\n");
	binary_tree_insert_left(root->right, 33);
	binary_tree_print(root);
	full = binary_tree_is_full(root->right);
	printf("Is %d full: %d\n", root->right->n, full);
	full = binary_tree_is_full(NULL);
	printf("Is NULL full: %d\n", full);
	full = binary_tree_is_full(root);
	printf("Is %d full: %d\n", root->n, full);
	full = binary_tree_is_full(root->left->right);
	printf("Is %d full: %d\n", root->left->right->n, full);
	full = binary_tree_is_full(root->right->left);
	 printf("Is %d full: %d\n", root->right->left->n, full);
    return (0);
}
