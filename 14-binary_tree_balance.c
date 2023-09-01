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
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Return: the balance factor of a node.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l = 0;
	int height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = height(tree->left);
	height_r = height(tree->right);

	return (height_l - height_r);
}
