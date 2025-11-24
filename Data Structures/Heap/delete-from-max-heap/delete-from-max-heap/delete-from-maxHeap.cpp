#define _CRT_SECURENO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//Complexity of deleting one element from max heap -- O(logN)

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

void delete_from_maxHeap(vector<int>& v) {
	cout << "\t" << v[0] << " deleted." << endl;

	v[0] = v.back(); //keeping the last value to the first index
	v.pop_back();

	int parentIdx = 0;

	while (true) {
		int leftIdx = parentIdx * 2 + 1;
		int rightIdx = parentIdx * 2 + 2;
		int leftValue, rightValue;

		//checking if left index and right index exist or not
		if (leftIdx < v.size()) {
			leftValue = v[leftIdx];
		}
		else {
			leftValue = INT_MIN; //if left idx does not exist, assign it the smallest number
		}

		if (rightIdx < v.size()) {
			rightValue = v[rightIdx];
		}
		else {
			rightValue = INT_MIN; //if right idx does not exist, assign it the smallest number
		}

		if (leftValue > v[parentIdx] && leftValue > rightValue) {
			swap(v[leftIdx], v[parentIdx]);
			parentIdx = leftIdx; // left index of this iteration becomes parentIndex for the next interation
		}
		else if (rightValue > v[parentIdx] && rightValue > leftValue) {
			swap(v[rightIdx], v[parentIdx]);
			parentIdx = rightIdx; // right index of this iteration becomes parentIndex for the next interation
		}
		else {
			break;
		}
	}
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

	delete_from_maxHeap(v);
	print_maxHeap(v);

	delete_from_maxHeap(v);
	print_maxHeap(v);

	return 0;
}
