#include "binary_trees.h"

/**
 * max - determines the maximum of two height arguments.
 * @height1: an int argument.
 * @height2: and int argument.
 * Return: the maximum between height1 and height2.
 */
int max(int height1, int height2)
{
	return (height1 > height2 ? height1 : height2);
}

/**
 * height - finds the maximum depth of the binary tree.
 * @tree: the binary tree
 * Return: the height of the binary tree.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * tree_is_perfect_recursive - checks if a tree is perfect.
 * @tree: a binary tree
 * @d: an int argument
 * @level: an int argument
 * Return: 1 if tree is perfect otherwise 0
 */
int tree_is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (tree_is_perfect_recursive(tree->left, d, level + 1)
		&& tree_is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a binary tree
 * Return: 1 if tree is full, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = height(tree);

	return (tree_is_perfect_recursive(tree, d, 0));
}
