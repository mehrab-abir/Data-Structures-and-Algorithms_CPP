#define _CRT_SECURENO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//input for max heap
void insert_at_maxHeap(int value, vector<int>& v) {
	v.push_back(value);

	int childIdx = v.size() - 1;

	while (childIdx != 0) {
		int parentIdx = (childIdx - 1) / 2;
		if (v[parentIdx] < v[childIdx]) {
			swap(v[parentIdx], v[childIdx]);
		}
		else {
			break;
		}
		childIdx = parentIdx;
	}
}

void print_maxHeap(vector<int>v) {
	cout << "The max heap array: ";
	for (int value : v) {
		cout << value << " ";
	}
	cout << endl;
}

int main() {
	cout << "Create a max heap array >>>> Input...Must be a complete binary tree:" << endl;
	int n;
	cout << "Size of the  max heap: ";
	cin >> n;

	vector<int>v;

	for (int i = 0; i < n; i++) {
		int value;
		cout << "Value " << i + 1 << ": ";
		cin >> value;

		insert_at_maxHeap(value, v);
	}
	cout << endl;

	print_maxHeap(v);

	return 0;
}
