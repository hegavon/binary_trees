#include "binary_trees.h"

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for nodes in the tree.
 * @max: The maximum allowed value for nodes in the tree.
 * @height: The height of the current subtree.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max, size_t *height)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return 1;
	}

	if (tree->n < min || tree->n > max)
		return 0;

	if (!is_avl_helper(tree->left, min, tree->n - 1, &left_height) ||
			!is_avl_helper(tree->right, tree->n + 1, max, &right_height))
		return 0;

	*height = 1 + (left_height > right_height ? left_height : right_height);

	return (left_height > right_height ? left_height - right_height : right_height - left_height) <= 1;
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height = 0;
	return is_avl_helper(tree, INT_MIN, INT_MAX, &height);
}
