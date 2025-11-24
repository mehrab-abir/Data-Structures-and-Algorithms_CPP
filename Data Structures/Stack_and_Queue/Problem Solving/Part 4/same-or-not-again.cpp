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

class Stack {
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
		Node* deleteNode = tail;

		tail = tail->prev;
		delete deleteNode;

		length--;

		if (tail == NULL) {
			head = NULL;
			return;
		}

		tail->next = NULL;
	}

	int top() {
		return tail->value;
	}

	int size() {
		return length;
	}

	bool empty() {
		return head == NULL;
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

	bool empty() {
		return head == NULL;
	}
};

int main() {
	Stack st;
	Queue q;

	int n, m;
	cout << "Stack size: ";
	cin >> n;
	cout << "Queue size: ";
	cin >> m;

	//stack input
	cout << "Input for stack: " << endl;
	for (int i = 0; i < n; i++) {
		int value;
		cout << "Number " << i + 1 << ": ";
		cin >> value;

		st.push(value);
	}
	
	cout << endl;

	//Queue input
	cout << "Input for queue: " << endl;
	for (int i = 0; i < m; i++) {
		int value;
		cout << "Number " << i + 1 << ": ";
		cin >> value;

		q.push(value);
	}

	cout << endl;

	if (n != m) {
		cout << "NO";
	}
	else {
		int isSame = 1;
		while (!st.empty()) {
			int stackTop = st.top();
			int queueFront = q.front();

			if (stackTop != queueFront) {
				isSame = 0;
				break;
			}
			else {
				st.pop();
				q.pop();
			}
		}

		if (isSame == 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}

	return 0;
}