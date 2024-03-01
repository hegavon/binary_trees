#include "binary_trees.h"

/**
 * heapify_up - Performs the "heapify-up" operation after insertion.
 * @node: The newly inserted node.
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent, *temp;

	if (!root)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (!*root)
		return (*root = node);

	/* Find parent of the last node */
	parent = *root;
	while (parent->left && parent->right)
	{
		if (!parent->left->left || !parent->left->right)
			parent = parent->left;
		else
			parent = parent->right;
	}

	/* Insert node */
	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;

	node->parent = parent;

	/* Perform heapify-up operation */
	heapify_up(node);

	/* Adjust root if necessary */
	temp = node;
	while (temp->parent)
		temp = temp->parent;
	*root = temp;

	return (node);
}
