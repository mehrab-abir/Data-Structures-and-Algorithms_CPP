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

int main() {
	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* c = new Node(40);

	head->next = a;
	a->next = b;
	b->next = c;

	cout << "The linked list: ";
	//usually, we keep the head in a temp node, then print the list, so the head is not lost
	/*while (head != NULL) {
		cout << head->value << " " ;
		head = head->next;
	}*/

	Node* temp = head;
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	//after this loop, temp is at NULL, imagine NULL as a Node which is at the end of the list, even after the last node, the last node is right before the null, when temp is at NULL, that's when the loop stops, the temp will keep moving forward untill it reaches the last existing node, when it will go to the NULL node, the loop stops
	cout << endl;

	//print the list again

	cout << "The linked list again: ";
	temp = head; //bringing the temp back at head
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;


	cout << "The linked list again: " << endl;
	temp = head; //bringing the temp back at head
	int i = 1; //to give each node a serial number
	while (temp != NULL) {
		cout << "Node "<<i<<": "<<temp->value <<endl;
		temp = temp->next;
		i++;
	}
	cout << endl;

	return 0;
}