#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree : pointer to the root node of the tree to measure the depth
 *
 * Return: depth of the node, otherwise 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *tempNode = tree;
	size_t height = 0;

	if (tree == NULL)
		return (0);

	while (tempNode->parent != NULL && height++)
		tempNode = tempNode->parent;
	return (height);
}
