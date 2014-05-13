/**
 * implements a simple binary tree with insert, search, 
 * destroyTree, and remove
 *
 * EAS
 */
#include <iomanip>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct node
{
	int value;
	node *p_left;
	node *p_right;
};

node* insert (node *p_tree, int key)
{
	if (p_tree == NULL)
	{
		node *p_new_tree = new node;
		p_new_tree->value = key;
		p_new_tree->p_left = p_new_tree->p_right = NULL;
		return p_new_tree;
	}	

	if (key < p_tree->value)
	{
		p_tree->p_left = insert(p_tree->p_left, key);
	}
	else if (key > p_tree->value)
	{
		p_tree->p_right = insert(p_tree->p_right, key);
	}

	return p_tree;
}

node* search (node *p_tree, int key)
{
	if (p_tree == NULL)
		return p_tree;

	if (key < p_tree->value)
		return search(p_tree->p_left, key);
	else if (key > p_tree->value)
		return search(p_tree->p_right, key);
	else
		return p_tree;
}

/*
 * less elegant
 *
void destroy_tree (node *p_tree)
{
	if (p_tree->p_left != NULL) 
		destroy_tree(p_tree->p_left);
	if (p_tree->p_right != NULL)
		destroy_tree(p_tree->p_right);
	delete p_tree;
}
*/

void destroy_tree (node *p_tree)
{
	if (p_tree != NULL)
	{
		destroy_tree(p_tree->p_left);
		destroy_tree(p_tree->p_right);
		// cout << "Deleting node: " << p_tree->value << endl;
		delete p_tree;
	}
}

/**
 * finds the maximum node in the given p_tree, which is 
 * the rightmost child in the tree
 */
node* find_max (node *p_tree)
{
	if (p_tree == NULL)
		return p_tree;

	if (p_tree->p_right == NULL)
		return p_tree;

	return find_max(p_tree->p_right);
}

/**
 * returns this tree, less the rightmost, "greatest", node. The
 * rightmost node is replaced with its left child if it exists
 * else NULL 
 */
node* remove_max_node (node *p_tree, node *p_max_node)
{
	// base case: the passed in tree is NULL, so just return NULL
	if (p_tree == NULL)
		return p_tree;

	// base case: found the node, now replace it with left guy
	if (p_tree == p_max_node)
	{
		return p_max_node->p_left;
	}	

	p_tree->p_right = remove_max_node (p_tree->p_right, p_max_node);

	return p_tree;
}

/**
 * returns this tree, less the node containing key, if it 
 * exists, else the tree is identical
 */
node* remove (node *p_tree, int key)
{
	if (p_tree == NULL)
	{
		return p_tree;
	}

	if (key > p_tree->value)
	{
		p_tree->p_right = remove(p_tree->p_right, key);
	}
	else if (key < p_tree->value)
	{
		p_tree->p_left = remove(p_tree->p_left, key);
	}
	else
	{
		// case 1: just a right child, replaces current node
		if (!p_tree->p_left)
		{
			node *p_right_subtree = p_tree->p_right;
			delete p_tree;
			return p_right_subtree;
		}

		// case 2: just a left child, replaces current node
		if (!p_tree->p_right)
		{
			node *p_left_subtree = p_tree->p_left;
			delete p_tree;
			return p_left_subtree;
		}

		// case 3: two children, we need to find the maximum node 
		// of the right child and use it to replace the current node,
		// replacing it with its left children, if they exist
		node *p_max_node = find_max(p_tree->p_left);
		p_max_node->p_left = remove_max_node(p_tree->p_left, p_max_node);
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}

	return p_tree;
}

void print_tree_helper (node *p_tree, unsigned level)
{
	if (p_tree == NULL)
		return;

	cout << setw(2*level + std::to_string(level).length()) << 
		setfill('-') << p_tree->value << endl;
	print_tree_helper (p_tree->p_left, level + 1);
	print_tree_helper (p_tree->p_right, level + 1);
}

void print_tree (node *p_tree)
{
	cout << endl;
	print_tree_helper (p_tree, 0);
	cout << endl;
}

unsigned count_nodes (node *p_tree)
{
	unsigned n_nodes = 0;
	if (p_tree != NULL)
	{
		n_nodes = 1 + 
			count_nodes(p_tree->p_left) +
			count_nodes(p_tree->p_right);
	}
	return n_nodes;
}

int main(void)
{
	node *tree = insert(NULL, 10);
	tree = insert(tree, 6);
	tree = insert(tree, 14);
	tree = insert(tree, 5);
	tree = insert(tree, 8);
	tree = insert(tree, 11);
	tree = insert(tree, 18);

	// report if we find the following values
	cout << "T: " << (search(tree, 6) != NULL) << endl; 
	cout << "F: " << (search(tree, 17) != NULL) << endl; 
	cout << "F: " << (search(tree, -1) != NULL) << endl; 
	cout << "T: " << (search(tree, 18) != NULL) << endl; 
	cout << "T: " << (search(tree, 5) != NULL) << endl;

	print_tree(tree);
	cout << count_nodes(tree) << endl;

	// delete some values in our tree
	tree = remove(tree, 14);
	print_tree(tree);
	cout << count_nodes(tree) << endl;
	tree = remove(tree, 14);
	print_tree(tree);
	cout << count_nodes(tree) << endl;
	tree = remove(tree, 10);
	print_tree(tree);
	cout << count_nodes(tree) << endl;
	tree = remove(tree, -220);
	print_tree(tree);
	cout << count_nodes(tree) << endl;

	cout << count_nodes(NULL) << endl;

	destroy_tree(tree);

	return 0;
}