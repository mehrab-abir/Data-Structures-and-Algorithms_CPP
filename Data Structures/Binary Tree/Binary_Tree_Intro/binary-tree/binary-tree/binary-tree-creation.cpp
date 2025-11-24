#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "binary-tree.h"

using namespace std;

int main() {
	Node* root = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* c = new Node(40);
	Node* d = new Node(50);
	Node* e = new Node(60);

	root->left = a;
	root->right = b;
	a->left = c;
	b->left = d;
	b->right = e;

	cout << "Pre-order traversal: ";
	preorder(root);

	cout << endl;

	cout << "Post-order traversal: ";
	postorder(root);

	cout << endl;

	cout << "In-order traversal: ";
	inorder(root);

	cout << endl;

	return 0;
}
