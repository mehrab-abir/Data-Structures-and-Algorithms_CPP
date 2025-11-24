#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

//print the outer tree of a binary tree, not left view nad right view, just outer tree
//left children of each nodes and right children of each nodes

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
		cout << "Root is NULL. So tree is empty." << endl;
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

//print left nodes
void leftNodes(Node* root, queue<int>&q) {
	Node* temp = root;

	if (temp == NULL) {
		cout << "Tree is empty." << endl;
		return;
	}

	stack<int>st;

	st.push(temp->value);

	if (temp->left) {
		leftNodes(temp->left, q);
	}
	else if (temp->right) {
		leftNodes(temp->right, q);
	}

	while (!st.empty()) {
		q.push(st.top());
		st.pop();
	}
}

//print right nodes
void rightNodes(Node* root, queue<int>&q) {
	Node* temp = root;

	if (temp == NULL) {
		cout << "Tree is empty." << endl;
		return;
	}

	q.push(temp->value);

	if (temp->right) {
		rightNodes(temp->right, q);
	}
	else if (temp->left) {
		rightNodes(temp->left, q);
	}
}

int main() {

	cout << "Input for binary tree >>> " << endl;
	Node* root = input_binary_tree();

	queue<int>leftQ;
	queue<int>rightQ;

	if (root->left && root->right ) {
		leftNodes(root, leftQ);
		rightNodes(root, rightQ);
	}
	else if (root->left != NULL && root->right == NULL) {
		leftNodes(root, leftQ);
	}
	else if (root->left == NULL && root->right != NULL) {
		rightNodes(root, rightQ);
	}
	

	while (!leftQ.empty()) {
		cout << leftQ.front() << " ";
		leftQ.pop();
	}

	if (root->left != NULL && root->right != NULL) {
		rightQ.pop();
	}
	
	//to remove duplicate node, as first root appears twice, which goes in front of the rightQ
	while (!rightQ.empty()) {
		cout << rightQ.front() << " ";
		rightQ.pop();
	}

	cout << endl;

	return 0;
}