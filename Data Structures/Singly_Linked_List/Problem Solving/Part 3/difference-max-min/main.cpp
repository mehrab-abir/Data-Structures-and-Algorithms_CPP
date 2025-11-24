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

int get_max(Node* head) {
	Node* temp = head;

	int max = temp->value;

	while (temp != NULL) {
		if (temp->value > max) {
			max = temp->value;
		}
		temp = temp->next;
	}

	return max;
}

int get_min(Node* head) {
	Node* temp = head;

	int min = temp->value;

	while (temp != NULL) {
		if (temp->value < min) {
			min = temp->value;
		}
		temp = temp->next;
	}

	return min;
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

	while (true) {
		int value;
		cout << "Enter value: ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	int length = list_length(head);

	if (length == 1) {
		cout << "Difference : 0" << endl;
	}
	else {
		int maxValue = get_max(head);
		int minValue = get_min(head);

		cout << "Difference = " << maxValue - minValue << endl;
	}

	return 0;
}

