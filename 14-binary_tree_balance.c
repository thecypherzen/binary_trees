#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance - a function that measures the balance factor
 * +of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: 0 if @tree is NULL
 *		   balance factor of @tree otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height_int(tree->left) -
	binary_tree_height_int(tree->right));
}
