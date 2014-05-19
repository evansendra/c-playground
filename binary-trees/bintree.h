#ifndef EAS_BINTREE_H
#define EAS_BINTREE_H

#include <iomanip>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

/*
 * defines a simple binary tree with ops insert,
 * search, destroyTree, and remove
 */

/**
 * the general structure for a tree
 */
struct node
{
	int value;
	node *p_left;
	node *p_right;
};

node* insert (node *p_tree, int key);
node* search (node *p_tree, int key);
void destroy_tree (node *p_tree);
node* remove (node *p_tree, int key);
void print_tree (node *p_tree);
unsigned count_nodes (node *p_tree);

#endif /* EAS_BINTREE_H */