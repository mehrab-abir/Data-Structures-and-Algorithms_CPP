#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void insert_at_heap(vector<int>& v, int value) {
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

void delete_from_heap(vector<int>&v) {

	v[0] = v.back();
	v.pop_back();

	int parentIdx = 0;

	while (true) {
		int leftIdx = parentIdx * 2 + 1;
		int rightIdx = parentIdx * 2 + 2;

		int leftValue, rightValue;

		if (leftIdx < v.size()) {
			leftValue = v[leftIdx];
		}
		else {
			leftValue = INT_MIN;
		}

		if (rightIdx < v.size()) {
			rightValue = v[rightIdx];
		}
		else {
			rightValue = INT_MIN;
		}

		if (leftValue > v[parentIdx] && leftValue > rightValue) {
			swap(v[leftIdx], v[parentIdx]);
			parentIdx = leftIdx;
		}
		else if (rightValue > v[parentIdx] && rightValue > leftValue) {
			swap(v[rightIdx], v[parentIdx]);
			parentIdx = rightIdx;
		}
		else {
			break;
		}
	}
	cout << endl;
}

void print_heap(vector<int>v) {
	cout << "The heap array: ";
	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	cout << "\n\tSample input, n = 6: 9,8,6,5,2,1 \n" << endl;

	int n;
	cout << "Array size: ";
	cin >> n;

	vector<int>v;

	for (int i = 0; i < n; i++) {
		int value;
		cout << i + 1 << ">";
		cin >> value;

		insert_at_heap(v, value); //max heap
	}

	print_heap(v);

	int nth;
	cout << "Value of n for nth highest: ";
	cin >> nth;

	if (nth <= n && nth > 0) {
		for (int i = 1; i < nth; i++) {
			delete_from_heap(v);
		}
		cout << "Value in " << nth << " highest position: " << v.front() << endl;
	}
	else {
		cout << "Invalid position." << endl;
	}

	


	/*int max1 = v.front();
	cout << "Highest = " << max1 << endl;

	delete_from_heap(v);
	int max2 = v.front();
	cout << "2nd highest = " << max2 << endl;

	delete_from_heap(v);
	int max3 = v.front();
	cout << "3rd highest = " << max3 << endl;

	delete_from_heap(v);
	int max4 = v.front();
	cout << "4th highest = " << max4 << endl;*/
	

	return 0;
}