#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class myStack {
public:
	vector<int>stVector;

	void push(int val) {
		stVector.push_back(val); //--O(1)
	}
	void pop() {
		stVector.pop_back();  //--O(1)
	}
	int top() {
		return stVector.back();  //--O(1)
	}
	int size() {
		return stVector.size(); //--O(1)
	}
	bool empty() {
		return stVector.empty(); //--O(1)
	}
};

int main() {
	
	myStack st;

	int n;
	cout << "Enter stack size: ";
	cin >> n;

	//taking input for stack
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Enter number " << i + 1 << ": ";
		cin >> val;

		st.push(val);
	}

	//printing stack elements
	cout << "The stack: " << endl;
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	if (!st.empty()) {
		cout << "Top: " << st.top() << endl;
	}
	else {
		cout << "Stack is empty" << endl;
	}

	return 0;
}
