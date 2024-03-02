#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array in descending order, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (!heap || !size)
        return (NULL);

    *size = tree_size(heap);
    int *sorted_array = malloc(sizeof(int) * (*size));
    if (!sorted_array)
        return (NULL);

    for (size_t i = 0; i < *size; ++i)
        sorted_array[i] = heap_extract(&heap);

    return (sorted_array);
}
