#include "binary_trees.h"


/**
 * binary_tree_insert_left - a function that inserts a node as the left-child \
 * +of another node
 *
 * If parent already has a left-child, the new node must take its place, and \
 * +the old left-child must be set as the left-child of the new node.
 *
 * @parent: a pointer to the node to insert left child in
 * @value: value of the node to insert in new node
 *
 * Return: Pointer to inserted node on success \
 * 		   NULL if malloc fails or parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
