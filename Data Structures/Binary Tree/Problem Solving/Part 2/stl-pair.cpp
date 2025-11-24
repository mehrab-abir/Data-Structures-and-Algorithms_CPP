#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

	pair<int, int>p;

	//p = make_pair(10, 20); or
	p = { 25, 35 };

	cout << "First = " << p.first << endl;
	cout << "Second = " << p.second << endl;

	cout << endl;

	pair<string, int>pr;
	pr = { "Hello", 100 };

	cout << "First = " << pr.first << endl;
	cout << "Second = " << pr.second << endl;

	cout << endl;

	//vector pair
	int n;
	cout << "Vector size: ";
	cin >> n;

	vector<pair<int, int>>vPair(n);

	//input
	for (int i = 0; i < n; i++) {
		cout << "Enter first item of pair " << i + 1 << ": ";
		cin >> vPair[i].first;
		cout << "Enter second item of pair " << i + 1 << ": ";
		cin >> vPair[i].second;
	}

	//output
	cout << "\nOutput: " << endl;
	for (int i = 0; i < n; i++) {
		cout << vPair[i].first << " " << vPair[i].second << endl;
	}

	return 0;
}