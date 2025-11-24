#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//almost similar to the level order traversal of binary tree
void bfs(int src, vector<vector<int>>adj_list, vector<bool>visited) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	//visit kora hoye geche, tai visited array er ei index true hoye gelo, ata r queue te push hobe na

	//time complexity for this loop -> O(V), V = number of vertices/nodes
	while (!q.empty()) {
		int parentNode = q.front();
		q.pop();

		cout << parentNode << " ";

		//current node er adjacent node gulu q te push kora,,time complexity -> O(E), E = Number of edges
		for (int adjacent : adj_list[parentNode]) {

			//jodi already akbar visit kora na hoye thake, tobei queue te push hobe
			if (visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true; //ai child visit kora done, queue te abar push hobe na
			}
		}
	}
}
//Total time complexity of BFS -> O(V+E)
//space complexity -> O(V) , for the queue

int main() {
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u); //for undirected graph
	}

	vector<bool>visited(nodes, false); //initially all false, not visited yet

	cout << "\nBreadth First Search traversal of this graph: ";
	bfs(0, adj_list, visited); //assuming src node is 0, sample input is at the end of this file

	return 0;
}


/*
**sample input

number of nodes 7, number of edges 7
nodes:
0 1
1 3
1 4
3 2
4 6
3 5
4 5

output for this graph, in bfs traversal: 0 1 3 4 2 5 6
*/