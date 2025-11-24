#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

//https://www.naukri.com/code360/problems/code-find-a-node_5682

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;

	}
};

//input
Node* input_binary_tree() {
	int rootValue;
	cout << "Enter a value for root: ";
	cin >> rootValue;

	Node* root;

	if (rootValue == -1) {
		root = NULL;
		cout << "Root is NULL. Tree is empty." << endl;
		return root;
	}
	else {
		root = new Node(rootValue);
	}

	cout << endl;

	queue<Node*>q;

	q.push(root);

	while (!q.empty()) {
		Node* parentNode = q.front();
		q.pop();

		int leftValue, rightValue;
		cout << "Enter a value for the left child of " << parentNode->value << ": ";
		cin >> leftValue;

		cout << "Enter a value for the right child of " << parentNode->value << ": ";
		cin >> rightValue;

		Node* leftNode, * rightNode;

		if (leftValue == -1) {
			leftNode = NULL;
		}
		else {
			leftNode = new Node(leftValue);
		}

		if (rightValue == -1) {
			rightNode = NULL;
		}
		else {
			rightNode = new Node(rightValue);
		}

		parentNode->left = leftNode;
		parentNode->right = rightNode;

		if (parentNode->left) {
			q.push(parentNode->left);
		}
		if (parentNode->right) {
			q.push(parentNode->right);
		}
		cout << endl;
	}
	cout << endl;
	return root;
}

//print
void preorder(Node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->value<<" ";
	preorder(root->left);
	preorder(root->right);
}

//search
bool isNodePresent(Node* root, int x) {
	if (root == NULL) {
		return false;
	}

	if (root->value == x) {
		return true;
	}
	bool leftSearch = isNodePresent(root->left, x);
	bool rightSearch = isNodePresent(root->right, x);

	if (leftSearch == true || rightSearch == true) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	Node* root = input_binary_tree();

	cout << "Preorder: ";
	preorder(root);

	cout << endl;

	int x;
	cout << "Search a number: ";
	cin >> x;

	bool searchNode = isNodePresent(root, x);

	if (searchNode) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	cout << endl;

	return 0;
}
