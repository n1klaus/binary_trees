#include "binary_trees.h"
/**
 * binary_tree_insert_left - creates a binary tree node
 * @parent : pointer to the node to insert the left-child in
 * @value : value to store in the new node
 *
 * Return: Pointer to the new tree node,
 * or return NULL on failure or parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lastNode = NULL, *tempNode = NULL;
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL || parent == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	tempNode = parent;
	while (tempNode != NULL)
	{
		lastNode = tempNode;
		if (newNode->n < tempNode->n)
			tempNode = tempNode->left;
		else
			tempNode = tempNode->right;
	}
	if (lastNode != parent)
	{
		tempNode = lastNode->parent;
		newNode->left = lastNode;
		lastNode->parent = newNode;
		tempNode->left = newNode;
		newNode->parent = tempNode;
	}
	else
	{
		lastNode->left = newNode;
		newNode->parent = NULL;
	}
	return (newNode);
}
