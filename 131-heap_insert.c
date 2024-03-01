#include "binary_trees.h"

/**
 * heapify_up - Performs the "heapify-up" operation after insertion.
 * @node: The newly inserted node.
 */
void heapify_up(heap_t *node)
{
	int temp;
	heap_t *parent;

	while (node && node->parent)
	{
		parent = node->parent;

		if (node->n > parent->n)
		{
			temp = node->n;
			node->n = parent->n;
			parent->n = temp;
			node = parent;
		}
		else
		{
			break;
		}
	}
}

/**
 * insert_parent - Finds the parent node for a new node insertion.
 * @root: Pointer to the root node of the binary tree.
 * Return: Pointer to the parent node.
 */
heap_t *insert_parent(heap_t *root)
{
	heap_t *parent = NULL;

	if (!root)
		return (NULL);

	if (!root->left || !root->right)
		return (root);

	parent = insert_parent(root->left);
	if (!parent)
		parent = insert_parent(root->right);

	return (parent);
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

	parent = insert_parent(*root);

	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;

	node->parent = parent;
	heapify_up(node);

	return (node);
}
