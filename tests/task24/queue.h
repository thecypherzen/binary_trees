#ifndef QUEUE_H
#define QUEUE_H

/**
 * struct queue_s - a struct defining a quque data type
 *
 * @tree: pointer to binary_tree node it holds
 * @next: pointer to next queue node
 * @prev: pointer to previous queue node
 */
typedef struct queue_s
{
	const binary_tree_t *tree;
	struct queue_s *next;
	struct queue_s *prev;
} queue_t;

int tree_has_no_dup(queue_t **queue, const binary_tree_t *root);

/**
 * queue_push - adds a binary_tree node to the queue
 *
 * @queue: ponter to head of the queue
 * @tree: pointer to binary tree node
 *
 * Return: void
 */
void queue_push(queue_t **queue, const binary_tree_t *tree)
{
	queue_t *temp, *new_node;

	if (!queue)
		return;

	new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return;
	new_node->tree = tree;
	new_node->next = NULL;

	if (!(*queue))
	{
		new_node->prev = NULL;
		(*queue) = new_node;
		return;
	}
	temp = *queue;
	while (temp->next)
		temp = temp->next;
	new_node->prev = temp;
	temp->next = new_node;
}

/**
 * print_queue - prints all items on the queue
 *
 * @head: pointer to queue head
 *
 * Return: void
 */
void print_queue(queue_t *head)
{
	queue_t *temp = head;

	printf("  [queue]:");
	while (temp)
	{
		printf(" %d", temp->tree ? temp->tree->n : -99);
		temp = temp->next;
	}
	printf("\n");
}


/**
 * queue_free - frees all memory used by queue
 *
 * @queue: pointer to queue head pointer
 *
 * Return: void
 */
void queue_free(queue_t **queue)
{
	queue_t *temp;

	if (!queue || !(*queue))
		return;

	while (*queue)
	{
		temp = (*queue)->next;
		(*queue)->next = NULL;
		free(*queue);
		*queue = temp;
	}
	*queue = NULL;
}

/**
 * queue_pop - removes an item from the queue's end
 *
 * @queue: pointer to queue head pointer
 *
 * Return: pointer to removed queue item
 *		   NULL if NULL value is passed
 */
queue_t *queue_pop(queue_t **queue)
{
	queue_t *temp;

	if (!queue || !(*queue))
		return (NULL);
	temp = *queue;

	if ((*queue)->next)
		(*queue)->next->prev = NULL;
	(*queue) = (*queue)->next;
	temp->next = NULL;

	return (temp);
}


/**
 * discard_queue_node - discards a queue node
 * @queue_node: pointer to the queue node's head
 * Return: void
 */
void discard_queue_node(queue_t **queue_node)
{
    if (!(*queue_node) || !queue_node)
        return;
    (*queue_node)->next = NULL;
    queue_free(queue_node);
}

int val_in_queue(queue_t **queue, int val)
{
	queue_t *temp;

	if (!queue || !(*queue))
		return (0);
	temp = *queue;
	while (temp)
	{
		if (temp->tree->n == val)
			return (1);
		temp = temp->next;
	}
	return (0);
}
#endif /* QUEUE_H */
