#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	//min priority queue
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ 10, 1 });
	pq.push({ 3, 6 });
	pq.push({ 5, 2 });
	pq.push({ 8, 4 });

	cout << pq.top().first << " " << pq.top().second << endl;
	
	/*
	priority queue gives priority to the first value of the pair, unless we specify using a
	custom compare function (cmp)
	*/

	return 0;
}