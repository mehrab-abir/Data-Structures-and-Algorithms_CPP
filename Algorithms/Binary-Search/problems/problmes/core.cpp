#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "core.h"

using namespace std;


//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F
void reverseArray() {
	int n;
	cout << "Number of elements: ";
	cin >> n;

	vector<int>nums(n);

	//input
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> nums[i];
	}

	reverse(nums.begin(), nums.end());

	//reversed order
	for (int d : nums) {
		cout << d << " ";
	}
	cout << endl;
}

//Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/D
void countElements() {
	cout << "You are given an array of nintegers, count the number of element a[i] in the array such that a[i] + 1 is also exists in the array a. "<<endl<<"If there're duplicates in a , count them separately."<<endl;

	int n;
	cout << "Number of elements: ";
	cin >> n;

	vector<int>numbers(n);

	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> numbers[i];
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		int checkNum = numbers[i] + 1;
		auto it = find(numbers.begin(), numbers.end(), checkNum);

		if (it != numbers.end()) {
			count++;
		}
	}

	cout << "\nNumber of such elements: "<<count<<endl;
}

//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/J
void countLetters() {
	string str;
	cout << "Enter a string(lowercase only, without space): ";
	cin >> str;

	vector<int>freq(26, 0);//size 26, initializing all values with 0

	string::iterator i;
	for (i = str.begin(); i != str.end(); i++) {
		int index = *i - 'a';
		freq[index] = freq[index] + 1;
	}

	//final output
	for (int i = 0; i < 26; i++) {
		if (freq[i] != 0) {
			cout << char(i + 'a') << " : " << freq[i] << endl;
		}
	}
}
//aaabbc
// a : a -  'a' = a - 97 = 97 - 97 = 0,,index = 0, for freq array
//a>> freq[0] = 0+1 = 1
//a>> freq[0] = 1+1 = 2
//a>> freq[0] = 2+1 = 3************

// b : b - 'a' = b - 97 = 97 - 97 = 1,, index = 1, for freq array
//b>> freq[1] = 0+1 = 1
//b>> freq[1] = 1+1 = 2***********

//c>> freq[2] = 0+1 = 1***********

//red
// r : r - 'a' = r - 97 = 114 - 97 = 17,, index = 17, for freq array
// e : e - 'a' = e - 65 = 101 - 97 = 4,, index = 4, for freq array
// d : d - 'a' = d - 65 = 100 - 97 = 3,, index = 3, for freq array


//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y
//this solution for this problem will work, but won't be accepted in codeforces due to TLE
//Use Prefix Sum concept for optimized solution
void rangeSumQuery() {
	int n, q;
	cout << "Number of elements: ";
	cin >> n;

	vector<int>arr(n+1);

	//input numbers for array
	for (int i = 1; i <= n; i ++ ) {
		cout << "Number " << i << ": ";
		cin >> arr[i];
	}

	cout << "\n **The array uses 1-based indexing**\n\n";

	cout << "Number of query pairs: ";
	cin >> q;

	for (int i = 0; i < q; i++) {
		int left, right, sum = 0;

		cout << "Query pair " << i + 1 << ": " << endl;
		cout << "Left index of query pair: ";
		cin >> left;
		cout << "Right index of query pair: ";
		cin >> right;

		for (int j = left; j <= right; j++) {
			sum = sum + arr[j];
		}

		cout << "Sum = " << sum << endl<<endl;
	}

}
