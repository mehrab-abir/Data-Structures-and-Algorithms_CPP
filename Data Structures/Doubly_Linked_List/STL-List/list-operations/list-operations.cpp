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

	/*
	
	//remove a value- if there are multiple same values, it removes all of them
	myList.remove(6); //removes all 6

	cout << "myList items after removing 6: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	*/
	//-----------------------------------------------------------------------------------------------




	/*
	//sort the list
	myList.sort();

	cout << "myList items after sorting in ascending order: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;

	//sort in descending order
	myList.sort(greater<int>());

	cout << "myList items after sorting in descending order: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/


	/*
	
	//remove duplicate values, it works only for sorted list
	myList.sort();

	myList.unique();
	
	cout << "myList items after removing duplicate values: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//------------------------------------------------------------------------------------------


	/*
	//reverse a list
	myList.reverse();
	cout << "myList items after reversing: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//------------------------------------------------------------------------------------------



	cout << endl;
	return 0;
}
