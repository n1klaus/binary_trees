#include "binary_trees.h"
/**
 * binary_tree_postorder - goes through a binary tree using post-order
 * traversal
 * @tree : pointer to the root node of the tree to traverse
 * @func : pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *currNode = tree;

	if (tree == NULL || func == NULL)
		return;

	if (currNode != NULL)
	{
		binary_tree_postorder(currNode->left, func);
		binary_tree_postorder(currNode->right, func);
		func(currNode->n);
	}
}
