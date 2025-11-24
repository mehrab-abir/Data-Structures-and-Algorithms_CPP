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

Node* convert(vector<int>v, int left, int right) {
	if (left > right) {
		return NULL;
	}

	int mid = (left + right) / 2;
	Node* root = new Node(v[mid]);

	Node* leftSideTree = convert(v, left, mid - 1);
	Node* rightSideTree = convert(v, mid + 1, right);

	root->left = leftSideTree;
	root->right = rightSideTree;

	return root;
}

void level_order(Node* root) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}

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
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>v(n);

	cout << "Input for array [Must be sorted]:" << endl;;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "> ";
		cin >> v[i];
	}

	cout << "\nThe array: ";
	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;

	int left = 0, right = n - 1;

	Node* root = convert(v, left, right);

	cout << "The binary tree: ";
	level_order(root);

	return 0;
}