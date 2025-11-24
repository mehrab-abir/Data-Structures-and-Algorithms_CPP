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

void delete_at_any_position(Node*& head, int index) {
	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	Node* deleteNode = temp->next;
	temp->next = temp->next->next;

	/*uporer line er por temp er 'next' update hoye gese, akhon temp er next bolte j node delete kora hobe 
	tar porer node er address ase, tar mane oi node ke bola jay, temp er next, r tar prev a rakhte hobe 
	temp ke*/
	temp->next->prev = temp;
	delete deleteNode;
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

	int position;
	cout << "From which position/index to delete: ";
	cin >> position;

	cout << "After deleting: ";
	delete_at_any_position(head, position);
	print_forward(head);

	return 0;
}