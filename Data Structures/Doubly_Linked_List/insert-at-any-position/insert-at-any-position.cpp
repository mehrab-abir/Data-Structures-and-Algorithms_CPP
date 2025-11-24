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

//insert at any position
void insert_at_any_position(Node*& head, int index, int value) {
	Node* newnode = new Node(value);

	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	newnode->next = temp->next; //newnode and tar porer tar moddhe forward connection
	temp->next->prev = newnode; //newnode and tar porer tar moddhe backward connection
	temp->next = newnode; //newnode and tar ager tar moddhe forward connection
	newnode->prev = temp; //newnode and tar ager tar moddhe backward connection
}


void print_forward(Node* head) {

	Node* temp = head;

	//if list is empty
	if (head == NULL) {
		cout << "Linked list is empty" << endl;
		return;
	}

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

	int value, position;

	cout << "Enter a value: ";
	cin >> value;
	cout << "Enter a position/index: ";
	cin >> position;

	cout << "After inserting " << value << " at postion/index " << position << ": ";
	insert_at_any_position(head, position, value);
	print_forward(head);

	cout << "After inserting 500 at postion/index 3: ";
	insert_at_any_position(head, 3, 500);
	print_forward(head);

	return 0;
}
