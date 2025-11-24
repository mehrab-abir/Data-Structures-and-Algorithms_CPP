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


void levelOrder(Node* root) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		return;
	}

	queue<Node*>q;
	q.push(root);

	while (!q.empty()) {
		Node* frontNode = q.front();
		q.pop();

		cout << frontNode->value << " ";

		if (frontNode->left) {
			q.push(frontNode->left);
		}
		if (frontNode->right) {
			q.push(frontNode->right);
		}
	}
	cout << endl;
}

Node* convertToBST(vector<int>arr, int left, int right) {

	if (left > right) {
		return NULL;
	}
	int mid = (left + right) / 2;

	Node* root = new Node(arr[mid]);

	Node * leftSide = convertToBST(arr, left, mid - 1);
	Node* rightSide = convertToBST(arr, mid + 1, right);

	root->left = leftSide;
	root->right = rightSide;

	return root;

}

int main() {

	int n;
	cout << "Size of array: ";
	cin >> n;

	vector<int>arr(n);

	cout << "Input for array (must be sorted) : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> arr[i];
	}
	cout << endl;

	int left = 0, right = n - 1; //left = left most index of array, right = right most index of array

	Node* root = convertToBST(arr, left, right);

	cout << "Binary Search Tree from this array: ";
	levelOrder(root);

	return 0;
}
