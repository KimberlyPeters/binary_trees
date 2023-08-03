#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);

	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_is_perfect_recursive(tree, height, 0));
}

/**
 * binary_tree_is_perfect_recursive - Recursive helper function
 * @tree: Pointer to the current node
 * @height: Height of the tree
 * @level: Current level
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(
	const binary_tree_t *tree,
	size_t height,
	size_t level
)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (height == level + 1);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	return (binary_tree_is_perfect_recursive(tree->left, height, level + 1) &&
			binary_tree_is_perfect_recursive(tree->right, height, level + 1));
}
