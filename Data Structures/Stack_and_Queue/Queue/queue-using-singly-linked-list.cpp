#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class myQueue {
public:
	Node* head = NULL;
	Node* tail = NULL;

	int length = 0;

	void push(int val) {
		
		//insert at tail

		Node* newnode = new Node(val);

		length++;

		if (head == NULL) {
			head = newnode;
			tail = newnode;
			return;
		}

		tail->next = newnode;
		tail = newnode;
	}


	void pop() {
		//delete head/front
		Node* deleteNode = head;
		head = head->next;
		delete deleteNode;

		length--;

		if (head == NULL) {
			tail = NULL;
			return;
		}
	}

	int front() {
		return head->val;
	}

	int back() {
		return tail->val;
	}

	int size() {
		return length;
	}

	bool empty() {
		return head == NULL;  //true/false
	}

};

int main() {
	myQueue q;

	int n;
	cout << "Enter size: ";
	cin >> n;

	//taking input
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Enter number "<<i+1<<": ";
		cin >> val;

		q.push(val);
	}

	cout << "\nSize = " << q.size() << endl;
	cout << "Front = " << q.front() << endl;

	cout << endl;

	//pop
	if (!q.empty()) {
		q.pop();
	}
	else {
		cout << "Queue is empty. POP is not possible" << endl;
	}
	
	//front
	if (!q.empty()) {
		cout << "\nAfter Poping once: Front = " << q.front() << endl;
	}
	else {
		cout << "Queue is empty.There is no front" << endl;
	}
	
	cout << "Size = " << q.size() << endl;


	//print whole queue again
	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}