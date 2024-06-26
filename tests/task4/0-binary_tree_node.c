#include "binary_trees.h"


/**
 * binary_tree_node - a function that creates a binary tree node
 *
 * When node is created, it doesn't have any children
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: Pointer to new node on success, NULL otherwise
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	return (new_node);
}
