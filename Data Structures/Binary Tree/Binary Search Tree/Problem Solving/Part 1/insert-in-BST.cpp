#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

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
	cout << "Enter a value for root (-1 for NULL): ";
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
		cout << "Enter a value for the left child of " << parentNode->value << " (-1 for NULL): ";
		cin >> leftValue;

		cout << "Enter a value for the right child of " << parentNode->value << " (-1 for NULL): ";
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

void level_order(Node* root) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}

	cout << "Level order: ";

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		cout << front->value << " ";

		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
	}
	cout << endl;
}

void insert_in_BST(Node* root, int value) {
	if (root == NULL) {
		root = new Node(value);
		return;
	}

	if (value < root->value) {
		if (root->left == NULL) {
			root->left = new Node(value);
		}
		else {
			insert_in_BST(root->left, value);
		}
	}
	else if (value > root->value) {
		if (root->right == NULL) {
			root->right = new Node(value);
		}
		else {
			insert_in_BST(root->right, value);
		}
	}
	else {
		cout << "\tNew value can not be equal to any existing value." << endl;
		return;
	}
}

int main() {

	Node* root = input_binary_tree();

	level_order(root);

	int value;
	cout << "Enter a number to insert: ";
	cin >> value;

	insert_in_BST(root, value);

	cout << "After inserting " << value << ", ";
	level_order(root);

	return 0;
}












