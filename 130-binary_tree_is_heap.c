#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max_heap - Checks if a binary tree is a max heap recursively.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int check_max_heap(const binary_tree_t *tree)
{
	int left_result = 1, right_result = 1;

	if (!tree)
		return (1);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		left_result = check_max_heap(tree->left);
	}

	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		right_result = check_max_heap(tree->right);
	}

	return (left_result && right_result);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid max binary heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid max binary heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_max_heap(tree));
}
