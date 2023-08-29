#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: pointer to the root node of the tree to solve
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL - failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *index = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);

	index = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		index->left = tree->right;
		tree->right->parent = index;
	}
	else
		index->left = NULL;

	index->parent = tree;
	tree->right = index;
	if (parent)
		parent->left = tree;
	tree->parent = parent;

	return (tree);
}
