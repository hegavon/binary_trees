#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function goes through a binary tree using post-order
 * traversal, i.e., it visits the left subtree first, then the right subtree,
 * and finally the root node. For each node, the function calls the specified
 * function `func` and passes the value in the node as a parameter to `func`.
 * If the tree or `func` is NULL, the function does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

