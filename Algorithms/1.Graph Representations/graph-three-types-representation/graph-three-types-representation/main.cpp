#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include "graph.h"
using namespace std;

int main() {

	cout << "\n\t*** Graphs ***\n";

	A: int select;
	while (true) {
		cout << endl;
		cout << "1. Adjacency Matrix" << endl;
		cout << "2. Adjacency List" << endl;
		cout << "3. Edge List" << endl;
		cout << "0. Exit" << endl;

		cout << "Select an item from the list above: ";
		cin >> select;

		if (cin.fail()) {
			cout << "  !!Invalid selection. Enter a number between 0 and 3" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		if (select == 1) {
			adjacency_matrix();
			cout << "\n*****************************************\n";
		}
		else if (select == 2) {
			adjacency_list();
			cout << "\n*****************************************\n";
		}
		else if (select == 3) {
			edge_list();
			cout << "\n*****************************************\n";
		}
		else if (select == 0) {
			break;
		}
		else {
			cout << "  !!Invalid selection. Enter a number between 0 and 3" << endl;
		}
	}

	cin.ignore();
	cout << "\nAre you sure you want to exit? - [Y(es)/N(o)]: ";
	string confirm;
	getline(cin, confirm);

	bool yes = confirm == "Y" || confirm == "Yes" || confirm == "y" || confirm == "yes" || confirm == "YES";

	if (yes) {
		cout << "\n\t*** Good Bye ***\n";
	}
	else {
		goto A;
	}


	return 0;
}