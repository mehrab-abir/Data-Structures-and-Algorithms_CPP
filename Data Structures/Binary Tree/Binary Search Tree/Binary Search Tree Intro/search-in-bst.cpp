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

Node* input_binary_tree() {
	int rootValue;
	cout << "Enter a value for root (-1 for NULL): ";
	cin >> rootValue;

	Node* root;

	if (rootValue == -1) {
		root = NULL;
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

bool searchNum(Node* root, int searchNumber) {
	if (root == NULL) {
		return false;
	}
	if (root->value == searchNumber) {
		return true;
	}

	if (searchNumber < root->value) {
		return searchNum(root->left, searchNumber);  //will return true or false
	}
	else {
		return searchNum(root->right, searchNumber); //will return true or false
	}
}

//Complexity of search operation in Binary Search Tree is O(H) > H = Height of the tree

int main() {

	Node* root = input_binary_tree();

	int number;
	cout << "Search a number: ";
	cin >> number;

	bool searchResult = searchNum(root, number);

	if (searchResult) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;
}