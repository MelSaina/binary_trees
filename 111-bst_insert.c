#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be added
 *
 * Return: A pointer to the created node
 *         NULL - failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *index = NULL;
	bst_t *second = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	index = *tree;
	while (index)
	{
		second = index;
		if (value < index->n)
			index = index->left;
		else if (value > index->n)
			index = index->right;
		else if (value == index->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;

	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}
