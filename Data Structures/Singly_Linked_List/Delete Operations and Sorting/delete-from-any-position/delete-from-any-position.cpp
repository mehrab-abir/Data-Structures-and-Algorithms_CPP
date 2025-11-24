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

	if (temp == NULL) {
		cout << "Linked List is empty." << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

//delete from any position
void delete_from_any_position(Node*& head, int index) {
	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	//loop er por, temp akhon targeted node er tik age ache
	//tar mane, temp er 'next' a targeted node er address ache, jeta delete korte chacchi

	Node* deleteNode = temp->next;
	temp->next = temp->next->next; //temp er 'next' update kore deleted node er porer node rekhe dilam
	delete deleteNode;
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create Linked List >>>>" << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	cout << "\nBefore deleting: ";
	print_linked_list(head);

	int position;
	cout << "From which position to delete: ";
	cin >> position;

	delete_from_any_position(head, position);

	cout << "\nAfter deleting the value from position " << position << ": ";
	print_linked_list(head);

	return 0;
}
