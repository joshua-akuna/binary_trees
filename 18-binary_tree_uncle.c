#include "binary_trees.h"

/**
 * _binary_tree_sibling - finds the sibling of a node.
 * @node: a pointer to the node of the the sibling
 * Return: a pointer to the sibling node or
 *	NULL if node or its parent is NULL
 */
binary_tree_t *_binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL, *sibling = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	sibling = parent->left == node ? parent->right : parent->left;

	return (sibling);
}

/**
 * binary_tree_uncle - a pointer to the node to find the uncle
 * @node: a pointer to the node to find the uncle.
 * Return: a pointer to the uncle node or
 *	NULL if node is NULL
 *	NULL if node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (_binary_tree_sibling(node->parent));
}
