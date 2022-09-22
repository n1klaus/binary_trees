#include "binary_trees.h"
/**
 * shiftNodes - changes position of @new to @old position
 * @tree : pointer to the root node of the tree to search
 * @old : pointer to the node to shift off the tree
 * @new : pointer to the node to shift up the tree
 * 
 * Return: Nothing
 */
void shiftNodes(binary_tree_t *tree, binary_tree_t *old, 
			  binary_tree_t *new)
{
	if (new != NULL)
		new->parent = old->parent;

	if (old->parent == NULL && tree != NULL)
		tree = new;
	else if (old == old->parent->left)
		old->parent->left = new;
	else if (old == old->parent->right)
		old->parent->right = new;
}

/**
 * getMinimum - look at all nodes on the left branches
 * from the starting position with the smallest value
 * @node : pointer to the node to start the search from
 * 
 * Return: node with smaller value than @node
 */
binary_tree_t *getMinimum(binary_tree_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);		
}

/**
 * getSuccessor - look for a node with value larger than @node
 * @node : pointer to the node to start the search from
 * 
 * Return: Next node with value larger than @node
 */
binary_tree_t *getSuccessor(binary_tree_t *node)
{
	binary_tree_t *parentNode = NULL;

	if (node->right != NULL)
		node = getMinimum(node->right);

	parentNode = node->parent;
	while (parentNode != NULL)	
	{
		node = parentNode->right;
		if (node != NULL)
			parentNode = node;
		else
			break;
	}
	return (parentNode);	
}

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree : pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tempNode = NULL, *currNode = NULL;

	if (tree == NULL)
		return;

	currNode = tree;
	while (currNode != NULL)
	{
		if (currNode->left == NULL)
			shiftNodes(tree, currNode, currNode->right);
		else if (currNode->right == NULL)
			shiftNodes(tree, currNode, currNode->left);
		else
		{
			tempNode = getSuccessor(currNode);
			if (tempNode->parent != currNode)
			{
				shiftNodes(tree, tempNode, tempNode->right);
				tempNode->right = currNode->right;
				tempNode->right->parent = tempNode;
			}
			shiftNodes(tree, currNode, tempNode);
			tempNode->left = currNode->left;
			tempNode->left->parent = tempNode;
		}
	}
}
