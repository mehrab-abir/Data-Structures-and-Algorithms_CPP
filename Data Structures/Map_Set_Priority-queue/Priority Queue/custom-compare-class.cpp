#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>

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
			if (l.roll > r.roll) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

int main() {
	priority_queue<Student, vector<Student>,cmp>stpq;

	int n;
	cout << "Number of students: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin.ignore();
		cout << "Student " << i + 1 << ":" << endl;
		string name;
		cout << "Name: ";
		getline(cin, name);

		int roll, marks;
		cout << "Roll: ";
		cin >> roll;
		cout << "Marks: ";
		cin >> marks;

		Student st(name, roll, marks);

		stpq.push(st);
		cout << endl;
	}

	int i = 1;

	while (!stpq.empty()) {
		cout << "Student " << i << " >>" << endl;
		cout << "Name: " << stpq.top().name << endl;
		cout << "Roll: " << stpq.top().roll << endl;
		cout << "Marks: " << stpq.top().marks << endl;
		stpq.pop();
		i++;
		cout << endl;
	}

	return 0;
}