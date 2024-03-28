#include "binary_trees.h"

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
 * binary_tree_height_int - calculates the height of a binary tree
 * +but returns an int instead of a unsigned int.
 *
 * @tree: pointer to the tree's root
 *
 * Return: number of levels in tree starting from @tree node
 */
int binary_tree_height_int(const binary_tree_t *tree)
{
    if (!tree)
        return (-1);
    return (1 + (_int_max(2, binary_tree_height_int(tree->left),
                          binary_tree_height_int(tree->right))));
}


/**
 * binary_tree_balance - a function that measures the balance factor
 * +of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: 0 if @tree is NULL
 *		   balance factor of @tree otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}
