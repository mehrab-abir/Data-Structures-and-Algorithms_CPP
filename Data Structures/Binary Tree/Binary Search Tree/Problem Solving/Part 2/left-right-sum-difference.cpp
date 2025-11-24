#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/left-and-right-sum-differences/description/

int main() {

	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "> ";
		cin >> v[i];
	}

	//Prefix sum
	vector<int>prefixSum(n);

	prefixSum[0] = v[0];

	for (int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + v[i];
	}

	//leftSum
	vector<int>leftSum(n);
	leftSum[0] = 0;
	
	for (int i = 1; i < n; i++) {
		leftSum[i] = prefixSum[i - 1];
	}
	
	cout << "Left_sum[]: ";
	for (int val : leftSum) {
		cout << val << " ";
	}
	cout << endl;
	
	//rightSum
	vector<int>rightSum(n);
	rightSum[n - 1] = 0;

	for (int i = 0; i < n-1; i++) {
		rightSum[i] = prefixSum[n - 1] - prefixSum[i];
	}
	cout << "Right_sum[]: ";
	for (int val : rightSum) {
		cout << val << " ";
	}
	cout << endl;


	//answer -- final array
	vector<int>answer(n);
	for (int i = 0; i < n; i++) {
		answer[i] = abs(leftSum[i] - rightSum[i]);
	}

	cout << "\nanswer[i] = leftsum[i] - rightsum[i]: ";
	for (int val : answer) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}