#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;

		right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;
		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}
