#include "binary_trees.h"

/**
 * tree_size - measures the total number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: The total number of nodes in the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += 1; /* Count the current node */

		/* Recursively count nodes in the left subtree */
		count += tree_size(tree->left);

		/* Recursively count nodes in the right subtree */
		count += tree_size(tree->right);
	}

	return (count);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order,
 *         or NULL if heap is NULL or size is NULL
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *sorted_array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap); /* Calculate the size of the array */

	sorted_array = malloc(sizeof(int) * (*size));

	if (!sorted_array)
		return (NULL);

	/* Extract elements from the heap and store them in the sorted array */
	for (i = (*size) - 1; i >= 0; i--)
		sorted_array[i] = heap_extract(&heap);

	return (sorted_array);
}
