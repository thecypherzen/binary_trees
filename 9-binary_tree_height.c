#include "binary_trees.h"
#include "custom_funcs_a.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the binary tree
 *
 * Return: height if @tree is NOT NULL
 *		   0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = binary_tree_levels(tree);

	return (height - 1);
}
