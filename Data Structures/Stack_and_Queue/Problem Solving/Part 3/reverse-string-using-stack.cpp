#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>

using namespace std;

//https://www.naukri.com/code360/problems/kevin-s-stack-problem_1169465

int main() {

	string str;
	cout << "Enter the string: ";
	getline(cin, str);

	stack<char>st;

	for (char c : str) {
		st.push(c);
	}

	str.clear();

	while (!st.empty()) {
		str += st.top();
		st.pop();
	}

	cout << "\nString: "<<str<<endl;

	return 0;
}
