#include "binary_trees.h"

/**
 * count_nodes - count the number of nodes in the tree.
 * @tree: a binary tree.
 * Return: returns the number of nodes in the tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * check_complete - checks if the binary tree is complete.
 * @tree: a binary tree.
 * @index: an int argument.
 * @nodes: the number of nodes in the tree.
 * Return: 1 if binary tree is complete else 0.
 */
int check_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (check_complete(tree->left, 2 * index + 1, nodes)
			&& check_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if the binary tree is complete
 * @tree: a binary tree.
 * Return: 1 if binary tree is complete else 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	int node_count = count_nodes(tree);

	if (tree == NULL)
		return (0);

	return (check_complete(tree, index, node_count));
}
