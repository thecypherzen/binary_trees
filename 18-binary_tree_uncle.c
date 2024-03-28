#include "binary_trees.h"


/**
 * binary_tree_uncle - a function that finds the uncle of a node
 *
 * @node: pointer to the root node to find the sibling
 *
 * Return: pointer to siblilng node if found
 *		   NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->parent->left == node->parent)
	{
		if (!node->parent->parent->right)
			return (NULL);
		uncle = node->parent->parent->right;
	}
	else if (node->parent->parent->right == node->parent)
	{
		if (!node->parent->parent->left)
			return (NULL);
		uncle = node->parent->parent->left;
	}
	return (uncle);
}
