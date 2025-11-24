#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

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

void increasingOrder(Node *&root, int value) {
	if (root == NULL) {
		root = new Node(value);
		return;
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* parent = q.front();
		q.pop();

		//find the leaf node anf then insert new node
		if (parent->left == NULL && parent->right == NULL) {
			Node* newnode = new Node(value);
			parent->right = newnode;
			parent->left = NULL; //left child will be NULL for all nodes
			
			/*newnode->left = NULL; //these two lines are not necessary
			newnode->right = NULL;*/
			return;
		}

		if (parent->right) {
			q.push(parent->right);
		}
	}
}

void in_order(Node* root, Node* &increasingOrderRoot) {
	if (root == NULL) {
		return;
	}

	in_order(root->left, increasingOrderRoot);
	increasingOrder(increasingOrderRoot, root->value);
	in_order(root->right, increasingOrderRoot);
}


void level_order(Node* root) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}

	cout << "Level order of increasing order tree: ";

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		cout << front->value << " ";

		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
	}
	cout << endl;
}

int main() {

	Node* root = input_binary_tree();
	Node* increasingOrderRoot = NULL;

	in_order(root, increasingOrderRoot);

	level_order(increasingOrderRoot);

	return 0;
}












