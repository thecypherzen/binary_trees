#include "binary_trees.h"


/**
 * binary_tree_postorder - a function that goes through a binary tree using \
 * +post-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *
 * Does nothing if @treee or @func is null
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{

	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 *
void print_num(int n)
{
    printf("%d\n", n);
}
*/
