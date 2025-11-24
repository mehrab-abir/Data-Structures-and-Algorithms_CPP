#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

/*
Take a stack of size N and a queue of size M as input. Then check if both of them are the same or not in the order of
removing. You should use STL to solve this problem.
*/

int main() {
	stack<int>st;
	queue<int>q;

	int stSize, qSize;

	cout << "Enter stack size: ";
	cin >> stSize;
	cout << "Enter queue size: ";
	cin >> qSize;

	if (stSize != qSize) {
		cout << "Not same" << endl;
	}
	else {
		//input for stack
		cout << "\Input for stack: " << endl;
		for (int i = 0; i < stSize; i++) {
			int val;
			cout << "Number " << i + 1 << ": ";
			cin >> val;

			st.push(val);
		}

		//input for queue
		cout << "\Input for queue: " << endl;
		for (int i = 0; i < qSize; i++) {
			int val;
			cout << "Number " << i + 1 << ": ";
			cin >> val;

			q.push(val);
		}

		int isSame = 1;

		while (!st.empty() && !q.empty()) {
			if (st.top() != q.front()) {
				isSame = 0;
				break;
			}
			else {
				st.pop();
				q.pop();
			}
		}

		if (isSame == 1) {
			cout << "Same" << endl;
		}
		else {
			cout << "Not same" << endl;
		}
	}
	
	return 0;
}