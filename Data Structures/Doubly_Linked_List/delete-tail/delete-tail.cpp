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
		this->next = next;
		this->prev = prev;
	}
};

void delete_tail(Node*& head, Node*& tail) {
	//if list is already empty ----corner case
	if (head == NULL) {
		cout << "List is already empty. Nothing to delete" << endl;
		return;
	}

	Node* deleteNode = tail;
	tail = tail->prev; /*jodi 1 ta node thakto, tahole oitai head and tail 2 tai hoto, and oi node er 'prev' a already NULL thakto, tar mane ai line er por tail NULL a chole jabe, karon oi 1 ta node er prev a to NULL chilo. ai jonno corner case handle korte hobe delete korar por*/
	delete deleteNode;

	// corner case
	/*1 ta matro node thakar karone tail NULL a chole jay, similarly head o NULL howa lagbe, jehetu oi akta
	node delete korar por list empty hoye jabe*/
	if (tail == NULL) {
		head = NULL;
		return;
	}
	tail->next = NULL; //1 ta node na thakle tail er 'next' a NULL hobe as usual
}

void print_forward(Node* head) {
	Node* temp = head;

	if (temp == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	/*Node* head = NULL;
	Node* tail = NULL;*/

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

	cout << "\nThe linked list: ";
	print_forward(head);

	cout << "After deleting tail: ";
	delete_tail(head, tail);
	print_forward(head);

	cout << "After deleting tail again: ";
	delete_tail(head, tail);
	print_forward(head);

	return 0;
}
