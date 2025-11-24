#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>

/*
Take a queue of size N as input. You need to copy those elements in another queue in reverse order. You might use stack
here. You should use STL to solve this problem. After copying in another queue, print the elements of that queue.
*/

using namespace std;

int main() {

	queue<int>q;

	int n;
	cout << "Queue Size: ";
	cin >> n;

	//input for queue
	cout << "Input for queue: " << endl;
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		q.push(val);
	}

	stack<int>st;

	//copying queue elements to stack
	while (!q.empty()) {
		st.push(q.front());
		q.pop();
	}

	cout << endl;

	//printing the stack
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	return 0;
}