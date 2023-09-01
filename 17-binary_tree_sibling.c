#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: a pointer to the node of the the sibling
 * Return: a pointer to the sibling node or
 *	NULL if node or its parent is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL, *sibling = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	sibling = parent->left == node ? parent->right : parent->left;

	return (sibling);
}
