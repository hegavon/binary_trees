#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Description: This function measures the size of a binary tree, i.e., the
 * number of nodes in the tree. If the tree is empty (i.e., `tree` is NULL),
 * the function returns 0.
 *
 * Return: The size of the binary tree, or 0 if the tree is empty
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

