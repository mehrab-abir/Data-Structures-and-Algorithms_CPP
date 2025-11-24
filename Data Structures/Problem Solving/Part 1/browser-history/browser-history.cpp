#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Node {
public:
	string value;
	Node* next;
	Node* prev;

	Node(string value) {
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

void insert_at_tail(Node*& head, Node*& tail, string value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}

void print_linked_list(Node* head) {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	while (true) {
		string value;
		cout << "Enter a string: ";
		cin >> value;

		if (value == "end") {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	cout << "The list: ";
	print_linked_list(head);

	int q;
	cout << "How many queries: ";
	cin >> q;
	cin.ignore();

	string firstCommand;
	cout << "Enter command: ";
	getline(cin, firstCommand);

	Node* temp = head;
	string address = firstCommand.substr(6);

	while (temp != NULL) {
		if (temp->value == address) {
			cout << address << endl;
			break;
		}
		else {
			temp = temp->next;
		}
	}

	for (int i = 1; i < q; i++) {
	
		string command;
		cout << "Enter command: ";
		getline(cin, command);

		if (command.substr(0, 6) == "visit ") {
			string address = command.substr(6);

			Node* temp2 = head;
			
			while (temp2 != NULL) {
				if (temp2->value == address) {
					cout << address << endl;
					temp = temp2;
					break;
				}
				else {
					temp2 = temp2->next;
				}
			}
			if (temp2 == NULL) {
				cout << "Not Available" << endl;
			}
			
		}
		else if (command == "next") {
			if (temp->next != NULL) {
				cout << "Next value: "<<temp->next->value << endl;
				temp = temp->next;
			}
			else {
				cout << "Not Available" << endl;
			}
		}
		else {
			if (temp->prev != NULL) {
				cout << "Previous value: " << temp->prev->value << endl;
				temp = temp->prev;
			}
			else {
				cout << "Not Available" << endl;
			}
		}
	}


	return 0;
}