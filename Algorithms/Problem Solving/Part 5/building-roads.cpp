#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited) {
	visited[src] = true;

	for (int adjacent : adj_list[src]) {
		if (!visited[adjacent]) {
			dfs(adjacent, adj_list, visited);
		}
	}
}

int main(){
	int cities, roads;
	//cout << "Number of cities and roads: ";
	cin >> cities >> roads;

	vector<vector<int>>adj_list(cities + 1);

	for (int i = 0; i < roads; i++) {
		int u, v;
		//cout << "Enter two cities that have a road between them: ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(cities + 1, false);

	vector<int>city;

	for (int i = 0; i < cities; i++) {
		if (!visited[i+1]) {
			dfs(i+1, adj_list, visited);
			city.push_back(i+1);
		}
	}

	//minimum connections needed to connect all components
	/*
	If there are two components, one edge(road) is required to connect them. For three components, 2
	edge is required to connect them. That's why, city.size()-1.
	*/
	int new_roads = city.size() - 1;
	cout << new_roads << endl;

	//connecting two different component
	for (int i = 0; i < city.size()-1; i++) {
		cout << city[i] << " " << city[i+1] << endl;
	}


	return 0;
}

