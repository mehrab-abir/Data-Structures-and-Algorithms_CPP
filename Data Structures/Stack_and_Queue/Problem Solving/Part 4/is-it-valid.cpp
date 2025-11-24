#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int main() {

	int testCase;
	cout << "Number of test cases: ";
	cin >> testCase;
	cin.ignore();

	for (int t = 0; t < testCase; t++) {
		string str;
		cout << "Enter the string (0,1 only): ";
		getline(cin, str);

		stack<char>st;

		for (char c : str) {
			if (st.empty()) {
				st.push(c);
			}
			else {
				if (c == '0' && st.top() == '1') {
					st.pop();
				}
				else if(c == '1' && st.top() == '0') {
					st.pop();
				}
				else {
					st.push(c);
				}
			}
		}

		string newStr;

		while (!st.empty()) {
			newStr += st.top();
			st.pop();
		}


		if (newStr.empty()) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
		cout << endl;
	}
	
	cout << endl;

	return 0;
}
