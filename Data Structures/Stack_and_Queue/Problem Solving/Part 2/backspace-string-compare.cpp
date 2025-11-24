#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>

using namespace std;

//https://leetcode.com/problems/backspace-string-compare/description/

int main() {
	string str_one;
	cout << "Enter first string: ";
	getline(cin,str_one);

	string str_two;
	cout << "Enter second string: ";
	getline(cin, str_two);

	stack<char>stack_one;
	stack<char>stack_two;

	for (char c : str_one) {
		if (c == '#') {
			stack_one.pop();
		}
		else {
			stack_one.push(c);
		}
	}

	for (char c : str_two) {
		if (c == '#') {
			stack_two.pop();
		}
		else {
			stack_two.push(c);
		}
	}

	if (stack_one == stack_two) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	

	return 0;
}