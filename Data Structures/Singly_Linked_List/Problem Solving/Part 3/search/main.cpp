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

void search_number(Node* head) {
	int x;
	cout << "Search a number: ";
	cin >> x;

	int found = 0;
	int j = 0;

	for (Node* i = head; i != NULL; i = i->next) {
		if (i->value == x) {
			//cout << "Index : " << j << endl;
			found = 1;
			break;
		}
		else {
			j++;
		}
	}

	if (found == 1) {
		cout << j << endl;
	}
	else {
		cout << "-1" << endl;
	}
}

int main() {

	int testCase;
	cout << "Number of test cases: ";
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		Node* head = NULL;
		Node* tail = NULL;

		cout << "Create linked list: " << endl;

		while (true) {
			int value;
			cout << "Enter an integer number: ";
			cin >> value;

			if (value == -1) {
				break;
			}

			insert_at_tail(head, tail, value);
		}

		search_number(head);
	}

	return 0;
}

