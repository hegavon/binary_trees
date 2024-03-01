#include "binary_trees.h"

/**
 * max_heapify - heapifies a subtree rooted at given index
 * @arr: array representing the heap
 * @n: size of the heap
 * @i: index of the subtree to heapify
 **/
void max_heapify(int *arr, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		int temp = arr[i];

		arr[i] = arr[largest];
		arr[largest] = temp;

		max_heapify(arr, n, largest);
	}
}

/**
 * heap_to_sorted_array - It converts a heap to a sorted array
 * @heap: The pointer to the root node of the heap
 * @size: The address to store the size of the array
 * Return: It returns a pointer to the array, or NULL on failure
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (!heap)
		return (NULL);

	size_t n = binary_tree_size(heap);

	int *sorted_array = malloc(sizeof(int) * n);

	if (!sorted_array)
		return (NULL);

	size_t i;

	for (i = 0; i < n; ++i)
	{
		sorted_array[i] = heap->n;
		heap->n = heap_extract(&heap);
	}

	*size = n;
	return (sorted_array);
}
