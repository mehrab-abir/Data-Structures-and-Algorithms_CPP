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

//Time complexity O(1)
void insert_at_tail(Node* &head, Node* &tail, int value) {
	Node* newnode = new Node(value);


	/* head null thakle tail o null thakbe, newnode create korar por 2 ta kei update korte hobe, newnode-e
	tokhon head and tail */
	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
	/*or tail = tail->next lekha jay, karon bortoman tail er 'next' a newnode er address ase, at likhle
	tail newnode kei point korbe, 2 tai same */
	 
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}

int main() {

	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* tail = new Node(40);  //last node

	head->next = a;
	a->next = b;
	b->next = tail;

	cout << "The linked list: ";
	print_linked_list(head);
	cout << "\nTail = " << tail->value << endl;

	cout << endl;

	int value;
	cout << "Enter a value to insert: ";
	cin >> value;

	insert_at_tail(head, tail, value);

	cout << "\nAfter inserting " << value << " at tail, the linked list: ";
	print_linked_list(head);
	cout << "\nTail = " << tail->value << endl;

	insert_at_tail(head, tail, 60);

	cout << "\nAgain, after inserting 60 at tail: ";
	print_linked_list(head);
	cout << "\nTail = " << tail->value << endl;

	cout << endl;
	return 0;
}
