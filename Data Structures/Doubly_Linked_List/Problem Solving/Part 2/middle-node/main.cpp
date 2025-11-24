#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*find the middle of a linked list, if there are two middle items, get the 2nd one*/


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

	if (temp == NULL) {
		cout << "Linked List is empty." << endl;
		return;
	}

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

void getMiddle(Node* head, int target) {
	Node* temp = head;

	for (int i = 1; i < target; i++) {
		temp = temp->next;
	}
	cout << "Middle item = " << temp->value << endl;
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create Linked List >>>>" << endl;

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

	int length = list_length(head);

	int middle = length / 2;

	int target;

	if (middle % 2 == 0) {
		target = middle + 1;
	}
	else {
		target = (int)middle + 1;
	}

	getMiddle(head, target);

	return 0;
}








