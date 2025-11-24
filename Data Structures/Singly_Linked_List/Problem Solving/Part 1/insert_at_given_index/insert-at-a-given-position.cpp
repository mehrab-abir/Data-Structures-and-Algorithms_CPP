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

//insert head
void insert_at_head(Node*& head, Node*&tail, int value) {
	Node* newnode = new Node(value);

	newnode->next = head;
	head = newnode;
}


//insert tail
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

//insert at any position
void insert_at_any_position(Node* &head, int index, int value) {
	Node* newnode = new Node(value);

	Node* temp = head;
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;

}

//print list
void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

//length
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

	cout << "\t\nCreate Linked List >>>>" << endl;

	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	int queryNumber;
	cout << "How many queries: ";
	cin >> queryNumber;

	for (int i = 0; i < queryNumber; i++) {
		int index, value;

		cout << "Enter an integer number (value): ";
		cin >> value;

		cout << "Enter the position to insert: ";
		cin >> index;

		int length = list_length(head);

		if (index < 0) {
			cout << "Invalid Index" << endl;
		}
		else if (index == 0) {
			insert_at_head(head,tail, value);
			cout << "The linked list: ";
			print_linked_list(head);
		}
		//length r index soman manei tail a insert
		else if (index == length) {
			insert_at_tail(head, tail, value);
			cout << "The linked list: ";
			print_linked_list(head);
		}
		else if (index > 0 && index < length) {
			insert_at_any_position(head, index, value);
			cout << "The linked list: ";
			print_linked_list(head);
		}
		else {
			cout << "Invalid Index" << endl;
		}
		cout << endl;
	}


	return 0;
}