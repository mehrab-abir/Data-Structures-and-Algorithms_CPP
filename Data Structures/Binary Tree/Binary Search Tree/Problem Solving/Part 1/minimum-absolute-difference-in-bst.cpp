#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
	cout << "Enter a value for root (-1 for NULL): ";
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

//min heap
void insert_at_heap(int value, vector<int>& v) {
	v.push_back(value);
	int childIdx = v.size() - 1;

	while (childIdx != 0) {
		int parentIdx = (childIdx - 1) / 2;

		if (v[parentIdx] > v[childIdx]) {
			swap(v[parentIdx], v[childIdx]);
		}
		else {
			break;
		}
		childIdx = parentIdx;
	}
}

//inorder...to sort the tree elements, only works for bst
void in_order(Node* root, vector<int>&v) {
	if (root == NULL) {
		return;
	}

	in_order(root->left, v);
	v.push_back(root->value);
	in_order(root->right, v);
}

int main() {

	Node* root = input_binary_tree();

	vector<int>v;
	vector<int>minHeap;

	in_order(root, v);

	for (int i = 0; i < v.size()-1; i++) {
		int diff = abs(v[i] - v[i + 1]);
		insert_at_heap(diff, minHeap);
	}

	cout << "Minimum absolute difference : " << minHeap.front() << endl;

	return 0;
}



