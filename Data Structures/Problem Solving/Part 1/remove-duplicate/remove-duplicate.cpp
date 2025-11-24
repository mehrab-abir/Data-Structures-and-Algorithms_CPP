#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;

int main() {
	list<int>myList;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}

		myList.push_back(value);
	}

	myList.sort();

	myList.unique();

	cout << "After removing duplicates: ";
	for (int value : myList) {
		cout << value << " ";
	}

	cout << endl;
	return 0;
}
