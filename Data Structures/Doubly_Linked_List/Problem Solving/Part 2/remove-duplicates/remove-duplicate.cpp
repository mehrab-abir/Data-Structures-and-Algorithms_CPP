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

void sort_list(Node* head) {
	Node* i, * j;

	for (i = head; i->next != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (i->value > j->value) {
				swap(i->value, j->value);
			}
		}
	}
}

//remove duplicate
void remove_duplicate(Node* head) {

	if (head == NULL) {
		cout << "The list is empty. Nothing to delete." << endl;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL) {
		if (temp->value == temp->next->value) {
			Node* deleteNode = temp->next;
			temp->next = temp->next->next;
			delete deleteNode;
		}
		else {
			temp = temp->next;
		}
	}
}

void print_linked_list(Node* head) {
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


	sort_list(head);

	remove_duplicate(head);

	cout << "After removing duplicates: ";
	print_linked_list(head);

	return 0;
}