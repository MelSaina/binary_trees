#include "binary_trees.h"

int bticomp_helper(const binary_tree_t *tree, size_t index, size_t s);
size_t binary_tree_s(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t s;

	if (!tree)
		return (0);
	s = binary_tree_s(tree);

	return (bticomp_helper(tree, 0, s));
}

/**
 * bticomp_helper - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: node index to check
 * @s: the number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 */

int bticomp_helper(const binary_tree_t *tree, size_t index, size_t s)
{
	if (!tree)
		return (1);

	if (index >= s)
		return (0);

	return (bticomp_helper(tree->left, 2 * index + 1, s) &&
		bticomp_helper(tree->right, 2 * index + 2, s));
}

/**
 * binary_tree_s - measure the size of a binary tree
 * @tree: tree to measure the size
 *
 * Return: size of the tree
 */
size_t binary_tree_s(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_s(tree->left) +
		binary_tree_s(tree->right) + 1);
}
