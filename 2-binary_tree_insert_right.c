#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert a node as the right-child of another node
 * @parent : pointer to the node to insert the right-child in
 * @value : value to store in the new node
 *
 * Return: Pointer to the new tree node,
 * or return NULL on failure or parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
		tempNode->right = newNode;
		newNode->parent = tempNode;
		newNode->right = lastNode;
		lastNode->parent = newNode;
	}
	else
	{
		lastNode->right = newNode;
		newNode->parent = lastNode;
	}
	return (newNode);
}
