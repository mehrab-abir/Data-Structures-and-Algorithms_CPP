#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cout << "Enter array size: ";
	cin >> n;

	vector<int>arr(n);

	for (int i = 0; i < n; i++) {
		cout << "Enter number " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "The array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int>prefixSum(n);

	prefixSum[0] = arr[0];

	//prefix sum
	for (int i = 1; i < n; i++) {
		prefixSum[i] =prefixSum[i - 1] + arr[i];

	}

	int found = 0;
	int i;

	for ( i= 1; i < n; i++) {
		int lowerIndexSum = prefixSum[i - 1];
		int higherIndexSum = prefixSum[n - 1] - prefixSum[i];

		if (lowerIndexSum == higherIndexSum) {
			found = 1;
			break;
		}
	}

	if (found == 1) {
		cout << "Equilibrium index : " << i << endl;
	}
	else {
		cout << "There is no such index" << endl;
	}


	return 0;
}