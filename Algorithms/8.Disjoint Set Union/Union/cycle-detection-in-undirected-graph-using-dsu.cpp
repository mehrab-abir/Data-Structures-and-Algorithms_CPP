#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

vector<int>leaderArry(100, -1); 
vector<int>group_size(100, 1); 

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

	int nodes, edges;
	cout << "Number of nodes and edges: ";
	cin >> nodes >> edges;

	bool cycle = false;

	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		int leaderU = find_leader(u);
		int leaderV = find_leader(v);

		if (leaderU == leaderV) {
			cycle = true;
		}
		else {
			dsu_union(u, v);
		}
	}

	if (cycle == true) {
		cout << "Cycle detected.\n";
	}
	else {
		cout << "No cycle\n";
	}

	return 0;
}