#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
/*
 Take two stacks of size N and M as input and check if both of them are the same or not.
 Don’t use STL to solve this problem.
*/
class Stack {
public:
	vector<int>stVector;

	void push(int val) {
		stVector.push_back(val);
	}
	void pop() {
		stVector.pop_back();
	}
	int top() {
		return stVector.back();
	}
	int size() {
		return stVector.size();
	}
	bool empty() {
		return stVector.empty();
	}
};

int main() {
	Stack st1, st2;

	int n,m;
	cout << "Size of the first stack: ";
	cin >> n;

	//input for first stack
	cout << "\nInput for first stack: "<< endl;
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st1.push(val);
	}
	cout << endl;

	cout << "\nSize of the second stack: ";
	cin >> m;

	//input for second stack
	cout << "\nInput for second stack: " << endl;
	for (int i = 0; i < m; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st2.push(val);
	}

	int isSame = 1;

	if (m != n) {
		cout << "Not same" << endl;
	}
	else {
		while (!st1.empty() && !st2.empty()) {
			if (st1.top() != st2.top()) {
				isSame = 0;
				break;
			}
			else {	
				st1.pop();
				st2.pop();
			}
		}

		if (isSame == 1) {
			cout << "Both stacks are same" << endl;
		}
		else {
			cout << "Not same" << endl;
		}
	}


	return 0;
}
