#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue<int>q;

	int n;
	cout << "Enter size: ";
	cin >> n;

	//taking input
	for (int i = 0; i < n; i++) {
		int val;
		cout << "Enter number " << i + 1 << ": ";
		cin >> val;

		q.push(val);
	}

	cout << "\nSize = " << q.size() << endl;
	cout << "Front = " << q.front() << endl;

	cout << endl;

	//pop
	if (!q.empty()) {
		q.pop();
	}
	else {
		cout << "Queue is empty. POP is not possible" << endl;
	}

	//front
	if (!q.empty()) {
		cout << "\nAfter Poping once: Front = " << q.front() << endl;
	}
	else {
		cout << "Queue is empty.There is no front" << endl;
	}

	cout << "Size = " << q.size() << endl;


	//print whole queue 
	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << endl;

	return 0;
}