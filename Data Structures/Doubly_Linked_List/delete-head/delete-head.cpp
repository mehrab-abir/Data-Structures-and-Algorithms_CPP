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

void delete_head(Node*& head, Node*& tail) {

	//if the list is already empty
	if (head == NULL) {
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}

	Node* deleteNode = head;
	head = head->next;
	delete deleteNode;

	/*Corner case--- if there was only one node, then it was both head and tail, in that case, after deleting
	that head node, head and tail both have to be NULL*/
	if (head == NULL) {
		tail = NULL;
		return;
	}
	head->prev = NULL;
}

void print_forward(Node* head) {
	Node* temp = head;

	if (temp == NULL) {
		cout << "List is empty"<<endl;
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

	cout << "After deleting head: ";
	delete_head(head, tail);
	print_forward(head);

	cout << "After deleting head again: ";
	delete_head(head, tail);
	print_forward(head);

	return 0;
}