#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/leaf-similar-trees/description/

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

bool checkSimilarity(Node* root1, Node* root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	if (root1 == NULL || root2 == NULL) {
		return false;
	}

	if (root1->value != root2->value) {
		return false;
	}

	bool leftSubTree = checkSimilarity(root1->left, root2->left);
	bool rightSubTree = checkSimilarity(root1->right, root2->right);

	return leftSubTree && rightSubTree;
}

int main() {

	cout << "Input for first binary tree >>> " << endl;
	Node* root1 = input_binary_tree();
	cout << "Input for second binary tree >>> " << endl;
	Node* root2 = input_binary_tree();

	bool areTreesSimilar = checkSimilarity(root1, root2);

	if (areTreesSimilar) {
		cout << "Both trees are similar" << endl;
	}
	else {
		cout << "Trees are different" << endl;
	}

	return 0;
}