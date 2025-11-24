#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;
};

int main() {
	Node a, b, c;

	a.value = 10;
	b.value = 20;
	c.value = 30;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	/*cout << "a.Value = " << a.value << endl;
	cout << "b.Value = " << b.value << endl;
	cout << "c.Value = " << c.value << endl;*/

	//using connection
	cout << "a.Value = " << a.value << endl;
	//cout << "b.Value = " << (*a.next).value << endl; //a.next is a pointer, as it contains address of the next node, so we dereference
	cout << "b.value = " << a.next->value << endl; //using arrow sign, shortcut of dereference operator
	cout << "c.Value = "<<a.next->next->value << endl;


	return 0;
}