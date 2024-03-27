#include "binary_trees.h"


/**
 * binary_tree_is_root - a function that checks if a tree node the root
 *
 * @node: pointer to the node to be checked
 *
 * Return: 1 if @node is the root
 *		   0 if @node is not the root or is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{

	if (!node || node->parent)
		return (0);

	return (1);
}
