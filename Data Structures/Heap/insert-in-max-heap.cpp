#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//complexity of inserting one value -- O(logN),,as it traverse through height of the tree
//for n value --O(nlogn)
//to retrieve the max value (root) - O(1)....but for array, it can be O(n^2logn) due to sorting n times
// sort() - O(nlogn),,sort an array n times -- O(n^2logn)..that's why heap is better in this case

int main() {
	int n;
	cout << "Size of the max-heap array: ";
	cin >> n;

	vector<int>maxHeap(n);

	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> maxHeap[i];
	}
	cout << endl;

	cout << "The max heap array: ";
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

		if (maxHeap[childIdx] > maxHeap[parentIdx]) {
			swap(maxHeap[childIdx], maxHeap[parentIdx]);
		}
		else {
			break;
		}

		childIdx = parentIdx;  //parentIdx of previous iteration becomes the childIdx for next iteration 
	}

	cout << "\nAfter inserting " << value << ", the max heap array: ";
	for (int val : maxHeap) {
		cout << val << " ";
	}


	cout << endl;

	return 0;
}
