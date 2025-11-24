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

void list_length(Node* head) {
	Node* temp = head;

	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	cout << "Length of the linked list: " << count << endl;
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

	cout << "Create linked list: "<<endl;

	while (true) {
		int value;
		cout << "Enter an integer number: ";
		cin >> value;

		if (value == -1) {
			break;
		}

		insert_at_tail(head, tail, value);
	}

	cout << "The linked list: ";
	print_linked_list(head);

	cout << endl;
	list_length(head);

	return 0;
}

