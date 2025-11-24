#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cout << "Number of elements: ";
	cin >> n;

	vector<int>nums(n);

	cout << "Enter " <<n<<" numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	cout << endl<<"Numbers: ";
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";

	//linear search
	int numberToSearch;
	cout << "Enter a number to search: ";
	cin >> numberToSearch;

	bool found = false;
	int foundIndex;

	for (int i = 0; i < n; i++) {
		if (nums[i] == numberToSearch) {
			found = true;
			foundIndex = i;
			break;
		}
	}

	if (found) {
		cout << numberToSearch << " found in index " << foundIndex << endl;
	}
	else {
		cout << numberToSearch << " not found in the array" << endl;
	}



	return 0;
}