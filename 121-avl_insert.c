#include "binary_trees.h"

avl_t *avl_insert(avl_t **tree, int value);

/**
 * bst_insert - inserts a value in a BST
 * @tree: the double pointer to the root node of the BST to enter the value
 * @value: the value to store in the node to be entered
 *
 * Return: Pointer to the node created
 *         NULL - failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *index = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

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

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree
 * @value: value to insert
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *new_node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < new_node->left->n)
		return (binary_tree_rotate_right(new_node));
	if (balance < -1 && value > new_node->right->n)
		return (binary_tree_rotate_left(new_node));
	if (balance > 1 && value > new_node->left->n)
	{
		new_node->left = binary_tree_rotate_left(new_node->left);
		return (binary_tree_rotate_right(new_node));
	}
	if (balance < -1 && value < new_node->right->n)
	{
		new_node->right = binary_tree_rotate_right(new_node->right);
		return (binary_tree_rotate_left(new_node));
	}

	return (new_node);
}
