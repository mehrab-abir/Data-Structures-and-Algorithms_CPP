#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include "input-output.h"
#include "insert.h"
#include "delete.h"

using namespace std;

void delete_head(Node*& head, Node*& tail) {
	if (head == NULL) {
		cout << "\n  - List is empty. Nothing to delete\n" << endl;
		return;
	}

	Node* deleteNode = head;

	head = head->next;
	delete deleteNode;

	//if there was only 1 node
	if (head == NULL) {
		tail = NULL;
		cout << "\n Head has been deleted" << endl;
		return;
	}

	head->prev = NULL;

	cout << "\n Head has been deleted" << endl;
}


//delete tail
void delete_tail(Node*& head, Node*& tail) {
	if (head == NULL) {
		cout << "\n  - List is empty. Nothing to delete\n" << endl;
		return;
	}

	Node* deleteNode = tail;
	tail = tail->prev;
	delete deleteNode;

	//if there was only 1 node
	if (tail == NULL) {
		head = NULL;
		cout << "\n Tail has been deleted" << endl;
		return;
	}
	tail->next = NULL;

	cout << "\n Tail has been deleted" << endl;
}

void delete_from_given_position(Node*& head, int index) {
	Node* temp = head;

	if (head == NULL) {
		cout << "\n - List is empty. Deletion is not possible." << endl;
		return;
	}

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	Node* deleteNode = temp->next;
	temp->next = temp->next->next;
	temp->next->prev = temp;
	delete deleteNode;
}
