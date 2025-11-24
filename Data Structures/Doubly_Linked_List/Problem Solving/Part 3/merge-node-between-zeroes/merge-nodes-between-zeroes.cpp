#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//leetcode https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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

void insert_at_new_list(Node*& head, Node* &tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	tail->next = newnode;
	tail = newnode;
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create a linked list: " << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}

		insert_at_tail(head, tail, value);
	}

	cout << "The list: ";
	print_linked_list(head);

	Node* newHead = NULL;
	Node* newTail = NULL;

	Node* temp = head->next; //skipping first 0 of the list, starting addition from the 2nd node

	while (temp != NULL) {
		Node* i;
		int sum = 0;
		for (i = temp ; i->value != 0; i = i->next) {
			sum = sum + i->value;
		}

		if (sum != 0) {
			insert_at_new_list(newHead, newTail, sum);
		}

		temp = i->next;
	}

	cout << "The list after merging nodes: ";

	print_linked_list(newHead);


	return 0;
}
