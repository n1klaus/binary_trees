#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree : pointer to the root node of the tree to count the number of leaves
 *
 * Return: size of the tree, otherwise 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	const binary_tree_t *tempNode = tree;
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if ((tempNode->left != NULL) || (tempNode->right != NULL))
	{
		if (tempNode->left != NULL)
			count += binary_tree_leaves(tempNode->left);
		else
			count += binary_tree_leaves(tempNode->right);
	}
	else
		count++;
	return (count);
}
