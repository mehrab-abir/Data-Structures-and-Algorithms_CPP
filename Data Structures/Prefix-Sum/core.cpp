#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

#include "core.h"

using namespace std;

//Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y
//this solution for this problem will work, but won't be accepted in codeforces due to TLE
//without using prefix sum
void rangeSumQuery() {
	int n, q;
	cout << "Number of elements: ";
	cin >> n;

	vector<int>arr(n + 1);

	//input numbers for array
	for (int i = 1; i <= n; i++) {
		cout << "Number " << i << ": ";
		cin >> arr[i];
	}

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

		cout << "Sum = " << sum << endl << endl;
	}

}

//Using Prefix sum concept---Optimized solution for range sum query, less time complexity
void rangeSumQueryOptimized() {
	int n, q;
	cout << "Number of elements: ";
	cin >> n;

	vector<long long int>arr(n + 1); //using 1-based indexing

	//input numbers for array
	//index starts from 1
	for (int i = 1; i <= n; i++) {
		cout << "Number " << i << ": ";
		cin >> arr[i];
	}

	cout << "Number of query pairs: ";
	cin >> q;

	vector<long long int>prefixSum(n+1);

	//calculating prefix sum

	prefixSum[1] = arr[1];	//first element remains as it is
	for (int i = 2; i <= n; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	}

	for (int i = 0; i < q; i++) {
		long long int left, right, sum = 0;

		cout << "Query pair " << i + 1 << ": "<<endl;
		cout << "Left index of query pair: ";
		cin >> left;

		cout << "Right index of query pair: ";
		cin >> right;

		if (left == 1) {
			sum = prefixSum[right];
		}
		else {
			sum = prefixSum[right] - prefixSum[left - 1];
		}
		cout << "Sum = " << sum << endl << endl;
	}
}