#include "binary_trees.h"


/**
 * binary_tree_preorder - a function that goes through a binary tree using \
 * +pre-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *
 * Does nothing if @treee or @func is null
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
