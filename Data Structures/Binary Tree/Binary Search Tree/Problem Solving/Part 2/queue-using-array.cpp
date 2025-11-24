#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Queue {
public:
	vector<int>v;

	void push(int value) {
		v.push_back(value);
	}
	void pop() {
		v.erase(v.begin());
	}
	int front() {
		return v.front();
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}
};

int main() {
	Queue q;

	while (true) {
		int value;
		cout << "Value: ";
		cin >> value;

		if (cin.fail()) {
			cout << "\tInvalid input. Enter a valid integer." << endl;;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (value == -1) {
			break;
		}
		q.push(value);
	}

	int size = q.size();
	cout << "Size = " << size << endl;

	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}