#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

//https://leetcode.com/problems/min-stack/description/
//must implement with O(1) time complexity for each function
class Stack {
public:
    stack<int>st, minStk;

    void push(int val) {
        st.push(val);

        if (minStk.empty()) {
            minStk.push(val);
        }
        else {
            if (val <= minStk.top()) {
                minStk.push(val);
            }
        }
    }

    void pop() {
	st.pop();
	    
        if (st.top() == minStk.top()) {
            minStk.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStk.top();
    }
};


int main() {
	Stack st;

	int n;
	cout << "Stack size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << "Number " << i + 1 << ": ";
		cin >> val;

		st.push(val);
	}

	int minStack = st.getMin();
	cout << "\nMin Stack = " << minStack << endl;

	return 0;
}
