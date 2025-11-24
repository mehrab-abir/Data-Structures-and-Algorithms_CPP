#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//children are greater than parent node or equal for min heap

//formula for childIndex: left child = parentIdx * 2 + 1, right child = parentIdx * 2 + 2
//formula for parentIdx = (childIdx - 1)/2

int main() {
	int n;
	cout << "Size of the min-heap array: ";
	cin >> n;

	vector<int>maxHeap(n);

	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> maxHeap[i];
	}
	cout << endl;

	cout << "The min heap array: ";
	for (int val : maxHeap) {
		cout << val << " ";
	}
	cout << endl << endl;

	int value;
	cout << "Enter a number to insert: ";
	cin >> value;

	maxHeap.push_back(value); //first step- insert at end, then compare it with parent

	int childIdx = maxHeap.size() - 1; //index of child, we need parent, so get parent index using formula

	while (childIdx != 0) {
		int parentIdx = (childIdx - 1) / 2;  //index of parent node

		if (maxHeap[childIdx] < maxHeap[parentIdx]) {
			swap(maxHeap[childIdx], maxHeap[parentIdx]);
		}
		else {
			break;
		}

		childIdx = parentIdx;  //parentIdx of previous iteration becomes the childIdx for next iteration 
	}

	cout << "\nAfter inserting " << value << ", the min heap array: ";
	for (int val : maxHeap) {
		cout << val << " ";
	}


	cout << endl;

	return 0;
}