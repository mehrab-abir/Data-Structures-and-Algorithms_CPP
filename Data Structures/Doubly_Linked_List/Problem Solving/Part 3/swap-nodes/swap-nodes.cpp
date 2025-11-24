#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//leetcode link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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

	//1 based index
	int index;
	cout << "Which positions' value to swap from beginning and end: ";
	cin >> index;

	Node* a = head;
	Node* b = head;


	int length = list_length(head);

	for (int i = 1, j = 1; i < length; i++, j++) {
		if (i < index) { 
			a = a->next;
		}
		if (j <= length - index) {
			b = b->next;
		}
	}

	swap(a->value, b->value);


	cout << "The list after swapping values: ";
	print_linked_list(head);
	
	//Example
	//5 7 6 1 9 8 3 9
	//index 3
	//a will move 2 times to reach index 3(value 6)
	//b will move 5 times to reach index 3 from ending (value 8)
	/*
	that's why, i < index and
	j <= length - index or
	j <= 8-3 or
	j<= 5,, j moves 5 times forward to reach 8
	*/

	//than we swap 6 and 8

	return 0;
}








