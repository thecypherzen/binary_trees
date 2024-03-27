#ifndef _CUSTOM_FUNCS_A_H
#define _CUSTOM_FUNCS_A_H

#include <stdarg.h>
#include <limits.h>

/**
 * _int_max - a function that returns the maximum between integers
 *
 * It's variadic and takes in as many ints as desired
 *
 * @n: number of expected arguments
 *
 * Return: the max of @n integers
 */
int _int_max(int n, ...)
{
	int max = INT_MIN, i, next;

	if (n)
	{
		va_list numbers;

		va_start(numbers, n);
		for (i = 0; i < n; i++)
		{
			next = va_arg(numbers, int);
			if (next > max)
				max = next;
		}
		va_end(numbers);
	}
	return (max);
}

/**
 * binary_tree_levels - a helper recursive function to get levels of
 * +nodes in a binary tree, beginning from node's level
 *
 * @tree: pointer to the tree's root
 *
 * Return: number of levels in tree starting from @tree node
 */
size_t binary_tree_levels(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _int_max(2, binary_tree_levels(tree->left),
						 binary_tree_levels(tree->right)));
}

#endif /* CUSTOM_FUNCS_A_H */
