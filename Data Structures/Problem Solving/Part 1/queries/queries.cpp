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

void insert_at_head(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	newnode->next = head;
	head->prev = newnode;
	head = newnode;
}

void insert_at_tail(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
	}

	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}


void insert_at_any_position(Node* head, int index, int value) {
	Node* newnode = new Node(value);

	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
	newnode->prev = temp;
}

void print_forward(Node* head) {

	Node* temp = head;

	if (head == NULL) {
		cout << "Linked list is empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void print_backward(Node* tail) {

	Node* temp = tail;

	if (tail == NULL) {
		cout << "Linked list is empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}


int list_length(Node* head) {

	Node* temp = head;
	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}


int main() {

	Node* head = NULL;
	Node* tail = NULL;

	int query;
	cout << "Number of queries: ";
	cin >> query;

	int length = list_length(head);

	for (int q = 0; q < query; q++) {
		int x, v;

		cout << "Enter a value: ";
		cin >> v;

		cout << "Enter index: ";
		cin >> x;

		length = list_length(head);

		if (x > length || x < 0) {
			cout << "Invalid Index" << endl;
		}
		else if (x == 0) {
			insert_at_head(head, tail, v);

			cout << "L -> ";
			print_forward(head);

			cout << "R -> ";
			print_backward(tail);
		}
		else if (x == length) {
			insert_at_tail(head, tail, v);

			cout << "L -> ";
			print_forward(head);

			cout << "R -> ";
			print_backward(tail);
		}
		else {
			insert_at_any_position(head, x, v);

			cout << "L -> ";
			print_forward(head);

			cout << "R -> ";
			print_backward(tail);
		}
	}

	return 0;
}