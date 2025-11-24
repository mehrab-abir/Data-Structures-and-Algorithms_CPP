#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//bottom up
//Complexity O(N)

int main() {

	long long int n;
	cout << "Enter a number: ";
	cin >> n;

	vector<long long int>fibo(n+1);

	for (long long int i = 0; i <= n; i++) {

		if (i == 0) {
			fibo[i] = 0;
		}
		else if (i == 1) {
			fibo[i] = 1;
		}
		else {
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}

		cout << fibo[i] << " "; //printing fibonacci number
	}
	cout << endl;

	cout << "\nFibonacci value of "<<n<<": " << fibo[n] << endl;

	return 0;
}
