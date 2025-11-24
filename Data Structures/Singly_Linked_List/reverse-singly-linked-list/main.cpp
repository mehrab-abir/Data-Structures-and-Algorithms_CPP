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


//reverse linked list
void reverse_linked_list(Node*& head, Node* temp, Node*& tail) {

	if (temp->next == NULL) {
		head = temp;
		return;
	}
	reverse_linked_list(head, temp->next, tail);
	temp->next->next = temp;
	temp->next = NULL;
	tail = temp;
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;

	cout << "\nCreate a singly linked list >>>>>" << endl;

	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	cout << "The linked list: ";
	print_linked_list(head);
	
	if (head != NULL) {
		cout << "Head = " << head->value << endl;
		cout << "Tail = " << tail->value << endl;
	}
	cout << endl;

	//reverse
	reverse_linked_list(head, head, tail);
	
	cout << "The linked list after reversing: ";
	print_linked_list(head);

	cout << "Head = " << head->value << endl;
	cout << "Tail = " << tail->value << endl;

	cout << endl;

	return 0;
}