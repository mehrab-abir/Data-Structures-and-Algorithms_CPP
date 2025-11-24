#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "binary-tree.h"

using namespace std;

Node::Node(int value) {
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

//left- root - right
void inorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	inorder(root->left);
	cout << root->value<<" ";
	inorder(root->right);
}

//root - left - right
void preorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->value << " ";
	preorder(root->left);
	preorder(root->right);
}

//left - right - root
void postorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->value << " ";
}