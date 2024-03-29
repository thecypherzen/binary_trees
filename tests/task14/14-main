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
	int balance;

	root = binary_tree_node(NULL, 98);

	balance = binary_tree_balance(root);
	printf("Balance factor for tree with root node (%d): %+d\n", root->n, balance);

	binary_tree_print(root);
	binary_tree_delete(root);
	return (0);
}
