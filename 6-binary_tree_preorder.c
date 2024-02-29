#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function goes through a binary tree using pre-order
 * traversal, i.e., it visits the root node first, then the left subtree, and
 * finally the right subtree. For each node, the function calls the specified
 * function `func` and passes the value in the node as a parameter to `func`.
 * If the tree or `func` is NULL, the function does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

