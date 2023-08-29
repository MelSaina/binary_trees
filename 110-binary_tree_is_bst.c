#include "binary_trees.h"

int btb_helper(const binary_tree_t *tree, int down, int up);
/**
 * binary_tree_is_bst - checks if binary tree is valid BST
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         else 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btb_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btb_helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @down: Lower bound of checked nored
 * @up: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         else 0
 */

int btb_helper(const binary_tree_t *tree, int down, int up)
{
	if (!tree)
		return (1);

	if (tree->n < down || tree->n > up)
		return (0);

	return (btb_helper(tree->left, down, tree->n - 1) &&
		btb_helper(tree->right, tree->n + 1, up));
}
