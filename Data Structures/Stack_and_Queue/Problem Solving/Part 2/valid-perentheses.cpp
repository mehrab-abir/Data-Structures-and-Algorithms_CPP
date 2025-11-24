#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>

using namespace std;

//https://leetcode.com/problems/valid-parentheses/description/

int main() {
	string brackets;
	cout << "Enter brackets: ";
	getline(cin, brackets);

	stack<char>st;

	for (char c : brackets) {
		if (c == '(' || c == '{' || c == '[') {
			st.push(c);
		}
		else {
			if (st.empty() == true) {
				cout << "Invalid" << endl;
				break;
			}
			else {
				if (c == ')' && st.top() == '(') {
					st.pop();
				}
				else if (c == '}' && st.top() == '{') {
					st.pop();
				}
				else if (c == ']' && st.top() == '[') {
					st.pop();
				}
				else {
					cout << "Invalid" << endl;
					break;
				}
			}
		}
	}

	if (st.empty() == true) {
		cout << "Valid" << endl;
	}



	return 0;
}