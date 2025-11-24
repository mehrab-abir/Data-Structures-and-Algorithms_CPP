#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include "input-output.h"
#include "insert.h"
#include "delete.h"

using namespace std;

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

//insert at head
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

void insert_at_any_position(Node*& head, int index, int value) {
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