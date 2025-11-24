#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;

class myStack {
public:
	list<int>stList;

	void push(int val) {
		stList.push_back(val); //--O(1)
	}
	void pop() {
		stList.pop_back(); //--O(1)
	}
	int top() {
		return stList.back(); //--O(1)
	}
	int size() {
		return stList.size(); //--O(1)
	}
	bool empty() {
		return stList.empty(); //--O(1)
	}
};

void printStack(myStack& st) {
	myStack tempStack; //temporary stack to retain original stack

	while (!st.empty()) {
		cout << st.top() << endl;
		tempStack.push(st.top());
		st.pop();
	}

	//restoring original stack- copy all elements from tempStact to st
	while (!tempStack.empty()) {
		st.push(tempStack.top());
		tempStack.pop(); //seleting temporary stack to free memory
	}
}

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

	printStack(st);

	//original stack remains as it is
	if (!st.empty()) {
		cout << "Top: " << st.top() << endl;
	}
	else {
		cout << "Stack is empty" << endl;
	}

	return 0;
}