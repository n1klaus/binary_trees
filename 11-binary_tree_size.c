#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 *
 * Return: size of the tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	const binary_tree_t *tempNode = tree;
	size_t size;

	if (tree == NULL)
		return (0);

	size = 1;
	if (tempNode != NULL)
	{
		size += binary_tree_size(tempNode->left);
		size += binary_tree_size(tempNode->right);
	}
	return (size);
}
