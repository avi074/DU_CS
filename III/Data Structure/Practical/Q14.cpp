#include <iostream>
#include "STL/bst.hpp"

using namespace std;
using namespace stl;

void traverse(const BST<int>& b)
{
	cout << "\n Iterative Version :\n";
	cout << "\n Inorder Traversal     : ";
	b.in_trav();
	cout << "\n Pre-order Traversal   : ";
	b.pre_trav(); 
	cout << "\n Post-order Traversal  : ";
	b.post_trav();
	cout << "\n Level-order Traversal : ";
	b.level_trav();

	cout << "\n\n Recursive Version :\n";
	cout << "\n Inorder Traversal     : ";
	in_DFT(b.getRoot());
	cout << "\n Pre-order Traversal   : ";
	pre_DFT(b.getRoot());
	cout << "\n Post-order Traversal  : ";
	post_DFT(b.getRoot());
	cout << "\n Level-order Traversal : ";
	BFT(b.getRoot());
}

int main()
{
	BST<int> b, b1{5,7,9};
	cout << "\n\t Practical 14\n";
	cout << "\n Binary Search Trees\n";

	cout << "\n Inserting 8,1 in Tree using recursion : ";
	b.insert_r(8);
	b.insert_r(1);
	cout << "\n b = ";
	b.pre_trav();
	cout << "\n Inserting 10,9,11,2,5 in Tree using iteration : ";
	b += {10,9,11,2,5};
	cout << "\n b = ";
	b.pre_trav();

	cout << "\n\n Deletion of 9 via merging : \n b = ";
	b.del_merge(9);
	b.pre_trav();
	cout << "\n Deletion of 11 by copying : \n b = ";
	b.del_copy(11);
	b.pre_trav();

	cout << "\n\n Height of tree   : " << height(b.getRoot());
	int n = countLeaf(b.getRoot());
	cout << "\n Total Node Count : " << b.nodes_len();
	cout << "\n Leaf Node Count  : " << n;
	cout << "\n Non Leaf Count   : " << b.nodes_len() - n;

	cout << "\n\n Traversal of Binary Search Tree b : \n";
	traverse(b);

	cout << "\n\n Binary Search Tree b \t : ";
	b.in_trav();
	b.mirror();
	cout << "\n Mirror of Binary Tree b : ";
	b.in_trav();
	b.mirror();

	cout << "\n\n Binary Search Trees : \n b  : ";
	b.in_trav();
	cout << "\n b1 : ";
	b1.in_trav();
	cout << "\n (b == b1)  : " << boolalpha << (b == b1) << "\n\n";
}