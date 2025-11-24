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

void insert_at_tail(Node* &head,Node* &tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	tail->next = newnode;
	newnode->next = NULL;
	tail = newnode;
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

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create a singly linked list >>>" << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	int length = list_length(head);
	int middle = length / 2;

	int targetNode;

	if (middle % 2 == 0) {
		targetNode = middle + 1;
	}
	else {
		targetNode = int(middle) + 1;
	}

	Node* temp = head;

	for (int i = 1; i < targetNode; i++) {
		temp = temp->next;
	}

	int middleValue = temp->value;
	cout << "Middle Node's value: "<< middleValue << endl;

	return 0;
}