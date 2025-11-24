#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

//find the ulmitate leader of a node/value

using namespace std;

vector<int>leaderArry(100, -1); //declaring leader array globally, initializing with -1
vector<int>group_size(100, 1); //initially all values are isolated, so their size is 1

//Complexity O(logN)
int find_leader(int node) {
	if (leaderArry[node] == -1) {
		return node;
	}
	int leader = find_leader(leaderArry[node]);
	leaderArry[node] = leader; //updating leader for all nodes
	return leader;
}

void dsu_union(int node1, int node2) {
	int leader1 = find_leader(node1);
	int leader2 = find_leader(node2);

	if (group_size[leader1] >= group_size[leader2]) {
		leaderArry[leader2] = leader1;
		group_size[leader1] = group_size[leader1] + group_size[leader2];
	}
	else {
		leaderArry[leader1] = leader2;
		group_size[leader2] = group_size[leader2] + group_size[leader1];
	}
}


int main() {
	//leaderArry.assign(100, -1);

	dsu_union(1, 2);
	dsu_union(2, 0);
	dsu_union(3, 1);

	//cout << find_leader(4) << endl;

	//the leader array gets updated inside recursion
	cout << "\nThe leader array: " << endl;

	for (int i = 0; i < 6; i++) {
		cout << i << " -> " << leaderArry[i] << endl;
	}

	return 0;
}