#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent : pointer to the parent node of the node to create
 * @value : value to put in the new node
 *
 * Return: Pointer to the new tree node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *lastNode = NULL, *tempNode = NULL;
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent == NULL)
	{
		parent = newNode;
		newNode->parent = NULL;
	}
	else
	{
		tempNode = parent;
		while (tempNode != NULL)
		{
			lastNode = tempNode;
			if (newNode->n < tempNode->n)
				tempNode = tempNode->left;
			else
				tempNode = tempNode->right;
		}
		newNode->parent = lastNode;
	}
	return (newNode);
}
