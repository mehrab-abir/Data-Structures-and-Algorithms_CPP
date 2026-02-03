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
		this->left = nullptr;
		this->right = nullptr;
	}
};

//input
Node* input_for_binary_tree() {
	int value;
	cout << "Enter value for root (-1 for NULL): ";
	cin >> value;

	Node* root;

	if (value == -1) {
		root = nullptr;
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
			leftNode = nullptr;
		}
		else {
			leftNode = new Node(leftValue);
		}

		if (rightValue == -1) {
			rightNode = nullptr;
		}
		else {
			rightNode = new Node(rightValue);
		}

		parentNode->left = leftNode;
		parentNode->right = rightNode;

		if (parentNode->left != nullptr) {
			q.push(parentNode->left);
		}
		if (parentNode->right != nullptr) {
			q.push(parentNode->right);
		}
	}
	cout << endl;

	return root;
}

void preorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->value << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	inorder(root->left);
	cout << root->value << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->value << " ";
}


int main() {

	Node* root = input_for_binary_tree();

	cout << "Preorder: ";
	preorder(root);

	cout << endl << endl;

	cout << "Inorder: ";
	inorder(root);

	cout << endl << endl;

	cout << "Postorder: ";
	postorder(root);

	cout << endl << endl;


	return 0;
}
