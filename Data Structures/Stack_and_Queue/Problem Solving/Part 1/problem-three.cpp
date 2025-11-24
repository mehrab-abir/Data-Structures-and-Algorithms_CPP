#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

/*
Take a stack of size N as input and copy those elements to another stack to get the values in the order they were
inserted and print them. You should use STL to solve this problem.

*/

int main() {
	stack<int>st;

	int n;
	cout << "Size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st.push(val);
	}

	stack<int>stCpy;

	//copying original to the other stack
	while (!st.empty()) {
		stCpy.push(st.top());
		st.pop();
	}

	cout << endl << "The Stack: " << endl;
	//printing the new stack
	while (!stCpy.empty()) {
		cout << stCpy.top() << endl;
		stCpy.pop();
	}


	return 0;
}