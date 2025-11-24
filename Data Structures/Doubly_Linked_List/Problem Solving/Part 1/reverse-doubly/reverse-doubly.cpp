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

void reverse_doubly(Node*& head, Node*& tail) {
	
	for (Node* i = head, *j = tail; i != j && j != i->prev; i = i->next, j = j->prev) {
		swap(i->value, j->value);
	}
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "\nCreate doubly linked list 1 >>>>" << endl;
	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	cout << "The linked list: ";
	print_linked_list(head);

	cout << "The linked list after reversing: ";
	reverse_doubly(head, tail);

	print_linked_list(head);

	return 0;
}