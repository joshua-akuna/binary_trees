#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses the binary tree using the
 *	pre-order traversal.
 * @tree: a pointer to the root node of the tree to trasverse.
 * @func: a pointer to the function to call for each node.
 *	The value in the node must be as a parameter to this function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
