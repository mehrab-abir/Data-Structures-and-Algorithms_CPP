#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main() {

	stack<int>st;
	queue<int>q;

	int n, m;
	cout << "Stack size: ";
	cin >> n;
	cout << "Queue size: ";
	cin >> m;

	//stack input
	cout << "Input for stack: " << endl;
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st.push(val);
	}

	//Queue input
	cout << "Input for queue: " << endl;
	for (int i = 0; i < m; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		q.push(val);
	}

	if (n != m) {
		cout << "NO";
	}
	else {
		int isSame = 1;

		while (!st.empty()) {
			int stTop = st.top();
			int qFront = q.front();

			if (stTop != qFront) {
				isSame = 0;
				break;
			}
			else {
				st.pop();
				q.pop();
			}
		}

		if (isSame == 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}

	cout << endl;

	return 0;
}