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
	Node* head_1 = NULL;
	Node* tail_1 = NULL;

	while (true) {
		int value;
		cout << "Enter number: ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head_1, tail_1, value);
	}


	Node* head_2 = NULL;
	Node* tail_2 = NULL;

	while (true) {
		int value;
		cout << "Enter number: ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head_2, tail_2, value);
	}

	int length_1 = list_length(head_1);
	int length_2 = list_length(head_2);

	if (length_1 != length_2) {
		cout << "No" << endl;
	}
	else {
		Node* i = head_1;
		Node* j = head_2;

		int isSame = 1;

		for (i = head_1, j = head_2; i != NULL, j != NULL;i=i->next, j= j->next ) {
			if (i->value != j->value) {
				isSame = 0;
				break;
			}
		}

		if (isSame == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}


	return 0;
}

