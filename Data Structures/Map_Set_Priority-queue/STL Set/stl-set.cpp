#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;

//set mainly duplicate remove kore, and sort kore rakhe....balanced binary search tree, inorder traversal...

int main() {
	set<int>s;

	int n;
	cout << "Size: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		int value;
		cout << i + 1 << "> ";
		cin >> value;

		s.insert(value);  //logn
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	if (s.count(5)) {
		cout << "5 ache" << endl;  //logn
	}
	else {
		cout << "5 nai" << endl;
	}

	return 0;
}
