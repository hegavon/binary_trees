#include "binary_trees.h"

/**
 * swap_nodes - Swaps the values of two nodes.
 * @node1: The first node.
 * @node2: The second node.
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Performs the "heapify-up" operation after insertion.
 * @node: The newly inserted node.
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
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
	heap_t *node, *parent;

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

	return (node);
}
