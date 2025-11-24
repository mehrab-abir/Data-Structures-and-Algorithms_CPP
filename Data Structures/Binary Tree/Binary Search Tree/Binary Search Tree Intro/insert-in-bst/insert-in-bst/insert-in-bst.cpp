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
		this->left = nullptr;
		this->right = nullptr;
	}
};

Node* input_binary_tree() {
	int rootValue;
	cout << "Enter a value for root (-1 for nullptr): ";
	cin >> rootValue;

	Node* root;

	if (rootValue == -1) {
		root = nullptr;
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
		cout << "Enter a value for the left child of " << parent->value << "(-1 for nullptr): ";
		cin >> leftValue;
		cout << "Enter a value for the right child of " << parent->value << "(-1 for nullptr): ";
		cin >> rightValue;

		Node* leftChild, * rightChild;

		if (leftValue == -1) {
			leftChild = nullptr;
		}
		else {
			leftChild = new Node(leftValue);
		}

		if (rightValue == -1) {
			rightChild = nullptr;
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

void insertNumber(Node* &root, int val) {
	if (root == nullptr) {
		root = new Node(val);
		return;
	}

	if (val < root->value) {
		if (root->left == nullptr) {
			root->left = new Node(val);
		}
		else {
			insertNumber(root->left, val);
		}
	}
	else if(val > root->value){
		if (root->right == nullptr) {
			root->right = new Node(val);
		}
		else {
			insertNumber(root->right, val);
		}
	}
	else {
		cout << "New value can not be eqaul to any existing value" << endl;
		return;
	}
}

void levelOrder(Node* root) {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
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

//1 node insert korar complexity O(H) >> H = height
// n ti node insert korar complexity O(NH)

int main() {

	Node* root = input_binary_tree();
	levelOrder(root);

	int number;
	cout << "Insert a number: ";
	cin >> number;

	insertNumber(root, number);
	
	cout << "\nAfter inserting " << number << ", Binary Search tree : ";
	levelOrder(root);

	return 0;
}