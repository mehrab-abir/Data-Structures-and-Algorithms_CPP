#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

//https://www.naukri.com/code360/problems/min-stack_3843991

class Stack {
public:
	stack<int>st;
	stack<int>minSt;


	// Function to add another element equal to num at the top of stack.
	void push(int num)
	{
		// Write your code here.
		st.push(num);

		if (minSt.empty()) {
			minSt.push(num);
		}

		if (num <= minSt.top()) {
			minSt.push(num);
		}
	}

	// Function to remove the top element of the stack.
	int pop()
	{
		// Write your code here.
		if (!st.empty()) {
			int topItem = st.top();

			if (st.top() == minSt.top()) {
				minSt.pop();
			}
			st.pop();
			return topItem;
		}
		else {
			return -1;
		}
	}

	// Function to return the top element of stack if it is present. Otherwise return -1.
	int top()
	{
		// Write your code here.
		if (!st.empty()) {
			return st.top();
		}
		else {
			return -1;
		}

	}

	// Function to return minimum element of stack if it is present. Otherwise return -1.
	int getMin()
	{
		if (!minSt.empty()) {
			return minSt.top();
		}
		else {
			return -1;
		}
	}

};

int main() {

	Stack st;

	int n;
	cout << "Stack size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i+1 << ": ";
		cin >> val;

		st.push(val);
	}

	st.pop();
	int minStack = st.getMin();
	cout << "Min stack: " << minStack << endl;

	return 0;
}
