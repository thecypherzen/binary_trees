#include "binary_trees.h"

/**
 * bst_insert - inserts a node into a bst
 *
 * @tree: double pointer to the root node of bst
 * @value: the value to insert into bst
 *
 * If value is aready in tree, it's ignored
 * If @tree is NULL, new node becomes the root node.
 *
 * Return: a pointer inserted node, NULL otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{

	bst_t *new_node, *parent, *temp;

	if (!(*tree))
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	temp = *tree;
	while (temp)
	{
		if (temp->n == value)
			return (NULL);
		parent = temp;
		if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	new_node = binary_tree_node(parent, value);
	if (parent)
	{
		if (value < parent->n)
			parent->left = new_node;
		if (parent->n < value)
			parent->right = new_node;
	}
	return (new_node);
}
