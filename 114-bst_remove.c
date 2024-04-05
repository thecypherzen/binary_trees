#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree.
 *
 * @root: pointer to the root node of the tree
 * @value: value to be removed from tree
 *
 * Node containing @value is removed and freed.
 * If the node to be deleted has two children, it must be replaced with its
 * first in-order successor (not predecessor)
 *
 * Return: pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *next;

	temp = root;
	/* get node to replace */
	while (temp)
	{
		if (temp->n == value)
			break;
		if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (!temp)
		return (temp);
	if (temp->right && temp->left) /* swap if node.left && node.right */
	{
		next = bst_inorder_successor(temp);
		next->left = temp->left, next->right = temp->right;
		temp->left->parent = next, temp->right->parent = next;
	}
	else
		next = temp->left ? temp->left : temp->right;
	if (next->parent->left == next)
		next->parent->left = NULL;
	next->parent = temp->parent;
	/* swap parents or root */
	if (temp->parent)
	{
		if (temp->parent->n < next->n)
			temp->parent->right = next;
		else
			temp->parent->left = next;
	}
	else
		root = next;
	temp->left = NULL, temp->right = NULL, free(temp);
	return (root);
}


/**
 * bst_inorder_successor - get inorder successor to a node
 *
 * @tree: pointer to tree's node to get successor
 *
 * Return: pointer to successor node.
 */
bst_t *bst_inorder_successor(bst_t *tree)
{
	bst_t *temp;

	if (!tree || !tree->right)
		return (NULL);
	temp = tree->right;
	while (temp->left)
		temp = temp->left;
	return (temp);
}
