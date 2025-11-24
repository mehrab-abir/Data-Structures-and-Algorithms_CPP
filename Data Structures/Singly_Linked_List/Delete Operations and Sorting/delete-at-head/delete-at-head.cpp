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

void insert_at_tail(Node* &head, Node* &tail, int value) {
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

//delete head
void delete_head(Node*& head, Node* &tail) {
	Node* deleteNode = head;

	if (head == NULL) {
		cout << "\nLinked list is empty. Nothing to delete." << endl;
		return;
	}

	//head null na thakle
	head = head->next;
	delete deleteNode;

	/*Corner case--- if there was only one node, then it was both head and tail, in that case, after deleting
	that head node, head and tail both have to be NULL*/
	if (head == NULL) {
		tail = NULL;
		return;
	}
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
	cout << "\nBefore deleting head: ";
	print_linked_list(head);
	
	delete_head(head, tail);
	cout << "\nAfter deleting head: ";
	print_linked_list(head);

	return 0;
}
