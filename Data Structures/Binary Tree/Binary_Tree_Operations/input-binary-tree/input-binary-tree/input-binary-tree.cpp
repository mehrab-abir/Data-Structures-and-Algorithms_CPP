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
		this->left = NULL;
		this->right = NULL;
	}
};

//input for binary tree - - - follows level order traversal process
Node* binary_tree_input() {
	int val;
	cout << "Enter root value (-1 for NULL): ";
	cin >> val;

	Node* root;

	//jodi shurutei root er value null deya hoy
	if (val == -1) {
		root = NULL;
		cout << "Root is NULL. Tree is empty." << endl;
		return root;
	}
	else {
		root = new Node(val);
	}

	queue<Node*>q;

	q.push(root);

	while (!q.empty()) {
		//Step 1: Node ber kore ana
		Node* parentNode = q.front();
		q.pop();

		cout << endl;

		//Step 2: Oi node niye kaj kora,,akhane input newa...
		int leftValue, rightValue;
		cout << "Enter the value for the left child of " << parentNode->value << ": ";
		cin >> leftValue;

		cout << "Enter the value for the right child of " << parentNode->value << ": ";
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

		//connecting newly created nodes with their parent node
		parentNode->left = leftNode;
		parentNode->right = rightNode;

		//Step 3: Queue te parent node er children push kora
		if (parentNode->left != NULL) {
			q.push(parentNode->left);
		}
		if (parentNode->right != NULL) {
			q.push(parentNode->right);
		}

	}
	cout << endl;

	return root;
}

//printing binary tree- using level order traversal
void levelorder(Node* root) {

	//root null thakle
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return; 
	}

	queue<Node*>q;

	q.push(root);

	while (!q.empty()) {

		//1. Node ber kore ana
		Node* qFront = q.front();
		q.pop();

		//2. Oi node niye kaj kora
		cout << qFront->value << " ";

		//3. Children push kora
		if (qFront->left != NULL) {
			q.push(qFront->left);
		}
		if (qFront->right != NULL) {
			q.push(qFront->right);
		}
	}
}


int main() {
	
	Node* root = binary_tree_input();

	cout << "Level order traversal: ";
	levelorder(root);

	cout << endl;

	return 0;
}