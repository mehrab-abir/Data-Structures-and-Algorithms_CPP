#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

//https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges/level-nodes-2

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

int depth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);
	return max(leftDepth, rightDepth) + 1;
}

void levelNodes(Node* root, int givenLevel, vector<int>& v) {
	if (root == NULL) {
		return;
	}

	queue<pair<Node*, int>>q;
	q.push({ root, 0 });

	while (!q.empty()) {
		pair<Node*, int>parent = q.front();
		q.pop();

		Node* node = parent.first;
		int level = parent.second;

		if (level == givenLevel) {
			v.push_back(node->value);
		}

		if (node->left) {
			q.push({ node->left , level + 1 });
		}
		if (node->right) {
			q.push({ node->right , level + 1 });
		}
	}
}

int main() {

	Node* root = input_binary_tree();

	int maxLevel = depth(root) - 1;
	cout << "Maximum level = " << maxLevel << endl;

	int level;
	cout << "Enter the level: ";
	cin >> level;

	if (level < 0 || level > maxLevel) {
		cout << "Invalid Level" << endl;
	}
	else {
		vector<int>v;

		levelNodes(root, level, v);

		cout << "All values in level " << level << ": ";
		for (int val : v) {
			cout << val << " ";
		}
	}

	cout << endl;

	return 0;
}