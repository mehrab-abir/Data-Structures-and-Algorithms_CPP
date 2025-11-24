#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "core.h"

using namespace std;

Node::Node(int value) {
	this->value = value;
	this->next = NULL;
}

//insert at head
void insert_at_head(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	if(head == NULL){
		head = newnode;
		tail = newnode;
		return;
	}

	newnode->next = head;
	head = newnode;
}

//insert at tail
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
void insert_at_any_position(Node*& head, int index, int value) {
	Node* newnode = new Node(value);

	Node* temp = head;
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next = newnode;
}


//delete head
void delete_head(Node*& head, Node*& tail) {
	if (head == NULL) {
		cout << "List is already empty." << endl;
		return;
	}

	Node* deleteNode = head;
	head = head->next;
	delete deleteNode;
	
	//if there was only one node
	if (head == NULL) {
		tail = NULL;
		cout << "\n  Head has been deleted" << endl;
		return;
	}

	cout << "\n  Head has been deleted" << endl;
}

//delete tail
void delete_tail(Node*& head, Node*& tail, int lastNode) {

	if (head == NULL) {
		cout << "\n  - List is already empty" << endl;
		return;
	}

	//if there is only one node
	if (head->next == NULL) {
		delete head;
		head = NULL;
		tail = NULL;
		cout << "\n  Tail deleted. List is now empty" << endl;
		return;
	}

	//otherwise
	Node* temp = head;
	for (int i = 1; i < lastNode - 1; i++) {
		temp = temp->next;
	}

	Node* deleteNode = temp->next;
	temp->next = NULL;
	delete deleteNode;

	tail = temp;

	cout << "\n  Tail has been deleted" << endl;

	
}

void delete_any_position(Node*& head, Node*& tail, int index) {
	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	
	Node* deleteNode = temp->next;
	temp->next = temp->next->next;
	delete deleteNode;
}

//length of the linked list
int list_length(Node* head) {
	Node* temp = head;

	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

//print the linked list
void print_linked_list(Node* head) {
	Node* temp = head;
	cout << "\nThe linked list: ";
	while (temp != NULL) {
		cout << temp->value<<" ";
		temp = temp->next;
	}
	cout << endl;
}

//reverse print
void reverse_print(Node* temp) {
	if (temp == NULL) {
		return;
	}
	reverse_print(temp->next);
	cout << temp->value << " ";
}
