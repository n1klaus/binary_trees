#include "binary_trees.h"
/**
 * searchTree - searches an entire binary tree for the leaf node at the end
 * @tree : pointer to the root node of the tree to search
 *
 * Return: leaf node found
 */
binary_tree_t *searchTree(binary_tree_t *tree)
{
	binary_tree_t *currNode = tree;

	while (currNode != NULL)
	{
		printf("Visiting elements: %d\n", currNode->n);
		if (currNode->left != NULL)
			currNode = currNode->left;
		else if (currNode->right != NULL)
			currNode = currNode->right;
		else
			break;
	}
	return (currNode);
}

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree : pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *lastNode = NULL, *tempNode = NULL;

	if (tree == NULL)
		return;

	lastNode = searchTree(tree);

	while (lastNode != NULL)
	{
		if (lastNode->left != NULL)
		{
			tempNode = lastNode->left;
			lastNode->left = NULL;
		}
		else if (lastNode->right != NULL)
		{
			tempNode = lastNode->right;
			lastNode->right = NULL;
		}
		else
		{
			if (lastNode->parent == NULL)
			{
				tempNode = searchTree(tree);
				if (tempNode->parent != NULL)
					lastNode = tempNode->parent;
			}
			else
			{
				tempNode = lastNode;
				lastNode = lastNode->parent;
			}
		}
		printf("Deleting elements: %d\n", tempNode->n);
		tempNode->parent = NULL;
		free(tempNode);
	}
	return;
}
