#pragma once

class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value);
};

void print_forward(Node* head);
void print_backward(Node* tail);
int list_length(Node* head);
