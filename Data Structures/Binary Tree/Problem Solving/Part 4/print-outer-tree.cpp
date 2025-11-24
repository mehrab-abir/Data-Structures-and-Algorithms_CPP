#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<stack>
#include<vector>

//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/print-outer-tree

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
		cout << "Root is NULL." << endl;
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

		parentNode->left = leftChild;
		parentNode->right = rightChild;

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

queue<int>leftSideNodes(Node* root) {
	queue<int>q;

	Node* temp = root;

	if (temp == NULL) {
		return q;
	}

	stack<int>st;
	while (temp != NULL) {
		st.push(temp->value);
		if (temp->left) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}

	while (!st.empty()) {
		q.push(st.top());
		st.pop();
	}
	return q;
}

queue<int>rightSideNodes(Node* root) {
	queue<int>q;

	Node* temp = root;

	if (temp == NULL) {
		return q;
	}

	while (temp != NULL) {
		q.push(temp->value);
		if (temp->right) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return q;
}

void outerTree(Node* root) {
	if (root == NULL) {
		return;
	}

	queue<int> leftNodes = leftSideNodes(root);
	queue<int> rightNodes = rightSideNodes(root);

	while (!leftNodes.empty()) {
		cout << leftNodes.front() << " ";
		leftNodes.pop();
	}
	
	rightNodes.pop();

	while (!rightNodes.empty()) {
		cout << rightNodes.front() << " ";
		rightNodes.pop();
	}
	cout << endl;
}

int main() {

	Node* root = input_binary_tree();

	outerTree(root);

	cout << endl;

	return 0;
}
