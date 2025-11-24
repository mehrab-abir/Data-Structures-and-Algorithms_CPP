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

	vector<int>runningSum(n);

	runningSum[0] = arr[0];

	//running sum/ prefix sum
	for (int i = 1; i < n; i++) {
		runningSum[i] = runningSum[i - 1] + arr[i];
	}

	//running sum array
	cout << "\nThe running sum array: ";
	for (int j = 0; j < n; j++) {
		cout << runningSum[j] << " ";
	}
	cout << endl;


	return 0;
}