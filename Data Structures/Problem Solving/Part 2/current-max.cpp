#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Student {
public:
	string name;
	int roll;
	int marks;

	Student(string name, int roll, int marks) {
		this->name = name;
		this->roll = roll;
		this->marks = marks;
	}
};

class cmp {
public:
	bool operator()(Student l, Student r) {
		if (l.marks < r.marks) {
			return true;
		}
		else if (l.marks > r.marks) {
			return false;
		}
		else {
			return l.roll > r.roll;
		}
	}
};

int main() {
	
	priority_queue<Student, vector<Student>,cmp>pq;

	int n;
	cout << "Number of students: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Student " << i + 1 << ">>> " << endl;

		string name;
		int roll, marks;
		
		cout << "Name: ";
		cin >> name;
		cout << "Roll: ";
		cin >> roll;
		cout << "Marks: ";
		cin >> marks;

		Student obj(name, roll, marks);

		pq.push(obj);
		cout << endl;
	}

	int q;
	cout << "Number of queries: ";
	cin >> q;
	cin.ignore();

	for (int i = 0; i < q; i++) {
		int command;
		cin >> command;

		if (command == 0) {
			string name;
			int roll;
			int marks;
			cin >> name >> roll >> marks;
			Student obj(name, roll, marks);
			pq.push(obj);

			cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
		}
		else if (command == 1) {
			if (!pq.empty()) {
				cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
			}
			else {
				cout << "Empty" << endl;
			}
		}
		else if (command == 2) {
			if (!pq.empty()) {
				pq.pop();
				if (!pq.empty()) {
					cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
				}
				else {
					cout << "Empty" << endl;
				}
			}
			else {
				cout << "Empty" << endl;
			}
		}
		else {

		}
	}

	return 0;
}