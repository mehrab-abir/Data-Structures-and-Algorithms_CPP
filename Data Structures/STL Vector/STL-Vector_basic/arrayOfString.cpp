#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include "arrayOfString.h"

using namespace std;

void arrayOfString() {
	int n;
	cout << "How many people: ";
	cin >> n;
	cin.ignore();

	vector<string>names(n);

	for (int i = 0; i < n; i++) {
		cout << "Person " << i + 1 << ": ";
		getline(cin, names[i]);
	}

	cout << "\nNames: " << endl;

	for (int i = 0; i < n; i++) {
		cout << names[i] << endl;
	}
	cout << endl;
}