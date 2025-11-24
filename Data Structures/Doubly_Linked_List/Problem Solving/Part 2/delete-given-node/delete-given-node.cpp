#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//leetcode link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

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

//deleting the given node
void deleteNode(Node* node) {
	node->value = node->next->value;
	node->next = node->next->next;
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

	//5 3 6 1 8 7
	cout << "The list: ";
	print_linked_list(head);

	//list length is 6, it is guaranteed that the given node is not the tail node
	//node to delete >> 1
	//5 3 6 1 8 7

	Node* node = head;

	for (int i = 1; i < 4; i++) {
		node = node->next;
	}
	
	//delete this node
	deleteNode(node);

	cout << "After removing the given node: ";
	print_linked_list(head);

	return 0;
}








