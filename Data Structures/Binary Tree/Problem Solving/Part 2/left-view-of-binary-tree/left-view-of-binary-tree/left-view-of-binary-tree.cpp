#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

//https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519

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
		cout << "Root is NULL. Tree is empty" << endl;
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

		int leftChild, rightChild;
		cout << "Enter a value for the left child of " << parentNode->value << " (-1 for NULL): ";
		cin >> leftChild;

		cout << "Enter a value for the right child of " << parentNode->value << " (-1 for NULL): ";
		cin >> rightChild;

		Node* leftNode, * rightNode;

		if (leftChild == -1) {
			leftNode = NULL;
		}
		else {
			leftNode = new Node(leftChild);
		}

		if (rightChild == -1) {
			rightNode = NULL;
		}
		else {
			rightNode = new Node(rightChild);
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

void leftView(Node* root, vector<int>& v) {
	queue<pair<Node*, int>>q;

	if (root) {
		q.push({ root, 1 });
	}
	else {
		cout << "Tree is empty" << endl;
		return;
	}

	int freqArry[5000] = { 0 };

	while (!q.empty()) {
		pair<Node*, int>parent = q.front();
		q.pop();

		Node* node = parent.first;
		int level = parent.second;

		if (freqArry[level] == 0) {
			v.push_back(node->value);
			freqArry[level] = 1;
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

	vector<int>leftViewValues;

	leftView(root, leftViewValues);

	if (root == NULL) {
		cout << "Leftview values: Not Available."<<endl;
	}
	else {
		cout << "Leftview values: ";
		for (int num : leftViewValues) {
			cout << num << " ";
		}
	}

	cout << endl;

	return 0;
}