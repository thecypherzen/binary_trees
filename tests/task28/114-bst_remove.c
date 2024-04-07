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

	temp = bst_node_to_remove(root, value);
	if (!temp)
		return (root);
	printf("    to remove: [%d]\n", temp->n);
	if (!temp->right && !temp->left)
	{
		if (temp->parent->left == temp)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;
		temp->parent = NULL; free(temp);
		return (root);
	}
	if (temp == root)
	{
		printf("   to remove root: %d\n", temp->n);
		return bst_remove_root(root);
	}
	if (temp->right && temp->left)
	{
		next = bst_inorder_successor(temp);
		printf("next = %d\n", next->n);
		if (next->parent != temp)
		{
			next->parent->left = NULL, next->right = temp->right;
			temp->right->parent = next;
		}
		printf("step 2...\n");
		next->left = temp->left, temp->left->parent = next;
		next->parent = temp->parent;
		if (temp->parent->left == temp)
			temp->parent->left = next;
		else
			temp->parent->right = next;
		free(temp);
		printf("returning root as %d\n", root->n);
		return (root);
	}
	bst_remove_inode(temp);
	return (root);
}

void bst_remove_inode(bst_t *node)
{
	if (node->parent->right == node)
	{
		if (node->left)
		{
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}
		else
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}
	else
	{
		if (node->left)
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		else
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}
	free(node);
}


bst_t *bst_remove_root(bst_t *root)
{
	bst_t *temp, *next;

	temp = root;
	if (!temp->left && !temp->right)
	{
		root = NULL, free(temp);
		return (root);
	}
	next = bst_inorder_successor(temp);
	if (!next)
	{
		root = temp->left, root->parent = NULL, free(temp);
		return (root);
	}
	if (next == temp->right)
		temp->left->parent = next;
	else
	{
		next->right = temp->right, temp->right->parent = next;
		next->parent->left = NULL;
	}
	next->left = temp->left, temp->left->parent = next;
	next->parent = temp->parent, root = next, free(temp);
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


bst_t *bst_node_to_remove(bst_t *root, int value)
{
	bst_t *temp;

	temp = root;

	while (temp)
	{
		if (temp->n == value)
			break;
		if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (temp);
}
