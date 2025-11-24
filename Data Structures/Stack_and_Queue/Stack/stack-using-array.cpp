#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class myStack {
public:
	vector<int>stVector;

	void push(int val) {
		stVector.push_back(val); //O(1)-- horizontal array ke anit-clock wise ghurale array er back stack er top hoye jay
	}
	void pop() {
		stVector.pop_back(); //O(1)--horizontal array ke anit-clock wise ghurale array er back stack er top hoye jay
	}
	int top() {
		return stVector.back(); //O(1)--horizontal array ke anit-clock wise ghurale array er back stack er top hoye jay
	}
	int size() {
		return stVector.size(); //O(1)
	}
	bool empty() {
		return stVector.empty(); //O(1)--empty hole true r na hole false return korbe
	}
};

int main() {
	myStack st;
	st.push(10);
	st.push(20);
	st.push(30);

	//corner/edge case should be handled before poping or accessing top
	if (st.empty() == false) {
		cout << "Top = " << st.top() << endl;
	}
	else {
		cout << "Accessing top is not possible. Stack is empty" << endl;
	}
	
	//get size of the stack
	cout << "Size = " << st.size() << endl;


	//check if empty or mot
	if (st.empty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}
	
	//corner/edge case should be handled before poping or accessing top
	if (st.empty() == false) {
		st.pop();
	}
	else {
		cout << "Pop is not possible. Stack is empty" << endl;
	}

	//access top
	//stack empty hole st.empty == true hobe, tar age 'not' operator dile false hobe 
	//tar mane, if 'false' hole, ortath, stack empty na hole pop korbe/top access korbe
	if (!st.empty()) {
		cout << "After Poping once: Top = " << st.top() << endl;
	}
	else {
		cout << "Accessing top is not possible. Stack is empty" << endl;
	}

	//push again
	st.push(100);

	//access top
	if (!st.empty()) {
		cout << "After pushing 100 again: Top = " << st.top() << endl;
	}
	else {
		cout << "Accessing top is not possible. Stack is empty" << endl;
	}
	

	return 0;
}
