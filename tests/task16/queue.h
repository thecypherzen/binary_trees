#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_s
{
	const binary_tree_t *tree;
	struct queue_s *next;
	struct queue_s *prev;
} queue_t;

void queue_push(queue_t **queue, const binary_tree_t *tree)
{
	queue_t *temp, *new_node;

	if (!queue || !tree)
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

void print_queue(queue_t *head)
{
	queue_t *temp = head;

	while (temp)
	{
		printf("%d\n", temp->tree->n);
		temp = temp->next;
	}
}

void queue_free(queue_t **queue)
{
	queue_t *temp;

	if (!queue || !(*queue))
		return;

	while (*queue)
	{
		temp = (*queue)->next;
		free(*queue);
		*queue = temp;
	}
}

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
#endif /* QUEUE_H */
