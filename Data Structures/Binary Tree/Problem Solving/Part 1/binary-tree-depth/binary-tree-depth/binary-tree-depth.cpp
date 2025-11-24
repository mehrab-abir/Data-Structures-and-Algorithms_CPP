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
	cout << endl;

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
		cout << endl;
	}
	cout << endl;
	return root;
}

int treeDepth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	//assuming root node er depth 1


	/*root node er depth 0 dhorle ai extra block rakhte hobe,,,r 1 dhorle -> either return 1 or just omit this
	block */
	/*
	if (root->left == NULL && root->right == NULL) {
		return 0;
	}
	*/
	

	int leftHeight = treeDepth(root->left);
	int rightHeight = treeDepth(root->right);
	return max(leftHeight, rightHeight) + 1;
	//return korar somoy plus 1 kora lagbe, root er depth 0 or 1 jetai hok
}

int main() {

	Node* root = input_binary_tree();

	int height = treeDepth(root);
	cout << "Depth of this binary tree: " << height << endl;

	return 0;
}
