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

//insert at tail
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


void print_forward(Node* head) {

	Node* temp = head;

	//if list is empty
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

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create Linked List >>>>" << endl;  //same as singly linked list
	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	
	print_forward(head);

	return 0;
}