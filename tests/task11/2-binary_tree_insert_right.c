#include "binary_trees.h"


/**
 * binary_tree_insert_right - a function that inserts a node as the right-child \
 * +of another node
 *
 * If parent already has a right-child, the new node must take its place, and \
 * +the old right-child must be set as the right-child of the new node.
 *
 * @parent: a pointer to the node to insert right child in
 * @value: value of the node to insert in new node
 *
 * Return: Pointer to inserted node on success \
 * 		   NULL if malloc fails or parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
