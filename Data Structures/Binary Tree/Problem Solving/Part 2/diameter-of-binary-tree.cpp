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

int getDiameter(Node* root, int &maxDiameter) {
	if (root == NULL) {
		return 0;
	}

	int leftHeight = getDiameter(root->left, maxDiameter);
	int rightHeight = getDiameter(root->right, maxDiameter);

	int diameter = leftHeight + rightHeight; //diameter through the current node

	maxDiameter = max(maxDiameter, diameter);

	return max(leftHeight, rightHeight) + 1;
	
}

int main() {

	Node* root = input_binary_tree();
	
	int maxDiameter = 0;

	getDiameter(root, maxDiameter); //maxDiameter passed by referance

	cout << "Diameter = " << maxDiameter << endl;

	return 0;
}