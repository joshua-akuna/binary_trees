#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: the parent node for the newly created node.
 * @value: the value of the n attrubute of the new created node of
 *	type binary_tree_t.
 * Return: returns the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}
