#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Description: This function counts the leaves in a binary tree, i.e., the
 * nodes that have no children. If the tree is empty (i.e., `tree` is NULL),
 * the function returns 0.
 *
 * Return: The number of leaves in the binary tree, or 0 if the tree is empty
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

