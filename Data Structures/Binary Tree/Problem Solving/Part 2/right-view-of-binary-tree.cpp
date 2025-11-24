#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

//https://leetcode.com/problems/binary-tree-right-side-view/description/

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


void rightView(Node* root, vector<int>& v) {
	
	queue<pair<Node*, int>>q;
	int freqArr[500] = { 0 };

	if (root) {
		q.push({ root, 1 });
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

		if (freqArr[level] == 0) {
			v.push_back(node->value);
			freqArr[level] = 1;
		}

		if (node->right) {
			q.push({ node->right, level + 1 });
		}
		if (node->left) {
			q.push({ node->left , level + 1 });
		}
	}
}

int main() {

	Node* root = input_binary_tree();

	vector<int>v;

	rightView(root, v);

	cout << "Right view of this binary tree: ";
	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
