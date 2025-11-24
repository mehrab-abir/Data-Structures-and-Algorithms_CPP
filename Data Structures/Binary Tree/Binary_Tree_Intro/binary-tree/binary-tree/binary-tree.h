#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Node {
public :
	int value;
	Node* left;
	Node* right;

	Node(int value);
};

void inorder(Node* root);

void preorder(Node* root);

void postorder(Node* root);

#endif // BINARY_TREE_H