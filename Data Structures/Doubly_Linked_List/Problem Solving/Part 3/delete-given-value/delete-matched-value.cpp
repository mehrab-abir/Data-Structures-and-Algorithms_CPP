#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//leetcode https://leetcode.com/problems/remove-linked-list-elements/

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

void delete_node(Node*& head, int givenValue) {
	if (head == NULL) {
		cout << "The list is empty" << endl;
		return;
	}

	if (head->value == givenValue) {
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;
	}

	Node* temp = head;
	while (temp != NULL && temp->next != NULL) {
		if (temp->next->value == givenValue) {
			Node* deleteNode = temp->next;
			temp->next = temp->next->next;
			delete deleteNode;
		}
		else {
			temp = temp->next;
		}
	}

	/*
	if all elements were same and that was the given value, then after the while loop, there will still remain
	one element. In that case...>>
	*/
	if (head != NULL && head->value == givenValue) {
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;
	}
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

	int number;
	cout << "Enter the value to delete: ";
	cin >> number;

	delete_node(head, number);

	cout << "The list after deleting "<<number<<": ";
	print_linked_list(head);


	return 0;
}


