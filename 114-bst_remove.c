#include "binary_trees.h"

bst_t *bst_min_value(bst_t *root);

/**
 * bst_remove - removes a node from a BST
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 *         NULL - failure
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_min_value(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * bst_min_value - finds the smallest node from a BST
 * @root: a pointer to the root node of the tree
 *
 * Return: A pointer to the smallest node
 */

bst_t *bst_min_value(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}
