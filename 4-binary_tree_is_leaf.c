#include "binary_trees.h"


/**
 * binary_tree_is_leaf - a function that checks if a tree node is a leaf
 *
 * @node: pointer to the node to be checked
 *
 * Return: 1 if @node is a leaf
 *		   0 if @node is not a leaf or is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}
