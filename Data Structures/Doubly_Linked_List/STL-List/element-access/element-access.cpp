#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector> 
#include<algorithm> //to use replace() and find()

using namespace std;

int main() {
	list<int>myList = { 5,3,6,7,1,5,2,6,4,6,10 };


	cout << "myList items: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;

	cout << "First item: " << myList.front()<<endl;
	cout << "Last item: " << myList.back() << endl;

	//specific item 
	cout << "Item of index 3: " << *next(myList.begin(), 3) << endl; //item of index 3



	cout << endl;
	return 0;
}
