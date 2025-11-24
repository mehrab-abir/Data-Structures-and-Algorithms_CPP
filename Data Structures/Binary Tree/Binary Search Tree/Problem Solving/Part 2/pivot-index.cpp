#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/find-pivot-index/description/

int main() {
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "> ";
		cin >> nums[i];
	}

	//Prefix Sum
	vector<int>prefixSum(n);
	prefixSum[0] = nums[0];

	for (int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + nums[i];
	}

	int pivotIndex = 0;

	int i;
	for (i = 0; i < n; i++) {
		int leftSum, rightSum;

		if (i == 0) {
			leftSum = 0;
			rightSum = prefixSum[n - 1] - prefixSum[0];
		}
		else if (i == nums.size() - 1) {
			leftSum = prefixSum[nums.size() - 2];
			rightSum = 0;
		}
		else {
			leftSum = prefixSum[i-1];
			rightSum = prefixSum[n - 1] - prefixSum[i];
		}
		

		if (leftSum == rightSum) {
			pivotIndex = 1;
			break;
		}
	}

	if (pivotIndex == 1) {
		cout << "Pivot index = " << i << endl;
	}
	else {
		cout << "-1" << endl;
	}
	


	return 0;
}