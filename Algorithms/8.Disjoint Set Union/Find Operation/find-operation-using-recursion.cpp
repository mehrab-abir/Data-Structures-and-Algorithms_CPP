#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

//find the ulmitate leader of a node/value

using namespace std;

int find_leader(int node, vector<int>& leaderArry) {
	if (leaderArry[node] == -1) {
		return node;
	}
	int leader = find_leader(leaderArry[node], leaderArry);
	return leader;
}

int main() {
	vector<int>leaderArry(100, -1);

	leaderArry[0] = 1;
	leaderArry[1] = -1;
	leaderArry[2] = 1;
	leaderArry[3] = 1;
	leaderArry[4] = 5;
	leaderArry[5] = 3;

	cout << find_leader(4, leaderArry) << endl;

	return 0;
}