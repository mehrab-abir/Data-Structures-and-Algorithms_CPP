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

//tree leaf one
void treeLeaf_one(Node* root, vector<int>&leafVector1) {

	if (root == NULL) {
		return;
	}

	treeLeaf_one(root->left, leafVector1);
	treeLeaf_one(root->right, leafVector1);

	//push the root to vector if only it is a leaf node
	if (root->left == NULL && root->right == NULL) {
		leafVector1.push_back(root->value);
	}
}

//tree leaf two
void treeLeaf_two(Node* root, vector<int>&leafVector2) {

	if (root == NULL) {
		return;
	}

	treeLeaf_two(root->left, leafVector2);  //vector passed by referance
	treeLeaf_two(root->right, leafVector2);  //vector passed by referance

	//push the root to vector if only it is a leaf node
	if (root->left == NULL && root->right == NULL) {
		leafVector2.push_back(root->value);
	}

}

//check leaves
bool checkLeaves(vector<int>leafVector1, vector<int>leafVector2) {

	if (leafVector1.size() != leafVector2.size()) {
		return false;
	}
	else {
		for (int i = 0; i < leafVector1.size();i++) {
			if (leafVector1[i] != leafVector2[i]) {
				return false;
			}
		}
		return true;
	}
}

int main() {

	cout << "Input for first binary tree >>> " << endl;
	Node* root1 = input_binary_tree();
	cout << "Input for second binary tree >>> " << endl;
	Node* root2 = input_binary_tree();

	vector<int>leafVector1;
	vector<int>leafVector2;

	treeLeaf_one(root1, leafVector1);
	treeLeaf_two(root2, leafVector2);


	cout << "Leaf vector 1: ";
	for (int v : leafVector1) {
		cout << v << " ";
	}
	cout << "\nLeaf vector 2: ";
	for (int v : leafVector2) {
		cout << v << " ";
	}
	cout << endl;


	bool isLeafSame = checkLeaves(leafVector1, leafVector2);

	if (isLeafSame) {
		cout << "Leaves are same in both binary trees." << endl;
	}
	else {
		cout << "Leaves are different in both binary trees." << endl;
	}

	return 0;
}