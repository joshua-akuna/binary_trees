#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of
 *	another node.
 * @parent: a pointer to the node to insert the left child in.
 * @value: the value to store in the new node.
 * Return: a pointer to the newly created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *left;

	if (parent == NULL)
		return (NULL);

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	left = parent->left;
	node->parent = parent;
	node->left = left;
	node->right = NULL;
	node->n = value;
	parent->left = node;
	return (node);
}
