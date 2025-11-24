#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include "input-output.h"
#include "insert.h"
#include "delete.h"

using namespace std;

Node::Node(int value) {
	this->value = value;
	this->next = next;
	this->prev = prev;
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
