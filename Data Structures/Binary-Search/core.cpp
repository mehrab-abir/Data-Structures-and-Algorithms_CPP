#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

#include "core.h"
using namespace std;

//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Z
//Linear search, O(N)
void searchNumber() {
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>arr(n);

	//input
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << endl;

	//display array
	cout << "The array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//search numbers
	int x, q;
	
	cout << "Number of queries: ";
	cin >> q;

	for (int i = 0; i < q; i++) {
		cout << "Search a number: ";
		cin >> x;

		int found = 0;

		for (int j = 0; j < n; j++) {
			if (arr[j] == x) {
				found = 1;
				break;
			}
		}

		if (found == 1) {
			cout << "Found" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	
}


//binary search..complexity O(logN)
void binarySearch() {
	cout << "Binary Search >>>> " << endl<<endl;
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>arr(n);

	//input
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << endl;

	//display array
	cout << "The array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//search numbers
	int x, q;

	cout << "Number of queries: ";
	cin >> q;

	//binary search works only for sorted array
	sort(arr.begin(), arr.end()); //O(nlogn)

	for (int i = 0; i < q; i++) {
		cout << "Search a number: ";
		cin >> x;

		int found = 0;

		int left = 0;
		int right = n - 1;


		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] == x) {
				found = 1;
				break;
			}
			else if (arr[mid] > x) {
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
}