#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void insert_at_heap(int value, vector<int>&maxHeap) {
	maxHeap.push_back(value);

	int curIndx = maxHeap.size() - 1;

	while (curIndx != 0) {
		int parentIndx = (curIndx - 1) / 2;

		if (maxHeap[parentIndx] < maxHeap[curIndx]) {
			swap(maxHeap[parentIndx], maxHeap[curIndx]);
		}
		else {
			break;
		}

		curIndx = parentIndx;
	}
}

int pop(vector<int>&maxHeap) {
	int deletedItem = maxHeap[0];
	maxHeap[0] = maxHeap.back();
	maxHeap.pop_back();

	if (maxHeap.empty()) {
		return deletedItem;
	}

	int parentIndx = 0;

	while (true) {
		int leftIndx = parentIndx * 2 + 1;
		int rightIndx = parentIndx * 2 + 2;
		int leftValue, rightValue;

		if (leftIndx < maxHeap.size()) {
			leftValue = maxHeap[leftIndx];
		}
		else {
			leftValue = INT_MIN;
		}

		if (rightIndx < maxHeap.size()) {
			rightValue = maxHeap[rightIndx];
		}
		else {
			rightValue = INT_MIN;
		}

		if (leftValue >= maxHeap[parentIndx] && leftValue >= rightValue) {
			swap(maxHeap[leftIndx], maxHeap[parentIndx]);
			parentIndx = leftIndx;
		}
		else if(rightValue >= maxHeap[parentIndx] && rightValue >= leftValue) {
			swap(maxHeap[rightIndx], maxHeap[parentIndx]);
			parentIndx = rightIndx;
		}
		else {
			break;
		}
	}
	return deletedItem;
}

int main() {
	//vector<int>nums = { 1,5,3,4,9,2,16,8,13,6 };
	vector<int>nums = { 1,3,4,5,5,7,3 };
	vector<int>maxHeap;

	for (int value : nums) {
		insert_at_heap(value, maxHeap);
	}

	cout << endl;

	cout << "The max heap array: ";
	for (int value : maxHeap) {
		cout << value << " ";
	}

	cout << endl;

	vector<int>sorted;

	while (!maxHeap.empty()) {
		sorted.push_back(pop(maxHeap));
	}

	reverse(sorted.begin(), sorted.end());

	cout <<"\nAfter sorting: ";
	for (int value : sorted) {
		cout << value << " ";
	}

	cout << endl;


	return 0;
}