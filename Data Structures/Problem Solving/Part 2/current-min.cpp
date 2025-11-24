#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/give-max-min

int main() {

	priority_queue<int, vector<int>,greater<>>pq;

	int n;
	cout << "Size of the list: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cout << i + 1 << "> ";
		cin >> value;

		pq.push(value);
	}
	
	int q;
	cout << "Number of queries: ";
	cin >> q;
	cin.ignore();

	for (int i = 0; i < q; i++) {
		string command;
		cout << "Enter command: ";
		getline(cin, command);

		if (*command.begin() == '0') {
			string value;

			if (command[2] == '-') {
				value = command.substr(3);
			}
			else {
				value = command.substr(2);
			}

			int num = 0;
			for (char c : value) {
				int digit = c - '0';
				num = num * 10 + digit;
			}

			if (command[2] == '-') {
				pq.push(-num);
			}
			else {
				pq.push(num);
			}

			cout << pq.top() << endl;
		}
		else if (*command.begin() == '1') {
			if (!pq.empty()) {
				cout << pq.top() << endl;
			}
			else {
				cout << "Empty" << endl;
			}
		}
		else if (*command.begin() == '2') {
			if (!pq.empty()) {
				pq.pop();
				if (!pq.empty()) {
					cout << pq.top() << endl;
				}
				else {
					cout << "Empty" << endl;
				}
			}
			else {
				cout << "Empty" << endl;
			}
		}
		else {

		}
	}

	return 0;
}
