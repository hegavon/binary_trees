#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Description: This function counts the nodes with at least 1 child in a
 * binary tree. If the tree is empty (i.e., `tree` is NULL), the function
 * returns 0.
 *
 * Return: The number of nodes with at least 1 child in the binary tree,
 * or 0 if the tree is empty
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

