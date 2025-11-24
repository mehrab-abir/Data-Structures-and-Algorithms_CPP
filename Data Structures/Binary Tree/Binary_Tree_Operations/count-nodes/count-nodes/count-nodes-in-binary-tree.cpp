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
Node* input_for_binary_tree() {
	int value;
	cout << "Enter value for root (-1 for NULL): ";
	cin >> value;

	Node* root;

	if (value == -1) {
		root = NULL;
		cout << "Root is NULL. Tree is empty." << endl;
		return root;
	}
	else {
		root = new Node(value);
	}

	queue<Node*>q;

	q.push(root);

	while (!q.empty()) {
		Node* parentNode = q.front();
		q.pop();

		cout << endl;

		int leftValue, rightValue;
		
		cout << "Value for the left child of " << parentNode->value << ": ";
		cin >> leftValue;
		cout << "Value for the right child of " << parentNode->value << ": ";
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

		if (parentNode->left != NULL) {
			q.push(parentNode->left);
		}
		if (parentNode->right != NULL) {
			q.push(parentNode->right);
		}
	}
	cout << endl;

	return root;
}

//count nodes- using recursion
int count_nodes(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftCount = count_nodes(root->left);
	int rightCount = count_nodes(root->right);
	return leftCount + rightCount + 1; //1 root er nijer jonno
}

int main() {

	Node* root = input_for_binary_tree();

	int numberOfNodes = count_nodes(root);
	cout << "Number of nodes in this binary tree: " << numberOfNodes << endl;

	return 0;
}
