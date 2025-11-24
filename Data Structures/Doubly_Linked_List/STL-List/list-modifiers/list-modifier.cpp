#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector> 
#include<algorithm> //to use replace() and find()

using namespace std;

int main() {
	list<int>myList = { 5,3,6,7,1,2,6,4,6,10 };

	/*
	//assigning a list to another list
	list<int>anotherList;

	//anotherList = myList; //or
	anotherList.assign(myList.begin(), myList.end());

	cout << "myList items: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;


	cout << "anotherList items: ";
	for (int item : anotherList) {
		cout << item << " ";
	}
	*/
	//---------------------------------------------------------------------------------------


	cout << "myList items: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;


	/*
	
	//insert at head
	myList.push_front(10);

	//insert_at_tail
	myList.push_back(50);
	
	cout << "myList items after inserting at head and tail: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	*/
	//---------------------------------------------------------------------------------------

	/*
	//delete head
	myList.pop_front();
	cout << "myList items after deleting head: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;


	//delete tail
	myList.pop_back();
	cout << "myList items after deleting tail: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//---------------------------------------------------------------------------------------



	/*
	
	//access a specific position
	cout << "Index 2: ";
	cout << *next(myList.begin(), 2); //it will print the value of index 2, must use dereference operator
	cout << "\nIndex 5: "<< *next(myList.begin(), 5);
	*/


	
	//insert at any position
	
	/*
	//myList.insert(next(myList.begin(), 2), 100); //insert 100 at index 2
	//myList.insert(next(myList.begin(), 4), 200); //insert 200 at index 4

	//insert another list to a list
	//list<int>list2 = { 300, 400 };

	//myList.insert(next(myList.begin(), 2), list2.begin(), list2.end());
	//this will insert the whole list 2 to the original list, at index 2

	//**************************************************************************

	//insert a vector to a list
	vector<int>v = { 1000, 2000 };

	myList.insert(next(myList.begin(), 3), v.begin(), v.end());
	//this will insert the whole vector to the original list, at index 3

	cout << "myList items after inserting a vector at middle: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//---------------------------------------------------------------------------------------------
	

	/*
	//delete from any specific position
	//myList.erase(next(myList.begin(), 2));

	//delete multiple values from middle
	myList.erase(next(myList.begin(), 2) , next(myList.begin(), 5));
	//this will delete items from index 2 to index 4, not 5, till before index 5

	cout << "myList items after deleting from index 2: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//---------------------------------------------------------------------------------------------

	/*
	//replace() -- not in STL, must include <algorithm> header file 
	replace(myList.begin(), myList.end(), 6, 50); //replace all 6 with 50

	cout << "myList items after replacing 6 with 50: ";
	for (int item : myList) {
		cout << item << " ";
	}
	cout << endl;
	
	*/
	//---------------------------------------------------------------------------------------------
	
	/*
	
	//find()-- not in STL, must include <algorithm> header file 
	auto findNumber = find(myList.begin(), myList.end(), 1000);
	
	if (findNumber != myList.end()) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not found" << endl;
	}
	*/
	//---------------------------------------------------------------------------------------------
	


	cout << endl;
	return 0;
}
