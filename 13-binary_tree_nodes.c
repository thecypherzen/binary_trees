#include "binary_trees.h"


/**
 * binary_tree_nodes - a function that counts the nodes with at least 1
 * +child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count nodes
 *
 * Return: 0 if @tree is NULL
 *		   number of nodes in @tree otherwise
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return ( 1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}
