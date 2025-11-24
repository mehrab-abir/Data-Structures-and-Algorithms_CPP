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

int list_length(Node* head) {
	Node* temp = head;

	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}


int main() {

	Node* head_1 = NULL;
	Node* tail_1 = NULL;

	cout << "Create First Linked List >>>>" << endl;
	while (true) {
		int value;
		cout << "Enter a number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head_1, tail_1, value);
	}

	//second linked list
	Node* head_2 = NULL;
	Node* tail_2 = NULL;

	cout << "\nCreate Second Linked List >>>>" << endl;
	while (true) {
		int value;
		cout << "Enter a number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head_2, tail_2, value);
	}

	cout << "\nFirst linked list: ";
	print_linked_list(head_1);

	cout << endl;

	cout << "Second linked list: ";
	print_linked_list(head_2);
	cout << "\n";

	int length_1 = list_length(head_1);
	int length_2 = list_length(head_2);

	if (length_1 == length_2) {
		cout << "\nSizes are same for both linked list." << endl;
	}
	else {
		cout << "\nSizes are different" << endl;
	}
	

	return 0;
}