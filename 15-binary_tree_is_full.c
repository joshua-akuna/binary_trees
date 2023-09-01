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
int height(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: a pointer to the node of the tree to check.
 * Return: returns 1 if tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
