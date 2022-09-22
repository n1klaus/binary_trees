#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree : pointer to the root node of the tree to measure the balance factor
 *
 * Return: number of nodes with at least 1 child, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	const binary_tree_t *tempNode = tree;
	int leftCount = 0, rightCount = 0;

	if (tree == NULL)
		return (0);

	if ((tempNode->left != NULL) || (tempNode->right != NULL))
	{
		if (tempNode->left != NULL)
		{
			leftCount++;
			leftCount += binary_tree_balance(tempNode->left);
			return (leftCount);
		}
		if (tempNode->left != NULL)
		{
			rightCount++;
			rightCount += binary_tree_balance(tempNode->left);
			return (rightCount);
		}
	}
	return (0);
}
