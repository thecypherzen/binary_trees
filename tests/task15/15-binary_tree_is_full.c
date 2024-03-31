#include "binary_trees.h"


/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * A full binary tree has each node with at least 2 children.
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if @tree is NULL
 *		   1 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}
