#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int btiav_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - finds if a binary tree is an valis avl
 * @tree: pointer to the root node of tree
 *
 * Return: 1 if tree is avl
 *         else 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btiav_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btiav_helper - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl
 *         else 0
 */

int btiav_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (btiav_helper(tree->left, min, tree->n - 1) &&
		btiav_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 -  NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
