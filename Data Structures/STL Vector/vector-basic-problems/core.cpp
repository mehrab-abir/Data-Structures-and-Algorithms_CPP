#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

#include "core.h"

using namespace std;

//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/L
void newArray() {
	int n;
	cout << "Enter array size: ";
	cin >> n;

	vector<int>arrA(n);

	//input for array A
	cout << "\nInput for array A: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Number A" << i + 1 << ": ";
		cin >> arrA[i];
	}
	
	vector<int>arrB(n);

	//input for array B
	cout << "\nInput for array B: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Number B" << i + 1 << ": ";
		cin >> arrB[i];
	}

	//concatenating arrA with arrB
	for (int i = 0; i < n; i++) {
		arrB.push_back(arrA[i]);
	}

	//arrB.insert(arrB.end(), arrA.begin(), arrA.end());
	

	//display final array
	cout << "\nFinal concatenated array: " << endl;
	for (int i = 0; i < arrB.size(); i++) {
		cout << arrB[i] << " ";
	}
}

//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C
void replace() {
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>nums(n);
	
	//input
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		if (nums[i] > 0) {
			nums[i] = 1;
		}
		else if(nums[i] < 0){
			nums[i] = 2;
		}
		else {
			nums[i] = 0;
		}
	}

	//display final array
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
}


