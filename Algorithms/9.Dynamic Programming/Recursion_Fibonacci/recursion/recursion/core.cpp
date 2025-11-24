#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

#include "core.h"

using namespace std;

int getSum(int i, int limit) {
	if(i > limit){
		return 0;
	}

	int sum = getSum(i + 1,limit);
	return sum + i;
}

void sum() {
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int s = getSum(1,n);

	cout << "Summation = " << s << endl;
}


//Factorial

int getFactorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * getFactorial(n - 1);
}

void factorial() {
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int ans = getFactorial(n);

	cout << "Factorial: " << ans << endl;
}

//Fibonacci - not optimized --  O(2^N);
int getFibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return getFibonacci(n - 1) + getFibonacci(n - 2);
}
void fibonacci() {
	int n;
	cout << "Enter a number to get its' fibonacci value: ";
	cin >> n;

	int ans = getFibonacci(n);
	cout << "Fibonacci value of " << n << ": " << ans << endl;
}