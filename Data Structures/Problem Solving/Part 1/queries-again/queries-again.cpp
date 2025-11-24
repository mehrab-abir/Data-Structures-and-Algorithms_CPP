#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;

void print_forward(list<int>numbers) {
	cout << "L -> ";
	for (int value : numbers) {
		cout << value << " ";
	}
	cout << endl;
}

void print_backward(list<int>numbers) {
	cout << "R -> ";

	numbers.reverse();
	for (int value : numbers) {
		cout << value << " ";
	}
	cout << endl;
}

int main() {

	list<int>numbers;

	int query;
	cout << "Number of queries: ";
	cin >> query;

	int length = numbers.size();

	for (int i = 0; i < query; i++) {
		int x, v;

		cout << "Enter the value of x: ";
		cin >> x;

		cout << "Enter the value of v: ";
		cin >> v;

		length = numbers.size();

		if (x == 0) {
			numbers.push_front(v);

			print_forward(numbers);
			print_backward(numbers);
		}
		else if (x == 1) {
			numbers.push_back(v);

			print_forward(numbers);
			print_backward(numbers);
		}
		else if (x == 2) {
			if (v >= length || v < 0) {
				print_forward(numbers);
				print_backward(numbers);
			}
			else {
				numbers.erase(next(numbers.begin(), v));

				print_forward(numbers);
				print_backward(numbers);
			}
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}


	return 0;
}