#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node
 * @node: The binary tree node for the new node to contain
 *
 * Return: A pointer to the new node, or NULL on failure
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue
 * @head: A pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	levelorder_queue_t *queue = create_node((binary_tree_t *)tree);
	if (queue == NULL)
		return;

	levelorder_queue_t *tail = queue;
	while (queue != NULL)
	{
		binary_tree_t *current = queue->node;
		func(current->n);

		if (current->left != NULL)
		{
			tail->next = create_node(current->left);
			if (tail->next == NULL)
			{
				free_queue(queue);
				return;
			}
			tail = tail->next;
		}

		if (current->right != NULL)
		{
			tail->next = create_node(current->right);
			if (tail->next == NULL)
			{
				free_queue(queue);
				return;
			}
			tail = tail->next;
		}

		levelorder_queue_t *temp = queue;
		queue = queue->next;
		free(temp);
	}
}

