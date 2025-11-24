#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include "arrayOfString.h"

using namespace std;

int main() {

	//vector allocates memory dynamically

	//uses of every function inside separate comment block


	//vector declaration, input, output 1, starts ********************************************

	//declaring an array, taking input and displaying output, take size while declaring
	/*
	int n;
	cout << "Size of the array: ";
	cin >> n;

	vector<int>arr(n);

	//input
	for (int i = 0; i < n; i++) {
		cout << "Number " << i + 1 << ": ";
		cin >> arr[i];
	}

	//output
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	*/
	//vector declaration, input, output 1, ends *********************************************





	//method 2 starts  ***********************************************************************
	/*

	//another method, without taking array size in declaration
	vector<int>marks;

	int nStudent;

	cout << "Number of students: ";
	cin >> nStudent;

	//input
	for (int i = 0; i < nStudent; i++) {
		int mrk;
		cout << "Mark " << i + 1 << ": ";
		cin >> mrk;

		marks.push_back(mrk);
	}
	cout << endl;

	//displaying the array of marks
	for (int i = 0; i < nStudent; i++) {
		cout << "Mark " << i + 1 << ": " << marks[i] << endl;
	}

	*/

	//method 2 ends*******************************************************************************





	vector<int>numbers = { 2,5,6,3,8 };

	/*
	for (int num : numbers) {
		cout << num << " ";
	}
	*/




	//copy vector starts**********************************************************************

	/*
	//copy a vector to another vector
	vector<int>copyOfNumbers(numbers);

	cout << "After copying: ";
	for (int num : copyOfNumbers) {
		cout << num << " ";
	}
	*/
	//copy vector ends**********************************************************************





	//size starts **************************************************************************
	/*
	//size
	cout << "Size of the vector: "<< numbers.size()<<endl;
	*/
	//size ends ********************************************************************************






	//clear() function starts *********************************************************************
	/*
	//clear the values of the vector
	numbers.clear();  //size will be zero
	*/
	//clear function ends ************************************************************************




	//empty() function starts *********************************************************************
	/*
	//check if empty or not
	if (numbers.empty()) {			//returns true or false
		cout << "Empty";
	}
	else {
		cout << "Not empty";
	}
	*/
	//empty function ends *************************************************************************




	//resize() starts *****************************************************************************
	/*
	//resize
	numbers.resize(10);

	//taking input for new values
	for (int i = 5; i < 10; i++) {
		cout << "New item " << i + 1 << ": ";
		cin >> numbers[i];
	}

	cout << endl;

	cout << "After resizing: " << endl;
	for (int num : numbers) {
		cout << num << " ";
	}

	*/
	//resize() ends ********************************************************************************




	//assign vector starts *************************************************************************
	/*

	//assign a vector to another vector
	vector<int> digits = numbers;

	cout << "Vector digits: ";
	for (int value : digits) {
		cout << value << " ";
	}
	cout << endl;

	cout << "Vector numbers: ";  //it will remain as it is
	for (int num : numbers) {
		cout << num << " ";
	}

	*/
	//assign vector ends ****************************************************************************




	//push_back() starts ****************************************************************************
	/*
	//push an item in the end
	numbers.push_back(100);

	for (int num : numbers) {
		cout << num << " ";
	}
	*/
	//push_back() ends *******************************************************************************




	//pop_back() starts ********************************************************************
	/*
	//remove number from the end---pop_back
	numbers.pop_back();

	for (int num : numbers) {
		cout << num << " ";
	}
	*/
	//pop_back() ends ********************************************************************





	//insert() starts **************************************************************************
	/*
	//insert an item to a spefic position
	numbers.insert(numbers.begin() + 2, 50); //here, 50 is being inserted to index 2

	numbers.insert(numbers.begin() + 4, 70);

	for (int num : numbers) {
		cout << num << " ";
	}
	*/
	//insert() ends ****************************************************************************





	//delete() starts **************************************************************************
	/*
	//delete an element from a specific position
	numbers.erase(numbers.begin()+2); //value of index 2 will be erased

	for (int num : numbers) {
		cout << num << " ";
	}
	*/
	//delete() ends ****************************************************************************



	//replace() starts*******************************************************************************
	//replace() and find() are not in STL, so we have to use <algorithm> header file
	/*
	//replace a value
	replace(numbers.begin(), numbers.end(), 3, 100); //3 is replaced by 100, if there are multiple same values, all will be replaced, unless range is adjusted accordingly

	for (int num : numbers) {
		cout << num << " ";
	}

	*/
	//replace() ends *******************************************************************************




	//find() starts ****************************************************************************
	/*

	//find an element in an array
	auto it = find(numbers.begin(), numbers.end(), 6);

	if (it != numbers.end()) {
		cout << "Found at position(index): "<<distance(numbers.begin(), it) << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	*/
	//find() ends *******************************************************************************


	for (int num : numbers) {
		cout << num << " ";
	}
	cout << endl;


	//access last and first elements starts *******************************************************
	/*
	//access the last element
	int lastNum = numbers.back();

	//access the first element
	int firstNum = numbers.front();

	cout << "First element: " << firstNum << endl;
	cout <<"Last element: "<< lastNum;

	*/
	//access last and first elements ends *********************************************************




	//array of string using vector, code in a separate file
	arrayOfString();



	cout << endl;


	return 0;
}
