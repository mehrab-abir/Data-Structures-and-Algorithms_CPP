#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

//https://www.naukri.com/code360/problems/node-level_920383

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

//node level
void nodeLevel(Node* root, int x) {
	
	queue<pair<Node*, int>>q;

	if (root) {
		q.push({ root,1 }); //root er level 1 dhora hoise
	}
	else {
		cout << "Tree is empty" << endl;
		return;
	}

	while (!q.empty()) {
		pair<Node*, int> parent = q.front();
		q.pop();

		Node* node = parent.first;
		int level = parent.second;

		if (node->value == x) {
			cout << "Level of this value: " << level << endl;
			break;
		}

		if (node->left) {
			q.push({ node->left, level + 1 }); //jehetu child node ase, tai child node er level 1 beshi
		}
		if (node->right) {
			q.push({ node->right , level + 1 }); //jehetu child node ase, tai child node er level 1 beshi
		}
	}
}

int main() {
	Node* root = input_binary_tree();

	int number;
	cout << "Enter the value to find its level: ";
	cin >> number;

	nodeLevel(root, number);

	return 0;
}










