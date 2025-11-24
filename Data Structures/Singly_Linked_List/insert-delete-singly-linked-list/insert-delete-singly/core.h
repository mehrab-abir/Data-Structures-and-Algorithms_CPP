#pragma once

#ifndef CORE_H
#define CORE_H

class Node {
public:
	int value;
	Node* next;

	Node(int value);
};

void insert_at_head(Node*& head,Node*&tail, int value);
void insert_at_tail(Node*& head, Node*& tail, int value);

void insert_at_any_position(Node*& head, int index, int value);

void delete_head(Node*& head, Node*& tail);
void delete_tail(Node*& head, Node*& tail, int lastNode);
void delete_any_position(Node*& head, Node*& tail, int index);

int list_length(Node* head);

void print_linked_list(Node* head);

void reverse_print(Node* temp);




#endif
