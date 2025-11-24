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

void insert_at_any_position(Node* &head, int index, int value) {
	Node* newnode = new Node(value);

	Node* temp = head;

	/*
	akhane, index hochche muloto, koto bar 'temp' ke samner dike move korate hobe, koto bar temp=temp->next 
	korar por amra sei node a jete parbo, jar tik age insert korate hobe. Jemon, jodi 3 number position a
	insert korte hoy, tahole 2 number position porjonto jete hobe. Se porjonto jete joto bar temp ke samner
	dike move korar proyujon porbe, loop totobar cholbe, sei node a chole gele loop theme jabe.
	*/
	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}
	/*
	//2 4 5 6 7,,,akhane indexing 0 based, jodi 4 er pore insert korte chai, amader jete hobe 4 porjonto,
	r index/position hobe 2 (5 er position), tar mane i=1 jokhon, tokhon 1 bar temp samne jabe, 4 er kache,
	ata hobe i < 2, akhne 2 holo 5 er position, amra jabo 4 porjonto, tai i 1 theke shuru hoye less than
	index porjonto gelei 4 e jawa hoye jabe
	*/

	newnode->next = temp->next; /*new node er 'next' a tar porer node er address rekhe dilam, jeta temp
	er 'next a ache'*/
	temp->next = newnode; // temp er 'next' ke update kore newnode rekhe dilam, mane new node er address r ki

	//insert howar somoy 0 based index er hisab onujayi insert hobe
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}

int main() {

	Node* head = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* c = new Node(40);

	head->next = a;
	a->next = b;
	b->next = c;

	cout << "The linked list: ";
	print_linked_list(head);

	cout << endl;

	int value, position;
	cout << "Enter a value to insert: ";
	cin >> value;

	cout << "In which position to insert: ";
	cin >> position;

	insert_at_any_position(head, position, value);

	cout << "\nAfter inserting " << value << " at position " << position << ", the linked list: ";
	print_linked_list(head);

	insert_at_any_position(head, 2, 60);

	cout << "\nAgain, after inserting 60 at 2nd position: ";
	print_linked_list(head);

	cout << endl;
	return 0;
}
