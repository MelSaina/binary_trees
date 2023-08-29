#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array.
 * @array: pointer to the first element of the array to be changed.
 * @size: the number of elements in array
 *
 * Return: Pointer to the root node of the created BST
 *         NULL - failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int k;

	bst_t *root = NULL;

	for (k = 0; k < size; k++)
		bst_insert(&root, array[k]);

	return (root);
}
