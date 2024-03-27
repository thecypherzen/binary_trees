#include "binary_trees.h"


/**
 * binary_tree_delete - a function that deletes an entire binary tree
 *
 * if @tree is NULL, does nothing.
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{

	if (!tree)
		return;
	printf("Freeing: %d\n", );
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
