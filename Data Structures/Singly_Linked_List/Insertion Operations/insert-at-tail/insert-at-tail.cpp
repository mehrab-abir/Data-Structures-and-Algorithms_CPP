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

void insert_at_tail(Node* &head,Node* &tail, int value) {
	Node* newnode = new Node(value);

	//corner case
	if (head == NULL) { //'head' null thakle (List empty) newnode e hobe head and tail
		head = newnode;
		tail = newnode;
		return; //return na korle porer line gula execute hoye jabe
	}

	Node* temp = head;
	/*
	temp er 'next' a null noye gele loop stop hoye jabe, karon, amader jete hobe last existing node a,
	okahne giye theme jete hobe, tar mane, temp jokhon oi last a thakbe, tokhon temp er 'next' NULL er
	address thakbe, that means amra last existing node a chole ashchi,NULL node ke akta node hisebe imagine
	koro jeta last real node er pore ache, oita porjonto gele hobe na, just temp er 'next' a oitar address
	address(null) chole ashlei theme jete hobe, ai jonno (temp->next != NULL) deya
	hoise
	*/
	while (temp->next != NULL) {
		temp = temp->next;
	}
	//loop shese, temp akhon last real node a ache, r temp er 'next' a NULL ache, karon NULL howar porei loop theme gese
	temp->next = newnode; //temp er 'next' upadte kore newnode rekhe dilam
	//new node e to NULL achei already, constructor er dara
}

void print_linked_list(Node* head) {
	Node* temp = head;

	int i = 1; 

	/*
	akhne, temp jokhon akbare NULL node a chole jabe, tokhon loop thambe, last real node porjonto jabe and oi last real node er value print korbe, jokhon-e temp NULL node ke point korbe jeta last real node er pore ache (imagine koro), loop stop hoye jabe
	*/
	while (temp != NULL) {
		cout << "Node " << i << ": " << temp->value << endl;
		temp = temp->next;
		i++;
	}
}

int main() {

	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* tail = new Node(30);

	head->next = a;
	a->next = tail;

	cout << "Insert at tail er age: " << endl;
	print_linked_list(head);

	insert_at_tail(head, tail, 50);

	cout << "After inserting 50 at tail:" << endl;
	print_linked_list(head);

	cout << endl << endl;

	insert_at_tail(head, tail, 70);
	cout << "After inserting 70 at tail:" << endl;
	print_linked_list(head);

	cout << endl;
	return 0;
}
