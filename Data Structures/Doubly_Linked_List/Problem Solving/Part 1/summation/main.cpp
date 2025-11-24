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

int getSummation(Node* head) {
	Node* temp = head;

	int sum = 0;

	while (temp != NULL) {
		sum = sum + temp->value;
		temp = temp->next;
	}

	return sum;
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create a singly linked list: " << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}


	cout << "The linked list: ";
	print_linked_list(head);

	int sum = getSummation(head);
	
	cout << "Summation of all numbers: " << sum << endl;

	return 0;
}








