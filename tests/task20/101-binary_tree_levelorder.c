#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - a function that goes through a binary tree using
 * level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the node is
 *		  be passed as a parameter to this function.
 *
 * If @tree is NULL, it does nothing
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL, *current;

	if (!tree || !func)
		return;
	queue_push(&queue, tree);
	if (!queue)
	{
		printf("queue init failed\n");
		return;
	}

	while (queue)
	{
		/*print_queue(queue);*/
		current = queue_pop(&queue);
		if (current->tree->left)
			queue_push(&queue, current->tree->left);
		if (current->tree->right)
			queue_push(&queue, current->tree->right);
		func(current->tree->n);
		queue_free(&current);
	}
	queue_free(&queue);
}
