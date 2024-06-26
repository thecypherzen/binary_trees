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
    size_t nodes;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
	binary_tree_insert_left(root->left->right, 14);
    binary_tree_print(root);

    nodes = binary_tree_nodes(root);
    printf("Nodes in %d: %lu\n", root->n, nodes);
    nodes = binary_tree_nodes(root->right);
    printf("Nodes in %d: %lu\n", root->right->n, nodes);
    nodes = binary_tree_nodes(root->left->right);
    printf("Nodes in %d: %lu\n", root->left->right->n, nodes);
	printf("================ *** ================\n");
    nodes = binary_tree_nodes(root->left);
    printf("Nodes in %d: %lu\n", root->left->n, nodes);
    nodes = binary_tree_nodes(root->left->right);
    printf("Nodes in %d: %lu\n", root->right->right->n, nodes);
    nodes = binary_tree_nodes(root->left->right->left);
    printf("Nodes in %d: %lu\n", root->left->right->left->n, nodes);
	nodes = binary_tree_nodes(NULL);
    printf("Nodes in NULL: %lu\n", nodes);
    return (0);
}
