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

//insert tail
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

//print list
void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

//length
int list_length(Node* head) {
	Node* temp = head;

	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

//check sorted or not
void check_sort(Node* head) {
	Node* temp = head;

	int sorted = 1;

	while (temp->next != NULL) {
		if (temp->value > temp->next->value) {
			sorted = 0;
			break;
		}
		else {
			temp = temp->next;
		}
	}

	if (sorted == 1) {
		cout << "Sorted in ascending order" << endl;
	}
	else {
		cout << "Not sorted" << endl;
	}
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "\t\nCreate Linked List >>>>" << endl;

	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	cout << endl;

	check_sort(head);

	return 0;
}