#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
};

void insert_at_head(Node*& head, Node *&tail, int value) {
	Node* newnode = new Node(value);

	newnode->next = head;
	head = newnode;

	if (tail == NULL) {
		tail = head;
	}
}

void insert_at_tail(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
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

void delete_at_any_position(Node*& head, Node*& tail, int index) {
	if (index == 0) { // Delete head
		Node* deleteNode = head;
		head = head->next;
		if (head == NULL) {
			tail = NULL;
		}
		delete deleteNode;
		return;
	}

	Node* temp = head;
	int length = list_length(head);

	if (index == length - 1) { // Delete tail
		while (temp->next != tail) {
			temp = temp->next;
		}
		Node* deleteNode = tail;
		temp->next = NULL;
		tail = temp;
		delete deleteNode;
		return;
	}

	// Delete at middle
	for (int i = 1; i < index; i++) {
		if (temp->next == NULL) {
			return;
		}
		temp = temp->next;
	}

	Node* deleteNode = temp->next;
	if (deleteNode == NULL) {
		return;
	}
	temp->next = temp->next->next;
	delete deleteNode;
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	int queryNumber;
	cout << "How many queries: ";
	cin >> queryNumber;

	for (int i = 0; i < queryNumber; i++) {
		int x, v;

		cout << "Enter x and v: ";
		cin >> x >> v;

		if (x == 0) {
			insert_at_head(head, tail, v);
		}
		else if (x == 1) {
			insert_at_tail(head, tail, v);
		}
		else if(x == 2) {
			int length = list_length(head);
			if (v >= 0 && v < length) {
				delete_at_any_position(head, tail, v);
			}
			else {

			}
		}
		print_linked_list(head);
		cout << endl;
	}


	return 0;
}

