#include "binary_trees.h"


/**
 * binary_trees_ancestor - a function that finds finds the lowest common
 * ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer tot the second node
 *
 * Return: pointer to the lowest common ancestor if found
 *		   NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *current;
	int node_in_tree;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return (first->left->parent);
	/**
	 *if (first->parent == second)
	 *	return (first->parent);
	 *if (second->parent == first)
	 *return (second->parent);
	 */

	current = first->parent;
	while (current)
	{
		node_in_tree = node_in_binary_tree(current, second);
		if (node_in_tree)
			return (current);
		current = current->parent;
	}
	return (NULL);
}

/**
 * node_in_binary_tree - checks if a binary tree node is in a tree
 *
 * @parent: the root node of the binary_tree
 * @child: the node of the child to search for
 *
 * Return: 1 if @child is a child of @parent
 *		   0 if @child is not a child of @parent or either is NULL
 */
int node_in_binary_tree(const binary_tree_t *parent,
						const binary_tree_t *child)
{
	int retval;

	if (!parent || !child)
		return (0);
	retval = parent->left == child || parent->right == child ? 1 : 0;
	return (retval ? retval : (node_in_binary_tree(parent->left, child) ||
							   node_in_binary_tree(parent->right, child)));
}
