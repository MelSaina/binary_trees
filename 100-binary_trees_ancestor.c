#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodess
 * @first: A pointer to first node
 * @second: A pointer to second node
 *
 * Return: if no common ancestors return NULL
 * else return common ancestors
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *first_node = (binary_tree_t *)first;
	binary_tree_t *second_node = (binary_tree_t *)second;
	int count1 = 0;
	int count2 = 0;

	while (first != NULL)
	{
		first = first->parent;
		count1++;
	}
	while (second != NULL)
	{
		second = second->parent;
		count2++;
	}

	while (count1 > count2)
	{
		first_node = first_node->parent;
		count1--;
	}
	while (count2 > count1)
	{
		second_node = second_node->parent;
		count2--;
	}
	while (first_node != second_node)
	{
		first_node = first_node->parent;
		second_node = second_node->parent;
	}
	return (first_node);
}
