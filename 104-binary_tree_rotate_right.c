#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that rotates a binary tree to the
 * right. When you rotate right, the current_root's left becomes empty.
 * and needs to be replaced with the new_root's right child.
 * In the new tree:
 *	1. the old_root's left child becomes the new root
 *	2. the new_root's right-child becomes the old_root's left child.
 *
 * @tree: pointer to root node of tree to rotate
 *
 * Return: a pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_root_parent;

	if (!tree)
		return (tree);
	old_root = tree, new_root = old_root->left;
	old_root_parent = old_root->parent;

	old_root->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = old_root;
	new_root->right = old_root;
	old_root->parent = new_root;
	new_root->parent = old_root_parent;
	return (new_root);
}
