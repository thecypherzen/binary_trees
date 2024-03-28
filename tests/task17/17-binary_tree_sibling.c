#include "binary_trees.h"


/**
 * binary_tree_sibling - a function that finds the sibling of a node
 *
 * @tree: pointer to the root node to find the sibling
 *
 * Return: pointer to siblilng node if found
 *		   NULL otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
	{
		if (!node->parent->right)
			return (NULL);
		sibling = node->parent->right;
	}
	else if (node->parent->right == node)
	{
		if (!node->parent->left)
			return (NULL);
		sibling = node->parent->left;
	}
	return (sibling);
}
