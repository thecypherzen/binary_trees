#include "binary_trees.h"
#include "15-binary_tree_is_full.c"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if @tree is NULL or not perfect
 *		   1 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_balance(tree))
		return (0);
	if (!binary_tree_is_full(tree))
		return (0);
	return (1);
}
