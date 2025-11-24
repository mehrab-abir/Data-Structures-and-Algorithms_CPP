#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<algorithm>

//https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571

using namespace std;

int getSum(stack<int>st) {
	int sum = 0;
	while (!st.empty()) {
		sum = sum + st.top();
		st.pop();
	}
	return sum;
}

int main() {
	stack<int>stack_one;
	stack<int>stack_two;
	stack<int>stack_three;

	int n1, n2, n3;

	cout << "Stack one size: ";
	cin >> n1;
	cout << "Stack two size: ";
	cin >> n2;
	cout << "Stack three size: ";
	cin >> n3;

	//input for stack one
	cout << "\nInput for Stack one: " << endl;
	for (int i = 0; i < n1; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		stack_one.push(val);
	}

	//input for stack two
	cout << "\nInput for Stack two: " << endl;
	for (int i = 0; i < n2; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		stack_two.push(val);
	}

	//input for stack three
	cout << "\nInput for Stack three: " << endl;
	for (int i = 0; i < n3; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		stack_three.push(val);
	}

	int sum1 = getSum(stack_one);
	int sum2 = getSum(stack_two);
	int sum3 = getSum(stack_three);

	while (true) {
		if (sum1 == sum2 && sum2 == sum3) {
			break;
		}

		if (sum1 >= sum2 && sum1 >= sum3) {
			sum1 = sum1 - stack_one.top();
			stack_one.pop();
		}
		else if (sum2 >= sum1 && sum2 >= sum3) {
			sum2 = sum2 - stack_two.top();
			stack_two.pop();
		}
		else {
			sum3 = sum3 - stack_three.top();
			stack_three.pop();
		}
	}

	cout << "Sum = " << sum1 << endl; //any of three sum

	

	return 0;
}