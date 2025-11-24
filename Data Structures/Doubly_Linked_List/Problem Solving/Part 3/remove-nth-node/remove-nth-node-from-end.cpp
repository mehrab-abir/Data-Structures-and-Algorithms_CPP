#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


//leetcode https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int list_length(Node* head) {
	Node* temp = head;
	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

//delete nth n ode from the endd
void delete_nth_node(Node*& head, int nthNode) {

	int length = list_length(head);

	/*
	If there is only one node or If the nth node is the same as the length of the list
	*/
	if (length - nthNode == 0) {
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;
		return;
	}

	Node* temp = head;

	for (int i = 1; i < length - nthNode; i++) {
		temp = temp->next;
	}

	Node* deleteNode = temp->next;
	temp->next = temp->next->next;
	delete deleteNode;
}


int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create a linked list: " << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}

		insert_at_tail(head, tail, value);
	}

	cout << "The list: ";
	print_linked_list(head);

	int nthNode;
	cout << "Enter the node number to delete from the end: ";
	cin >> nthNode;

	delete_nth_node(head, nthNode);

	cout << "The list after deleting node "<<nthNode<<" from the end: ";
	print_linked_list(head);

	return 0;
}

