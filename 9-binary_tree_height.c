#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree : pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	const binary_tree_t *tempNode = tree;
	size_t height = 0;

	if (tree == NULL)
		return (0);

	while (tempNode != NULL)
	{
		if (tempNode->left != NULL)
			tempNode = tempNode->left;
		else if (tempNode->right != NULL)
			tempNode = tempNode->right;
		else
			break;
		height++;
	}
	return (height);
}
