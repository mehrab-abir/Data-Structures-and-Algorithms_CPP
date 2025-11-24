#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void fun(int a) { //reference ashe nai, ai a er address different, at a er akta copy
	a = 50; //a er value change

	cout << "Inside fun(): a = " << a << endl;
	//a er value main function a change hobe na
}

void fun2(int &a) { //reference ashce
	a = 50; //a er value change

	cout << "Inside fun2(): a er address = " << &a << endl;
	cout << "Inside fun2(): a = " << a << endl;
	//a er value main function a change hobe
}

void funX(int* px) { //address of x or value of px is different here, px pointer er reference ashe nai
	px = NULL; //pointer changed
	cout << "Inside funX(): px = " << px << endl;
	//main function a change hobe na
}

void funXref(int* &px) { //address of x or value of px is same here, px pointer er reference ashche
	px = NULL; //pointer changed
	cout << "Inside funXref(): px = " << px << endl;
	//main function a change hobe
}


int main() {
	int a = 10;
	int* pa = &a;
	
	//working with value
	fun(a);

	cout << "After function call, in main(): a = " << a << endl; //no change

	cout << endl<<endl;

	cout << "Inside main function: a er address: " << &a << endl;
	fun2(a); //a er reference gese, see fun2()
	cout << "After function fun2() call, in main(): a = " << a << endl;
	//value of a is changed here, beacuse 'a' er reference patano hoise
	//fun2 function a parameter a &a lekha hoise, er mane reference


	//working with pointer
	cout << endl << endl;
	int x = 100;
	int* px = &x;
	cout << "In main, before calling funX: address of x/&x/px = " << px << endl;

	funX(px); 
	cout << "In main, after calling funX: address of x/&x/px = " << px << endl;
	//akhane, funX er vitore pointer change hoile o main function a atar reflection hoyni, karon px er akta copy gese funX function a, address/reference jay ni

	cout << endl << endl;
	funXref(px);
	cout << "In main, after calling funX with reference: address of x/&x/px = " << px << endl; 
	//in this case, we passed the reference of the pointer, so the updation of the pointer inside funXref function is reflected in the main function, funXref() er parameter a px er age & sign deya hoise,   (int* &px),, avabe dite hoy jodi chai pointer er change main function a o houk

	return 0;
}