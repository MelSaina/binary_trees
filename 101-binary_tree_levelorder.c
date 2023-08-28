#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traverse
 * @tree: Pointer tree to traverse
 * @func: A pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binarytr_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btrlo_helper(tree, func, level);
}

/**
 * btrlo_helper - runs through a binary tree using post order traverse
 *
 * @tree: A pointer tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void btrlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btrlo_helper(tree->left, func, level - 1);
		btrlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binarytr_height - measures the height of a binary tree
 * @tree: tree to measure the height
 *
 * Return: height of the tree
 *
 */
size_t binarytr_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binarytr_height(tree->left) : 0;
	height_r = tree->right ? 1 + binarytr_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
