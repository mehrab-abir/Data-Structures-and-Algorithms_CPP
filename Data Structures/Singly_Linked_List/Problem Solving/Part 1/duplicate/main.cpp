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
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create linked list: " << endl;

	while (true) {
		int value;
		cout << "Enter an integer number: ";
		cin >> value;

		if (value == -1) {
			break;
		}

		insert_at_tail(head, tail, value);
	}

	cout << "The linked list: ";
	print_linked_list(head);

	cout << endl;

	int freq[101] = { 0 };

	Node* temp = head;

	while (temp != NULL) {
		freq[temp->value] = freq[temp->value] + 1;
		temp = temp->next;
	}

	int duplicate = 0;

	for (int i = 0; i < 101; i++) {
		if (freq[i] > 1) {
			duplicate = 1;
			break;
		}
	}

	if (duplicate == 1) {
		cout << "Duplicate exist" << endl;
	}
	else {
		cout << "All elements are unique" << endl;
	}

	return 0;
}

