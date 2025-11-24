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
int leftSum(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int sum = 0;

	if (root->left) {
		sum = sum + root->left->value;
	}

	sum += leftSum(root->left);
	sum += leftSum(root->right);

	return sum;
}

int main() {

	Node* root = input_binary_tree();

	int leftNodesSummation = leftSum(root);

	cout << "Summation of the left nodes: "<<leftNodesSummation<<endl;

	cout << endl;

	return 0;
}