#include<iostream>

using namespace std;

int main() {
	int n;
	// cout << "Array size: ";
	cin >> n;

	int* numbers = new int[n];

	for (int i = 0; i < n; i++) {
		// cout << "Number " << i + 1 << ": ";
		cin >> numbers[i];
	}

	//selection sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (numbers[i] > numbers[j]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}

	//display sorted array
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << " ";
	}
	cout <<endl;

	delete[] numbers;

	return 0;
}
