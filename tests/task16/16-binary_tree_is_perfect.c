#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * A perfect binary tree has:
 * 1. All internal nodes have 2 children
 * 2. All leaves are at same level
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if @tree is NULL or not perfect
 *		   1 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	queue_t *queue = NULL, *queue_item = NULL;

	if (!tree)
		return (0);
	queue_push(&queue, tree);
	if (!queue)
		return (0);
	while (queue)
	{
		queue_item = queue_pop(&queue);
		if ((queue_item->tree->left && !queue_item->tree->right) ||
			(queue_item->tree->right && !queue_item->tree->left))
		{
			discard_queue_node(&queue_item), queue_free(&queue);
			return(0);
		}
		if (!queue_item->tree->left && !queue_item->tree->right)
		{
			discard_queue_node(&queue_item);
			while (queue)
			{
				queue_item = queue_pop(&queue);
				if (queue_item->tree->left || queue_item->tree->right)
				{
					discard_queue_node(&queue_item), queue_free(&queue);
					return (0);
				}
				discard_queue_node(&queue_item);
			}
			queue_free(&queue);
			return (1);
		}
		queue_push(&queue, queue_item->tree->left);
		queue_push(&queue, queue_item->tree->right);
		discard_queue_node(&queue_item);
	}
	queue_free(&queue);
	return (0);
}
