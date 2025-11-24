#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector> 
#include<algorithm> //to use replace() and find()

using namespace std;

int main() {
	list<int>myList = { 5,3,6,7,1,5,2,6,4,6,10 };

	//print list items using iterator
	cout << "myList items: ";
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << " ";
	}



	cout << endl;
	return 0;
}
