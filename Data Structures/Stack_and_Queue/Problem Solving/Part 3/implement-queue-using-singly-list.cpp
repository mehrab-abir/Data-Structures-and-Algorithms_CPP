#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};


class Queue {
public:
	Node* head = NULL;
	Node* tail = NULL;

	int length = 0;

	void push(int val) {
		Node* newnode = new Node(val);
		length++;

		if (head == NULL) {
			head = newnode;
			tail = newnode;
			return;
		}

		tail->next = newnode;
		tail = newnode;
	}

	void pop() {
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;

		length--;

		if (head == NULL) {
			tail = NULL;
			return;
		}
	}

	int size() {
		return length;
	}

	int front() {
		return head->val;
	}

	bool empty() {
		return head == NULL;
	}
};
int main() {
	Queue q;

	int n;
	cout << "Queue size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		q.push(val);
	}

	int qSize = q.size();
	cout << "Size = " << qSize << endl;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}
