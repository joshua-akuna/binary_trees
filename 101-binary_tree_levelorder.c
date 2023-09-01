#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * print_current_level - prints the current level of the binary
 *	tree.
 * @tree: a binary tree
 * @func: a call back function to print the content of a node
 * @level: an int argument.
 */
void print_current_level(const binary_tree_t *tree,
		void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_current_level(tree->left, func, level - 1);
		print_current_level(tree->right, func, level - 1);
	}
}


/**
 * binary_trees_levelorder - traverses through a binary tree using
 *	level-order traversal.
 * @tree: a binary tree
 * @func: a call back function to print the content of a node
 */
void binary_trees_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, level = tree_height(tree);

	for (i = 1; i <= level + 1; i++)
		print_current_level(tree, func, i);
}

/**
 * binary_tree_levelorder - traverses through a binary tree using
 *	level-order traversal.
 * @tree: a binary tree
 * @func: a call back function to print the content of a node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[100];
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
