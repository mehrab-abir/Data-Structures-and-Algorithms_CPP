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

void remove_duplicates(Node* head) {
	for (Node* i = head; i != NULL; i = i->next) {
		Node* j = i;

		while (j->next != NULL) {
			if (i->value == j->next->value) { 
				Node* deleteNode = j->next;   
				j->next = j->next->next;      
				delete deleteNode;            
			}
			else {
				j = j->next;
			}
		}
	}
}


int main() {

	Node* head = NULL;
	Node* tail = NULL;

	while (true) {
		int value;
		cout << "Enter number: ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	remove_duplicates(head);

	cout << endl;
	print_linked_list(head);


	return 0;
}