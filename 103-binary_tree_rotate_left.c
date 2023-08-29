#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree.
 * @tree: pointer to the root node of the tree to solve
 *
 * Return: Pointer to the root node of the tree once rotated
 *         NULL - failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *index = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	index = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		index->right = tree->left;
		tree->left->parent = index;
	}
	else
		index->right = NULL;
	index->parent = tree;
	tree->left = index;
	if (parent)
		parent->right = tree;
	tree->parent = parent;

	return (tree);
}
