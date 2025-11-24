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

int length = 0;

void insert_at_head(Node* &head, Node* &tail, int value) {
	Node* newnode = new Node(value);

	length++;

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	newnode->next = head;
	head->prev = newnode;
	head = newnode;

	cout <<"\n"<< value << " has been inserted at head.\n";
}


void insert_at_tail(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	length++;
	
	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}

void insert_at_any_position(Node* &head, int index, int value) {
	Node* newnode = new Node(value);

	length++;

	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
	newnode->prev = temp;

	cout << "\n" << value << " has been inserted at index/position " << index << endl;
}

void delete_head(Node* &head, Node*&tail) {
	if (head == NULL) {
		cout << "The Linked List is already empty. Nothing to delete." << endl;
		return;
	}

	Node* deleteNode = head;
	head = head->next;
	delete deleteNode;

	length--;

	//If there was only one node
	if (head == NULL) {
		tail = NULL;
	}

	head->prev = NULL;

	cout << "\n Head has been deleted." << endl;
}

void delete_tail(Node* &head, Node* &tail) {
	if (head == NULL) {
		cout << "The Linked List is already empty. Nothing to delete." << endl;
		return;
	}

	Node* deleteNode = tail;
	tail = tail->prev;
	delete deleteNode;

	length--;

	//if there was only one node
	if (tail == NULL) {
		head = NULL;
		return;
	}

	tail->next = NULL;

	cout << "\n Tail has been deleted." << endl;
}

void delete_from_any_position(Node* head, int index) {
	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	Node* deleteNode = temp->next;

	temp->next = temp->next->next;
	temp->next->prev = temp;
	delete deleteNode;

	length--;

	cout << "\nNode of position/index " << index << " has been deleted." << endl;
}

int list_length() {
	return length;
}

Node* get_ith_node(Node* head, int index) {
	Node* temp = head;

	for (int i = 1; i < index; i++) {
		temp = temp->next;
	}

	Node* targetNode = temp->next;
	return targetNode;
}

void print_forward(Node* head) {
	Node* temp = head;

	if (temp == NULL) {
		return;
	}

	cout << "\n The Linked List: ";
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void print_backward(Node* tail) {
	Node* temp = tail;

	if (temp == NULL) {
		return;
	}

	cout << "\n The Linked List in backward: ";
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;

	cout << "\n\t** Doubly Linked List **" << endl;

	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list: ): ";
		cin >> value;

		if (cin.fail()) {
			cout << " !!Invalid input. Enter a valid integer number." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	cout << "\nDoubly Linked List Created." << endl;

	int select;
	while (true) {
		cout << endl;
		cout << "1. Print forward" << endl;
		cout << "2. Insert at head" << endl;
		cout << "3. Insert at tail" << endl;
		cout << "4. Insert at at any position" << endl;
		cout << "5. Delete head" << endl;
		cout << "6. Delete tail" << endl;
		cout << "7. Delete from any position" << endl;
		cout << "8. Get any node's value" << endl;
		cout << "9. Get current length" << endl;
		cout << "10. Print backward" << endl;
		cout << "0. Exit" << endl;

		cout << "\nSelect an item from the list (0 to 10): ";
		cin >> select;

		if (cin.fail()) {
			cout << " !!Invalid selection. Please enter a number between 0 and 10." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		switch (select) {
		case 1:
			print_forward(head);
			cout << "\n**************************************************************************\n";
			break;
		case 2:
			int headValue;
			cout << "Enter a value: ";
			cin >> headValue;

			insert_at_head(head, tail, headValue);
			cout << "\n**************************************************************************\n";
			break;
		case 3:
			int tailValue;
			cout << "Enter an integer value: ";
			cin >> tailValue;

			insert_at_tail(head, tail, tailValue);
			cout << "\n**************************************************************************\n";
			break;
		case 4:
			length = list_length();

			int insertPosition, value;
			cout << "Enter an integer value: ";
			cin >> value;
			cout << "Enter the position to insert new value (0 based index): ";
			cin >> insertPosition;

			if (insertPosition < 0 || insertPosition > length) {
				cout << "Invalid position." << endl;
				break;
			}
			else if (insertPosition == 0) {
				insert_at_head(head, tail, value);
			}
			else if (insertPosition == length) {
				insert_at_tail(head, tail, value);
			}
			else {
				insert_at_any_position(head, insertPosition, value);
			}

			cout << "\n**************************************************************************\n";
			break;
		case 5:
			delete_head(head, tail);
			cout << "\n**************************************************************************\n";
			break;
		case 6:
			delete_tail(head, tail);
			cout << "\n**************************************************************************\n";
			break;
		case 7:
			length = list_length();
			int delPosition;
			cout << "Enter the position to delete (0 based index): ";
			cin >> delPosition;

			if (delPosition < 0 || delPosition >= length) {
				cout << "Invalid position" << endl;
				break;
			}
			else if (delPosition == 0) {
				delete_head(head, tail);
			}
			else if(delPosition == length-1){
				delete_tail(head, tail);
			}
			else {
				delete_from_any_position(head, delPosition);
			}

			cout << "\n**************************************************************************\n";
			break;
		case 8: {
			length = list_length();

			int index;
			cout << "Enter the node's index to get its value (0 based index): ";
			cin >> index;

			Node* targetNode = NULL;

			if (index < 0 || index >= length) {
				cout << "Invalid index." << endl;
				break;
			}

			targetNode = get_ith_node(head, index);
			cout << "Node's value: " << targetNode->value << endl;

			cout << "\n**************************************************************************\n";
			break;
		}
		case 9:
			length = list_length();
			cout << "Length of the linked list: " << length << endl;
			cout << "\n**************************************************************************\n";
			break;
		case 10:
			print_backward(tail);
			cout << "\n**************************************************************************\n";
			break;
		case 0:
			cout << "\n\t*** Good Bye ***\n";
			exit(1);
		default:
			cout << " !!Invalid selection. Please enter a number between 0 and 10." << endl;
			break;
		}
	}while (select != 0);

	return 0;
}