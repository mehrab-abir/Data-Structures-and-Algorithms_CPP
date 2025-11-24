#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

//https://www.naukri.com/code360/problems/special-binary-tree_920502?leftPanelTabValue=PROBLEM

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

//level order traversal method
bool isSpecialTree(Node* root) {

	//if tree is empty
	if (root == NULL) {
		cout << "Tree is empty. ";
		return false;
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* frontNode = q.front();
		q.pop();

		if (frontNode->left != NULL && frontNode->right == NULL) {
			return false;
		}
		if (frontNode->left == NULL && frontNode->right != NULL) {
			return false;
		}

		if (frontNode->left) {
			q.push(frontNode->left);
		}
		if (frontNode->right) {
			q.push(frontNode->right);
		}
	}
	return true;
}

//using recursion
bool isSpecial(Node* root) {
	if (root == NULL) {
		return true;
	}

	if (root->left == NULL && root->right != NULL) {
		return false;
	}
	if (root->left != NULL && root->right == NULL) {
		return false;
	}

	bool leftSubtree = isSpecial(root->left);
	bool rightSubtree = isSpecial(root->right);

	return leftSubtree && rightSubtree;
}


int main() {

	Node* root = input_binary_tree();

	//bool special = isSpecialTree(root);

	//using recursion
	bool special = isSpecial(root);

	if (special) {
		cout << "It's special" << endl;
	}
	else {
		cout << "Not special" << endl;
	}


	return 0;
}