#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Complete binary tree - All levels starting from L1 to the 2nd last level must be fulfil with nodes
and for the last level, all nodes must be filled up from the left side.
It is not mandatory that the last leaf node must have the right sibling.
*/

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

Node* input_c_binary_tree() {
	int rootValue;
	cout << "Enter a value for the root (-1 for NULL): ";
	cin >> rootValue;

	Node* root;
	if (rootValue == -1) {
		root = NULL;
		cout << "Root is NULL. So tree is empty" << endl;
		return root;
	}
	else {
		root = new Node(rootValue);
	}
	cout << endl;

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* parent = q.front();
		q.pop();

		int leftValue, rightValue;
		cout << "Enter a value for the left child of " << parent->value << "(-1 for NULL): ";
		cin >> leftValue;
		cout << "Enter a value for the right child of " << parent->value << "(-1 for NULL): ";
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

		parent->left = leftNode;
		parent->right = rightNode;

		if (parent->left) {
			q.push(parent->left);
		}
		if (parent->right) {
			q.push(parent->right);
		}
		cout << endl;
	}
	cout << endl;
	return root;
}

void convertToArray(Node* root, vector<int>& v) {
	if (root == NULL) {
		cout << "Tree is empty. Converting not possible." << endl;
		return;
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* frontNode = q.front();
		q.pop();

		v.push_back(frontNode->value);

		if (frontNode->left) {
			q.push(frontNode->left);
		}
		if (frontNode->right) {
			q.push(frontNode->right);
		}
	}
}

int main() {
	cout << "Create a complete binary tree >>>\n" << endl;
	cout << "Enter the following: 1,2,3,4,5,6,-1,-1,-1,-1,-1,-1,-1" << endl;

	Node* root = input_c_binary_tree();

	vector<int>v;

	convertToArray(root, v);

	cout << "After converting the complete binary to an array: ";
	for (int num : v) {
		cout << num << " ";
	}

	cout << endl;

	return 0;
}