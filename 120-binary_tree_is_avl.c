#include "binary_trees.h"
#include "110-binary_tree_is_bst.c"
#include "custom_funcs_a.h"


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is an avl
 *		   0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl_helper(tree));
}

int is_avl_helper(const binary_tree_t *tree)
{
	int is_bst, h_left, h_right, diff, is_avl;

	if (!tree)
		return (1);
	is_bst = binary_tree_is_bst(tree);
	h_left = binary_tree_height_int(tree->left);
	h_right = binary_tree_height_int(tree->right);
	diff = h_left - h_right;
	diff = diff >= -1 && diff <= 1;
	is_avl = diff && is_bst;
	return (is_avl && is_avl_helper(tree->left) &&
			is_avl_helper(tree->right));
}
