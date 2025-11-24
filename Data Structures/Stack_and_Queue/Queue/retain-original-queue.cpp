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

	queue<int>tempQ; //temprary queue

	//print whole queue 
	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";

		tempQ.push(q.front()); //copy all items to temporary queue

		q.pop();
	}
	cout << endl;

	while (!tempQ.empty()) {
		q.push(tempQ.front());
		tempQ.pop();
	}


	//print original queue
	cout << "The queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	return 0;
}