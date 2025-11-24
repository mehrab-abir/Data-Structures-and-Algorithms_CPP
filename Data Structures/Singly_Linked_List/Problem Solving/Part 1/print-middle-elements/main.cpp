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

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
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

	cout << "Create linked list >>>>> " << endl;

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

	cout << endl;

	int length = list_length(head);

	Node* temp = head;

	if (length % 2 == 0) {
		int middle = length / 2;

		for (int i = 1; i < middle; i++) {
			temp = temp->next;
		}
		cout <<"Middle elements: "<< temp->value << ", " << temp->next->value << endl;
	}
	else {
		int middle = (int)(length / 2) + 1;

		for (int i = 1; i < middle; i++) {
			temp = temp->next;
		}
		cout << "Middle element: " << temp->value << endl;
	}

	return 0;
}

