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

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


//reverse the original list
Node* reverse_list(Node* original_head) {
	Node* reversed_head = NULL; //new linked list where values of the original list will be stored in reverse
	Node* reversed_tail = NULL;

	Node* temp = original_head;

	while (temp != NULL) {
		Node* newnode = new Node(temp->value); //creating a node with the value of original list

		//inserting that node at head of the new node so that the values are inserted in reverse order in the new list
		//if we insert at tail, it won't be reversed, rather just a copy of the original list
		newnode->next = reversed_head; 
		reversed_head = newnode;

		temp = temp->next; //moving temp to the next node, temp representing original list
	}

	return reversed_head; //head of the newly created linked list in which the values are in reverse order
}

//check if palindrome or not
void isPalindrome(Node* head, Node* reversed_head) {
	Node* i = head, * j = reversed_head;

	int palindrome = 1;

	for (i = head, j = reversed_head; i != NULL; i = i->next, j = j->next) {
		if (i->value != j->value) {
			palindrome = 0;
			break;
		}
	}

	if (palindrome == 1) {
		cout << "Palindrome" << endl;
	}
	else {
		cout << "Not palindrome" << endl;
	}
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "Create a singly linked list: " << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}


	cout << "Original linked list: ";
	print_linked_list(head);

	Node* reversed_head = reverse_list(head);

	cout << "After reversing: ";
	print_linked_list(reversed_head);

	cout << endl;

	isPalindrome(head, reversed_head);
	

	return 0;
}

