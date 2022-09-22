#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree : pointer to the root node of the tree to traverse
 * @func : pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *currNode = tree;

	if (tree == NULL || func == NULL)
		return;

	if (currNode != NULL)
	{
		func(currNode->n);
		binary_tree_preorder(currNode->left, func);
		binary_tree_preorder(currNode->right, func);
	}
}
