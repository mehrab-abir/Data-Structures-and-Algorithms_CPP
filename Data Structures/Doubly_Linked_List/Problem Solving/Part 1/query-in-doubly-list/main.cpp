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

void insert_at_head(Node*& head, Node* &tail, int value) {
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
		return;
	}

	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}

void insert_at_middle(Node*& head, int index, int value) {
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

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void print_backward(Node* tail) {
	Node* temp = tail;

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

	for (int i = 0; i < query; i++) {
		int index, value;

		cout << "Enter a value: ";
		cin >> value;

		cout << "Enter index: ";
		cin >> index;

		int length = list_length(head);

		if (index == 0) {
			insert_at_head(head, tail, value);
			
			cout << "The linked list : " << endl;
			cout << "Forward: ";
			print_forward(head);

			cout << "Backward: ";
			print_backward(tail);
		}
		else if (index == length) {
			insert_at_tail(head, tail, value);

			cout << "The linked list : " << endl;
			cout << "Forward: ";
			print_forward(head);

			cout << "Backward: ";
			print_backward(tail);
		}
		else if (index > 0 && index < length) {
			insert_at_middle(head, index, value);

			cout << "The linked list : " << endl;
			cout << "Forward: ";
			print_forward(head);

			cout << "Backward: ";
			print_backward(tail);
		}
		else {
			cout << "Invalid index" << endl;
		}
	}

	return 0;
}