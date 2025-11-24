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

void insert_at_head(Node*& head, Node*& tail, int value) { //look, head akta pointer, r akhane head er reference ante hoise, karon head change hobe, jeta main function a o howa lagbe

	Node* newnode = new Node(value); //at first, newnode create korte hobe 

	//corner case
	if(head == NULL){
		head = newnode;
		tail = newnode;
		return;
	}

	//newnode er 'next' a akhon NULL ache, constructor er karone, ata update kore head ke rakhte hobe

	newnode->next = head; //newnode er 'next' a head ke rekhe dilam, mane, new node er 'next' a head er address ache, karon head to nijei tar node er address carry korteche, jehetu dynamically neya hoise
	head = newnode; //head ke new node a niye gelam

}

void print_linked_list(Node* head) {
	Node* temp = head;

	int i = 1;
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
	//tail er 'next' a to NULL achei already

	cout << "Insert at head er age: " << endl;
	print_linked_list(head);

	insert_at_head(head, tail, 50);

	cout << "After inserting 50 at head:" << endl;
	print_linked_list(head);

	cout << endl<<endl;

	insert_at_head(head, tail, 70);
	cout << "After inserting 70 at head:" << endl;
	print_linked_list(head);

	cout << endl;
	return 0;
}
