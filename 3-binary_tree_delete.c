#include "binary_trees.h"
/**
 * shiftNodes - changes position of @new to @old position
 * @tree : pointer to the root node of the tree to search
 * @old : pointer to the node to shift off the tree
 * @new : pointer to the node to shift up the tree
 * 
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
