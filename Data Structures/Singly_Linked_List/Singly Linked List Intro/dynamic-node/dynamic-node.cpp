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

	head->next = a; //a itslef is a pointer/address. So we don't use & sign before it
	a->next = b;
	b->next = c;
	//c er next a already NULL ase, constructor er dara

	cout << "Head value: " << head->value << endl;
	cout << "a > value: " << head->next->value << endl; //head->next manei a,,meaning a->value,, a eikhane akta pointer, tai arrow sign
	cout << "b > value: " << head->next->next->value << endl; //head er maddhome avabe access korte hoy
	cout << "c > value: " << head->next->next->next->value << endl; 



	return 0;
}