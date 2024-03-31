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
    size_t height;
	int h;

    root = binary_tree_node(NULL, 98);
    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
	binary_tree_insert_left(root->right->right, 33);
	binary_tree_insert_right(root->right->right, 43);
	binary_tree_insert_left(root->right->right->right, 51);
	binary_tree_insert_left(root->left->right, 31);
	binary_tree_insert_left(root->left, 21);
	binary_tree_insert_right(root->left->right, 32);

    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height);
	height = binary_tree_height(root->left);
	printf("Height from %d: %lu\n", root->left->n, height);
    height = binary_tree_height(NULL);
    printf("Height of NULL %lu\n", height);
	h = binary_tree_height_int(NULL);
	printf("Height_int of NULL %d\n", h);
    return (0);
}
