#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
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

//input
Node* input_for_binary_tree() {
	int value;
	cout << "Enter value for root (-1 for NULL): ";
	cin >> value;

	Node* root;

	if (value == -1) {
		root = NULL;
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

int maxHeight(Node* root) {
	if (root == NULL) {
		return 0;
	}
	//if (root->left == NULL && root->right == NULL) {
	//	return 0; //karon leaf node er height zero dhora hoise,  1 hole ai block lagbei na, tobe return a 1 plus korte hobe
	//}
	//leaf node er height 0 dhorle return korar somoy plus 1 korte hobe
	
	int leftHeight = maxHeight(root->left);
	int rightHeight = maxHeight(root->right);
	return max(leftHeight, rightHeight) + 1; //every time, root nije to 1 height a ase, tai 1 jug kora
	//return korar somoy 1 plus hobe sob somoy, leaf node er height 0 or 1 jetai hok
}

int main() {

	Node* root = input_for_binary_tree();

	int maxTreeHeight = maxHeight(root);

	cout << "Height of the binary tree: " << maxTreeHeight << endl;
	

	return 0;
}
