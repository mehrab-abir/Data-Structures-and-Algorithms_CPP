#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include<sstream>
#include<map>

using namespace std;

int main() {
	int testCase;
	cout << "Number of test cases: ";
	cin >> testCase;
	cin.ignore();

	for (int t = 0; t < testCase; t++) {
		string str;
		cout << "Type the sentence: ";
		getline(cin, str);

		map<string, int>mp;

		stringstream ss(str);
		string word;

		int maxCount = -1;
		string ans;

		while (ss >> word) {
			mp[word]++;

			if (maxCount < mp[word]) {
				maxCount = mp[word];
				ans = word;
			}
		}

		cout << ans << " " << maxCount << endl;
		cout << endl;
	}

	return 0;
}