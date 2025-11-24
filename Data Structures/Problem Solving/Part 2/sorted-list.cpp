#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/sorted-3-1

int main() {

	set<int>s;

	int n;
	cout << "Size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cout << i + 1 << "> ";
		cin >> value;

		s.insert(value);
	}

	cout << "The list: ";
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}