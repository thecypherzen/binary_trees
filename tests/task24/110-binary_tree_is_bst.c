#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * Properties of a bst:
 *	1. the left sub tree values of a node are <  the node's value
 *	2. the right sub tree values of a node are > the node's value
 *	3. the left and right sub trees are bsts.
 *	4. there are no duplicate values.
 *
 * @tree: pointer to root node of tree to rotate
 *
 * Return: a pointer to the new root node of the tree after rotation
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int no_dups, is_bst, min = -2147483648, max = 2147483647;
	queue_t *queue = NULL;

	if (!tree)
		return (0);
	is_bst = validate_subtree_values(tree, min, max);
	no_dups = tree_has_no_dup(&queue, tree);
	queue_free(&queue);
	return (is_bst && no_dups);
}

/**
 * tree_has_no_dup - checks that a binary tree has no duplicate
 * values
 *
 * @queue: pointer to the queue structure to use for checking
 * @root: pointer to the binary tree's root
 *
 * Return: 1 if there is no duplicate
 *		   0 otherwise
 */
int tree_has_no_dup(queue_t **queue, const binary_tree_t *root)
{
	int ret;

	if (!root)
		return (1);

	/* push node into queue if not duplicated. Else ret false */
	ret = val_in_queue(queue, root->n);
	if (ret)
		return (0);
	queue_push(queue, root);

	/* check subtree values for duplicates */
	return (tree_has_no_dup(queue, root->left) &&
			tree_has_no_dup(queue, root->right));
}

/**
 * validate_subtree_values - validates that a binary tree
 * is a bst
 *
 * @tree: pointer to the tree's node
 * @root: pointer to the tree's root
 * @min: minimum value for left subtree check
 * @max: maximum value for the right subtree check
 *
 * Return: 1 if tree is a bst
 *		   0 otherwise
 */
int validate_subtree_values(const binary_tree_t *tree, int min, int max)
{
	int check_pass;

	if (!tree)
		return (1);

	/* check if node.left < node < node.right */
	if (!tree->left && !tree->right)
		check_pass = 1;
	if (tree->left && !tree->right)
		check_pass = tree->left->n < tree->n;
	if (!tree->left && tree->right)
		check_pass = tree->n < tree->right->n;
	if (tree->left && tree->right)
	{
		check_pass = tree->left->n < tree->n &&
			tree->n < tree->right->n;
	}
	if (!(min < tree->n && tree->n < max))
		return (0);

	/* check if sub trees are bsts */
	return (check_pass &&
			validate_subtree_values(tree->left, min, tree->n) &&
			validate_subtree_values(tree->right, tree->n, max));
}
