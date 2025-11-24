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

Node* input_tree() {
	int rootValue;
	cout << "Enter a value for root (-1 for NULL): ";
	cin >> rootValue;

	Node* root;
	if (rootValue == -1) {
		root = NULL;
		cout << "Root is NULL. So tree is empty." << endl;
		return root;
	}
	else {
		root = new Node(rootValue);
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* parent = q.front();
		q.pop();

		int leftValue, rightValue;
		cout << "Enter a value for the left child of " << parent->value << " (-1 for NULL): ";
		cin >> leftValue;
		cout << "Enter a value for the righ child of " << parent->value << " (-1 for NULL): ";
		cin >> rightValue;

		Node* leftChild, * rightChild;

		if (leftValue == -1) {
			leftChild = NULL;
		}
		else {
			leftChild = new Node(leftValue);
		}

		if (rightValue == -1) {
			rightChild = NULL;
		}
		else {
			rightChild = new Node(rightValue);
		}

		parent->left = leftChild;
		parent->right = rightChild;

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

void searchInBST(Node* root, int searchNumber) {
	if (root == NULL) {
		cout << "Not found" << endl;
		return;
	}
	
	if (searchNumber == root->value) {
		cout << "Found" << endl;
		return;
	}

	if (searchNumber < root->value) {
		searchInBST(root->left, searchNumber);
	}
	else {
		searchInBST(root->right, searchNumber);
	}
}

int main() {
	Node* root = input_tree();

	int searchNumber;
	cout << "Search a number: ";
	cin >> searchNumber;

	searchInBST(root, searchNumber);

	cout << endl;

	return 0;
}