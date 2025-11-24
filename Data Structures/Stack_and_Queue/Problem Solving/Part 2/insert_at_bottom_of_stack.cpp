#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

//https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

int main() {
	stack<int>st;

	int n;
	cout << "Stack size: ";
	cin >> n;

	for (int i = 0; i < n; i++ ) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st.push(val);
	}

	int number;
	cout << "Enter a number to insert at bottom: ";
	cin >> number;

	cout << endl;

	stack<int>newStack;

	//keeping all elements into new stack
	while (!st.empty()) {
		newStack.push(st.top());
		st.pop();
	}

	st.push(number); //push the number to the original stack

	//bring all elements back to the original stack from the new stack
	while (!newStack.empty()) {
		st.push(newStack.top());
		newStack.pop();
	}

	//print original stack
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}



	return 0;
}