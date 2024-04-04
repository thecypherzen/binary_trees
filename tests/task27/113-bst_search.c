#include "binary_trees.h"

/**
 * bst_search - searches for a value in a bst
 *
 * @tree: pointer to tree's root
 * @value: value to search for
 *
 *
 * Return: pointer to node containing value
 *		   NULL if tree is NULL or value is not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	bst_t *temp;

	if (!tree)
		return (NULL);

	temp = (bst_t *)tree;
	while (temp)
	{
		if ((temp)->n == value)
			return (temp);
		if (value < (temp)->n)
			(temp) = (temp)->left;
		else
			(temp) = (temp)->right;
	}
	return (temp);
}
