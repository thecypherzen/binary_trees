#include "binary_trees.h"

/**
 * array_to_bst - builds a bst from an array
 *
 * @array: pointer to array
 * @size: size of array
 *
 * If value is aready in tree, it's ignored
 *
 * Return: a pointer to bst root node
 */
bst_t *array_to_bst(int *array, size_t size)
{

	bst_t *root = NULL;
	size_t i;

	if (!size || !array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
