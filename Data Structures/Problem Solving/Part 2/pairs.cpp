#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class cmp {
public:
	bool operator()(pair<string, int>l, pair<string, int>r) {
		if (l.first > r.first) {
			return true;
		}
		else if (l.first < r.first) {
			return false;
		}
		else {
			return l.second < r.second;	
		}
	}
};

int main() {
	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>pq;

	int n;
	cout << "Size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cout << "String: ";
		cin >> str;

		int num;
		cout << "Number: ";
		cin >> num;

		pq.push({ str,num });
	}

	cout << endl;
	while (!pq.empty()) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	return 0;
}