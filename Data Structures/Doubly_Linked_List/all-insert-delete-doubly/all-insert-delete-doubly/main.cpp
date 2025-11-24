#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<limits>

#include "input-output.h"
#include "insert.h"
#include "delete.h"

using namespace std;

int main() {
	Node* head = NULL;
	Node* tail = NULL;

	cout << "\n\t*** Doubly Linked List ***\n";
	cout << "Create Doubly Linked List >>>>>" << endl;
	
	while (true) {
		int value;
		cout << "Enter an integer number (-1 to end the list): ";
		cin >> value;

		if (cin.fail()) {
			cout << "  !!Invalid input. Enter a valid integer number.\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}

	cout << "\nDoubly Linked List Created" << endl;

	int select;

	while (true) {
		cout << endl;
		cout << "1. Print forward" << endl;
		cout << "2. Print backward" << endl;
		cout << "3. Insert at head" << endl;
		cout << "4. Insert at tail" << endl;
		cout << "5. Insert at a given position" << endl;
		cout << "6. Delete head" << endl;
		cout << "7. Delete tail" << endl;
		cout << "8. Delete from a given position" << endl;
		cout << "9. Length of the linked list" << endl;
		cout << "0. Exit" << endl;

		cout << "Select an item from the list: ";
		if (!(cin >> select)) {
			cout << "\n  !! Invalid Input. Enter a number between 0 and 9." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		int length = list_length(head);

		switch (select) {
		case 1:
			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 2:
			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List in reverse: ";
			print_backward(tail);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 3:
			int value_head;
			cout << "Enter an integer number to insert: ";
			cin >> value_head;

			if (cin.fail()) {
				cout << "\t** Invalid input. Enter an integer number. **" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			insert_at_head(head, tail, value_head);

			cout << "\n" << value_head << " has been inserted at head." << endl;

			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 4:
			int value_tail;
			cout << "Enter an integer number to insert: ";
			cin >> value_tail;

			if (cin.fail()) {
				cout << "\t** Invalid input. Enter an integer number. **" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			insert_at_tail(head, tail, value_tail);
			cout << "\n" << value_tail << " has been inserted at tail." << endl;

			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 5:
			int position, value;

			cout << "Enter a value to insert: ";
			cin >> value;

			if (cin.fail()) {
				cout << "\t** Invalid input. Enter an integer number. **" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			cout << "Enter the position/index: ";
			cin >> position;

			if (cin.fail()) {
				cout << "\t** Invalid input. Enter an integer number. **" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			if (position > length) {
				cout << "\n  %% Invalid Index %%" << endl;
			}
			else if (head == NULL && position == 0) {
				insert_at_tail(head, tail, value);
			}
			else {
				insert_at_any_position(head, position, value);

				cout << "\n" << value << " has been inserted at position/index " << position << endl;
			}
			
			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;

			cout << "\n***********************************************************************" << endl;
			break;
		case 6:
			delete_head(head, tail);

			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 7:
			delete_tail(head, tail);

			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;
			cout << "\n***********************************************************************" << endl;
			break;
		case 8:
			int delete_position;
			cout << "Enter the position/index to delete: ";
			cin >> delete_position;

			if (delete_position >= length) {
				cout << "\n  %% Invalid Index %%" << endl;
			}
			else {
				delete_from_given_position(head, delete_position);

				cout << "Value from index " << delete_position << " has been deleted" << endl;
			}

			cout << "\n---------------------------------------------------------" << endl;
			cout << "The Linked List: ";
			print_forward(head);
			cout << "---------------------------------------------------------" << endl;

			cout << "\n*********************************************************" << endl;
			break;
		case 9:
			
			cout << "\nLength of the list: " << length << endl;
			cout << "\n*********************************************************" << endl;
			break;
		case 0:
			cout << "\n\t*** Good Bye ***" << endl << endl;
			exit(1);
			break;
		default:
			cout << "  !! Invalid selection. Enter a number between 0 and 9" << endl << endl;
			break;
		}
	}


	return 0;
}
