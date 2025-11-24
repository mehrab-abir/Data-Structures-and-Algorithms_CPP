#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//Optimized using dynamic programming - Complexity O(N)

int getFibonacci(int n, vector<int>& memo) {
	if ( n == 0|| n == 1) {
		return n;
	}
	if (memo[n] != -1) {
		return memo[n];
	}

	memo[n] = getFibonacci(n - 1,memo) + getFibonacci(n - 2, memo);
	return memo[n];
}

int main() {

	int n;
	cout << "Enter a number: ";
	cin >> n;

	vector<int>memo(n+1,-1); //initializing with -1, will be updated inside getFibonacci function

	int fiboValue = getFibonacci(n,memo);

	cout << "Fibonacci value of " << n << ": " << fiboValue << endl;

	return 0;
}