#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

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
	}
	cout << endl;
	return root;
}

//print binary tree
void postorder(Node* root) {
	if (root == NULL) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->value << " ";
}

//pushing to a vector
void pushToVector(Node* root, vector<int>&v ) {

	if (root == NULL) {
		return;
	}

	pushToVector(root->left, v);
	pushToVector(root->right, v);
	v.push_back(root->value);
}

int main() {

	Node* root = input_binary_tree();

	cout << "Post order traversal: ";
	postorder(root);

	cout << endl;

	vector<int>treeVector;

	pushToVector(root, treeVector);
	
	cout << "In vector: ";
	for (int num : treeVector) {
		cout << num << " ";
	}
	
	cout << endl;

	return 0;
}
