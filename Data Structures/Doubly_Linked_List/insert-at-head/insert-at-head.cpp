#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value) {
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

//insert at head
void insert_at_head(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	//corner case
	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
}

void print_forward(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* tail = new Node(40);

	head->next = a; 
	a->prev = head;

	a->next = b;
	b->prev = a;

	b->next = tail;
	tail->prev = b;

	cout << "Before inserting at head: ";
	print_forward(head);

	cout << "After inserting at head: ";
	insert_at_head(head, tail, 100);
	print_forward(head);

	cout << "After inserting at head again: ";
	insert_at_head(head, tail, 200);
	print_forward(head);

	return 0;
}
