#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/1521560440/

int main() {
	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "> ";
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	cout << "Max product of two elements i and j -> (v[i]-1) * (v[j]-1): " << (v[0] - 1) * (v[1] - 1) << endl;

	return 0;
}