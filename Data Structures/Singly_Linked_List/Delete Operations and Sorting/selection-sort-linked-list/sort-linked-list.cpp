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

//Selection Sort
void sort_linked_list(Node* head) {
	for (Node* i = head; i->next != NULL; i = i->next) {	// i cholbe last node er ag porjonto
		for (Node* j = i->next; j != NULL; j = j->next) {	//j cholbe last node porjonto, NULL ke imagine koro akta node hisebe, jeta sobar shese ache, r last existing node er 'next' a NULL er address ache. tahole, j cholbe oi NULL node er ag porjonto, r 'i' cholbe NULL node er ager Node er ag porjonto.
			if (i->value > j->value) {
				swap(i->value, j->value);
			}
		}
	}
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next; 
	}
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create linked list >>>>>" << endl;

	while (true) {
		int value;
		cout << "Enter a number (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	cout << "\nBefore sorting the linked list: ";
	print_linked_list(head);
	cout << endl;

	sort_linked_list(head);

	cout << "After sorting the linked list: ";
	print_linked_list(head);

	cout << endl;

	return 0;
}

