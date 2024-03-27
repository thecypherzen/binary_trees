#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a binary tree
 *
 * @tree: pointer to the root node to measure
 *
 * Return: depth if @tree is NOT NULL
 *		   0 otherwise
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (depth);

	while (tree->parent)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth);
}
