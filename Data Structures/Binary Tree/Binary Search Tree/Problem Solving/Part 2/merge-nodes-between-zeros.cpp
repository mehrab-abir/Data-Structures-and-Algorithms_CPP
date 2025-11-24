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

void printMergedList(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
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

	Node* newHead = NULL;
	Node* newTail = NULL;

	Node* temp = head->next;

	while (temp != NULL) {
		int sum = 0;
		Node* i;
		for (i = temp; i->value != 0; i = i->next) {
			sum = sum + i->value;
		}
		
		if (sum != 0) {
			insert_at_tail(newHead, newTail, sum);
		}
		temp = i->next;
	}

	cout << "New merged list: ";
	printMergedList(newHead);


	return 0;
}