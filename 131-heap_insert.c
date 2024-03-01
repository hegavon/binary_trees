#include "binary_trees.h"

/**
 * heap_insert - This function inserts a new node into the heap.
 * @root: This is a pointer to the root node of the heap to insert into.
 * @value: This is the value to insert into the heap.
 *
 * Return: A pointer to the new node, or NULL upon failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* Traverse tree to find the first leaf */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leaves.
	 * For example, if the number of leaves is 10, then the binary
	 * representation is 1010, so we traverse the tree to the left
	 * child of the root node. 1 corresponds to the left child,
	 * 0 corresponds to the right child.
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Flip the tree to restore the heap property */

	return (new);
}

/**
 * binary_tree_size - The func returns the number of nodes in a binary tree.
 * @tree: This is a pointer to the root node of the tree to measure size.
 *
 * Return: The number of nodes in the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
