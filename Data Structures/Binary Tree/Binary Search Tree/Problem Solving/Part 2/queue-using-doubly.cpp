#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value) {
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

class Queue {
public:
	Node* head = NULL;
	Node* tail = NULL;

	int length = 0;

	void push(int value) {
		Node* newnode = new Node(value);
		length++;

		if (head == NULL) {
			head = newnode;
			tail = newnode;
			return;
		}

		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}

	void pop() {

		if (head == NULL) {
			cout << "Already Empty" << endl;
			return;
		}

		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;

		length--;

		if (head == NULL) {
			tail = NULL;
			return;
		}
		head->prev = NULL;
	}

	int front() {
		return head->value;
	}

	int size() {
		return length;
	}

	int empty() {
		return head == NULL;
	}
};

int main() {
	Queue q;

	cout << "Create a queue >>>" << endl;
	while (true) {
		int value;
		cout << "Value: ";
		cin >> value;

		if (cin.fail()) {
			cout << " !!Invalid input. Enter a valid integer." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (value == -1) {
			break;
		}
		q.push(value);
	}

	int qSize = q.size();
	cout << "Size = " << qSize<< endl;

	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}