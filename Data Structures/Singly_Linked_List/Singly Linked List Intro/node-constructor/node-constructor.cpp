#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value) {		//constructor
		this->value = value;
		this->next = NULL;
	}
};

int main() {
	Node a(10), b(20), c(30); //they are just objects of Node Class

	a.next = &b;
	b.next = &c;
	//c.next = NULL >>>at kora lagbe na,, constructor er dara automatic c er next NULL hoye ache, baki gula o chilo, just update hoise,,c NULL thakbe karon ata last node

	cout << "a.Value = " << a.value << endl;
	cout << "b.value = " << a.next->value << endl;
	cout << "c.Value = " << a.next->next->value << endl;


	return 0;
}

