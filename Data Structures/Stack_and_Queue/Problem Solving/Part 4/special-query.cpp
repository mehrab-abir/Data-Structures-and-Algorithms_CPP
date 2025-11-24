#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main() {
	int query;
	cout << "Number of queries: ";
	cin >> query;
	cin.ignore();

	queue<string>line;

	for (int q = 0; q < query; q++) {

		string command;
		cout << "Enter command: ";
		getline(cin, command);

		if (*command.begin() == '0') {
			string person = command.substr(2);
			line.push(person);
		}
		else{
			if (!line.empty()) {
				string frontMan = line.front();
				line.pop();
				cout << frontMan << endl;
			}
			else {
				cout << "Invalid" << endl;
			}
		}
	}

	return 0;
}
