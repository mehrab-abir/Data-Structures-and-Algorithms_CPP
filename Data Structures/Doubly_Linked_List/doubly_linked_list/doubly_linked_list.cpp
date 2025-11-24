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

void print_forward(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

//almost same as singly linked list, just traverse from tail to head's null
void print_backward(Node* tail) {

	Node* temp = tail;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main() {
	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* tail = new Node(40);

	head->next = a;  //head er prev a already NULL ache, constructor er dara
	a->prev = head;

	a->next = b;
	b->prev = a;

	b->next = tail;
	tail->prev = b;
	//tail er 'next' a to already NULL ase

	cout << "Forward: ";
	print_forward(head);

	cout << "Backward: ";
	print_backward(tail);


	return 0;
}
