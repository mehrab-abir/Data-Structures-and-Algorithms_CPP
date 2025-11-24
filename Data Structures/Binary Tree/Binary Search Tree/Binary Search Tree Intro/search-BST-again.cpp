#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

//https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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

void levelOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* frontNode = q.front();
		q.pop();

		cout << frontNode->value << " ";

		if (frontNode->left) {
			q.push(frontNode->left);
		}
		if (frontNode->right) {
			q.push(frontNode->right);
		}
	}
	cout << endl;
}

Node* searchNum(Node* root, int searchNumber) {
	if (root == NULL) {
		return NULL;
	}
	if (root->value == searchNumber) {
		return root;
	}

	if (searchNumber < root->value) {
		root = searchNum(root->left, searchNumber);
		return root; //will return the subtree rooted with that node
	}
	else {
		root = searchNum(root->right, searchNumber); 
		return root; //will return the subtree rooted with that node
	}
}

int main() {

	Node* root = input_binary_tree();

	int number;
	cout << "Search a number: ";
	cin >> number;

	Node* subTree = searchNum(root, number);
	
	if (subTree != NULL) {
		cout << "\nFound. Subtree rooted with found node: ";
		levelOrder(subTree);
	}
	else {
		cout << "Not found" << endl;
	}
	

	return 0;
}