#define CRT_SECURE_NO_WARNINGS
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



int getSum(Node* root) {
	if (root == NULL) {
		return 0;
	}

	queue<Node*>q;
	q.push(root);

	int sum = 0;

	while (!q.empty()) {
		Node* parent = q.front();
		q.pop();

		if (parent->left != NULL || parent->right != NULL) {
			sum += parent->value;
		}

		if (parent->left) {
			q.push(parent->left);
		}
		if (parent->right) {
			q.push(parent->right);
		}
	}
	return sum;
}


//recrsive approach
int getSumRecursive(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int sum = 0;

	if (root->left != NULL || root->right != NULL) {
		sum += root->value;
	}


	sum += getSumRecursive(root->left);
	sum += getSumRecursive(root->right);
	return sum;
}


int main() {

	Node* root = input_binary_tree();

	int sumWithoutLeaf = getSum(root);
	int sumRecursive = getSumRecursive(root);
	cout << "Summation of all nodes except leaf nodes: "<<sumWithoutLeaf<<endl;
	cout << "Summation of all nodes except leaf nodes: "<<sumRecursive<<endl;

	return 0;
}