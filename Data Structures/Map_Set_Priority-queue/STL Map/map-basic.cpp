#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {

	map<string, int>mp; //string -> key, int -> value(for count)
	mp["Football"] = 100;
	mp["Badminton"] = 4;
	mp["Hocky"] = 1;
	mp["Tennis"] = 6;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	//1 ta value insert korar complexity O(logn) --for n values -> O(nlogn)
	//1 ta value print korar complexity O(logn) --for n values -> O(nlogn)

	//cout << mp["Tiger"] << endl;  //0

	if (mp.count("Tiger")) {
		cout << "Tiger ache" << endl;
	}
	else {
		cout << "Tiger nai" << endl;
	}

	return 0;
}