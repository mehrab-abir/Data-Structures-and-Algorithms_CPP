#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>

using namespace std;

//STL for doubly linked list

int main() {

	//construct a list without declaring size, O(1)
	
	/*
	list<int>myList;

	int size;
	cout << "Enter size: ";
	cin >> size;

	for (int i = 1; i <= size; i++) {
		int value;
		cout << "Enter number "<<i<<": ";
		cin >> value;
		myList.push_back(value);
	}
	cout << endl;

	for (int num : myList) {
		cout << num << " ";
	}
	
	*/
	//------------------------------------------------------------------------------------------------
	

	//myList.push_back(10);  //insert_at_tail
	//myList.push_back(20);
	//myList.push_front(5); //insert_at_head
	

	//access first and last item
	/*
	cout << "First item: "<< myList.front() << endl;
	cout << "Last item: " << myList.back() << endl;
	
	*/
	
	//printing list using iterator
	/*
	cout << "List elements: ";
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << " "; //iterator is a pointer, so we need to dereference it
	}
	
	*/
	//------------------------------------------------------------------------------------------------
	
	cout << endl;

	//construct a list with size -- O(N)
	/*
	
	int n;
	cout << "Enter size: ";
	cin >> n;

	list<int>numbers(n);

	auto it = numbers.begin();
	for (int i = 0; i < n; i++) {
		cout << "Enter number " << i+1 << ": ";
		cin >> *it; //in vector, we can use index, but list does not have index, it has iterator
		it++;
	}
	//------------------------------------------------------------------------------------------------

	//printing list elements using range based for loop
	cout << "List elements: ";
	for (int item : numbers) {
		cout << item << " ";
	}
	*/
	//------------------------------------------------------------------------------------------------
	

	//another method to declare a list -- O(N)
	/*
	list<int>nums(5, 2); //there will be 5 items, all are 2
	
	for (int item : nums) {
		cout << item << " ";
	}
	*/
	//------------------------------------------------------------------------------------------------

	//Construct a list by copying another list list2.
	/*
	
	list<int>list_1 = { 5,10,8,6,7 };
	list<int>list_2(list_1); //list_1 will be copied into list 2


	cout << "List 1: ";
	for (int item : list_1) {
		cout << item << " ";
	}

	cout << endl;

	cout << "List 2: ";
	for (int item : list_2) {
		cout << item << " ";
	}
	
	*/
	//------------------------------------------------------------------------------------------------




	//Construct a list by copying all elements from an array A of size N.
	/*
	int arr[5] = { 5,4,1,9,3 };
	list<int>List(arr, arr + 5); //all items of array will be copied into the List

	cout << "List items: ";
	for (int item : List) {
		cout << item << " ";
	}

	cout << endl;

	cout << "Array items: ";
	for (int item : arr) {
		cout << item << " ";
	}
	
	*/
	//------------------------------------------------------------------------------------------------

	//Construct a list by copying all elements from a vector v.
	/*
	vector<int>vector_numbers = { 6,10,5,8,3 };
	list<int>List(vector_numbers.begin(), vector_numbers.end());

	cout << "List items: ";
	for (int item : List) {
		cout << item << " ";
	}

	cout << endl;

	cout << "Vector items: ";
	for (int item :vector_numbers) {
		cout << item << " ";
	}
	
	*/
	
	

	cout << endl;
	return 0;
}
