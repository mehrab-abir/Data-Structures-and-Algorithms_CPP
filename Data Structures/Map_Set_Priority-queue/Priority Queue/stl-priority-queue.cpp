#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int main() {
	priority_queue<int>pq; //works like max_heap

	int n;
	cout << "Priority queue size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cout << i + 1 << "> ";
		cin >> value;

		pq.push(value);
	}
	cout << "\nPQ size = " << pq.size() << endl;

	//print pq
	cout << "The priority queue: ";
	while (!pq.empty()) {
		cout << pq.top() << " "; //pq.top() -> max value
		pq.pop(); //will remove the first value, which is the largest one
	}
	cout << endl << endl;


	priority_queue<int,vector<int>,greater<int>>minpq; //min heap
	//minpq.top() -> min value
	//minpq.pop() -> will remove the first value, which is the smallest one

	//input for minimum priority queue
	int m;
	cout << "Minimum Priority queue size: ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		int value;
		cout << i + 1 << "> ";
		cin >> value;

		minpq.push(value);
	}
	cout << "\nPQ size = " << minpq.size() << endl;

	//print pq
	cout << "The minimum priority queue: ";
	while (!minpq.empty()) {
		cout << minpq.top() << " "; //pq.top() -> min value
		minpq.pop(); //will remove the first value, which is the smallest one
	}
	cout << endl;

	return 0;
}
