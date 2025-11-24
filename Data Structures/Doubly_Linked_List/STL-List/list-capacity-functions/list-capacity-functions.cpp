#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list> // to use list
#include<vector> //for vector only

using namespace std;

int main() {
	list<int>myList = { 5,3,6,7,1,2 };

	//cout << "Size = " << myList.size();


	//to clear a list
	/*
	myList.clear(); //size 0
	cout << "Size = " << myList.size();
	
	*/
	//----------------------------------------------------------------------------------

	/*
	//myList.clear(); //after clearing the list, list will be empty, size 0

	if (myList.empty()) {   //empty() returns true or false
		cout << "List is empty" << endl;
	}
	else {
		cout << "Not empty" << endl;
	}
	
	*/
	

	//resize the lits
	//myList.resize(4);
	myList.resize(8); //the extra value will be 0


	cout << "List items: ";
	for (int item : myList) {
		cout << item << " ";
	}
	

	cout << endl;
	return 0;
}
