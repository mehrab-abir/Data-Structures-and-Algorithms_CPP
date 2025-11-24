#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cout << "How many numbers: ";
	cin >> n;

	vector<int>numbers(n);

	for (int i = 0; i < n; i++) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	//binary search

	int query;
	cout << "How many queries: ";
	cin >> query;

	for (int q = 0; q < query; q++) {
		int x;
		cout << "Enter a number to search: ";
		cin >> x;

		int left = 0;
		int right = n-1;

		int found = 0;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (numbers[mid] == x) {
				found = 1;
				break;
			}
			else if (numbers[mid] > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (found == 1) {
			cout << "Found" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	

	return 0;
}