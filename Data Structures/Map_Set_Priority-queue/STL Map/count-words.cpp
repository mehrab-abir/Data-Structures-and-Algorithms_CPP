#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

int main() {
	string str;
	cout << "Write something: ";
	getline(cin, str);

	stringstream ss(str);
	string word;

	map<string, int>mp;

	while (ss >> word) {
		mp[word]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << "Word : " << it->first << ", Number of appearance: " << it->second << endl;
	}

	cout << endl;
	//count one specific word
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->first == "Football") {
			cout << it->first << " " << it->second << " times" << endl;
		}
	}
	cout << endl;


	int arr[10] = { 2,5,4,2,6,9,5,5,4,1 };
	map<int, int>mpNums;

	for (int i = 0; i < 10; i++) {
		mpNums[arr[i]]++;
	}

	for (auto it = mpNums.begin(); it != mpNums.end(); it++) {
		cout << it->first << " appears " << it->second << " time(s)." << endl;
	}

	cout << endl;

	//count one specific number
	for (auto it = mpNums.begin(); it != mpNums.end(); it++) {
		if (it->first == 5) {
			cout << it->first << " appears " << it->second << " times" << endl;
		}
	}

	return 0;
}