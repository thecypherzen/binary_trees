#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that rotates a binary tree to the
 * left. When you rotate left, the current_node's right becomes empty.
 * and needs to be replaced with the new_nodes' left child.
 * In the new tree:
 *	1. the old_root's right child becomes the new root
 *	2. the new_root's left-child becomes the old_root's right child.
 *
 * @tree: pointer to root node of tree to rotate
 *
 * Return: a pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_root_parent;

	if (!tree)
		return (tree);
	old_root = tree, new_root = old_root->right;
	old_root_parent = old_root->parent;

	old_root->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = old_root;
	new_root->left = old_root;
	old_root->parent = new_root;
	new_root->parent = old_root_parent;
	return(new_root);
}
