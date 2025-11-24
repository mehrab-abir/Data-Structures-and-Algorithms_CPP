#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value) {
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

int main() {

	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* c = new Node(30);
	Node* d = new Node(30);

	head->next = a;
	a->prev = head;

	a->next = b;
	b->prev = a;

	b->next = c;
	c->prev = b;

	c->next = d;
	d->prev = c;
	//d->next = a; // Normally NULL thake, kintu airokom thakle cycle hoye jay 

	Node* slow = head;
	Node* fast = head;

	int cycle = 0;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			cycle = 1;
			break; //cycle detected
		}
	}

	if (cycle == 1) {
		cout << "Cycle detected" << endl;
	}
	else {
		cout << "No cycle in this linked list" << endl;
	}


	cout << endl;
	return 0;
}