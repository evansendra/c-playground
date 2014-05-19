/**
 * tests a simple binary tree implementation
 */
#include <iostream>
#include "bintree.h"

using namespace std;

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
