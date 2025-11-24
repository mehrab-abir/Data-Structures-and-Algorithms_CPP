#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/perfect-binary-tree

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

int getMaxDepth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDepth = getMaxDepth(root->left);
	int rightDepth = getMaxDepth(root->right);
	return max(leftDepth , rightDepth) + 1;   //root er nijer depth 1
}

int countNodes(Node* root) {
	if (root == NULL) {
		return 0;
	}

	queue<Node*>q;
	q.push(root);

	int count = 0;

	while (!q.empty()) {
		Node* frontNode = q.front();
		q.pop();

		count++;

		if (frontNode->left) {
			q.push(frontNode->left);
		}
		if (frontNode->right) {
			q.push(frontNode->right);
		}
	}
	return count;
}

int main() {

	Node* root = input_binary_tree();

	int maxDepth = getMaxDepth(root);
	cout << "Max depth = " << maxDepth << endl;

	int numOfNodes = countNodes(root);
	cout << "Number of nodes: " << numOfNodes << endl;

	int nodes = pow(2, maxDepth) - 1;

	if (nodes == numOfNodes) {
		cout << "It's a perfect binary tree" << endl; 
	}
	else {
		cout << "It's not a perfect binary tree." << endl;
	}

	cout << endl;

	return 0;
}