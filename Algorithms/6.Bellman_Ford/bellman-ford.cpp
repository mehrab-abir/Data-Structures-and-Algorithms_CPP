#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Edge {
public:
	int u;
	int v;
	int w;

	Edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

//Complexity - O(VE)
//O(V) for the outer or loop as it runs V-1 times - O(V-1) = O(V)
//O(E) for the inner for loop as it nested in the outer for loop => O(E)

void bellman_ford(vector<Edge>& edge_list, vector<int>&distance, int nodes) {
	distance[0] = 0; //assuming source is 0, distance of the source node is 0

	for (int i = 0; i < nodes - 1; i++) {
		for (Edge edge : edge_list) {
			int u, v, w;
			u = edge.u;
			v = edge.v;
			w = edge.w;

			if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
				distance[v] = distance[u] + w;
			}
		}
	}

	//executing the loop one more time to check if there is any negative weighted cycle
	bool cycle = false;
	for (Edge edge : edge_list) {
		int u, v, w;
		u = edge.u;
		v = edge.v;
		w = edge.w;

		if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
			cycle = true; 
			/*
			ai block er vitore ashche manei distance update hote chacche, that means negative weighted
			cycle ache
			*/

			break;
		}
	}

	if (cycle == true) {
		cout << "Negative weighted cycle detected" << endl;
	}
	else {
		//printing the distance array
		for (int i = 0; i < nodes; i++) {
			cout << "Shortest distnace from source(0) to node " << i << "-> " << distance[i] << endl;
		}
	}
}

int main() {
	int nodes, edges;

	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<Edge>edge_list;

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		//cout << "Enter nodes and weight: (u,v,w): ";
		cin >> u >> v >> w;

		edge_list.push_back(Edge(u, v, w));
		//edge_list.push_back(Edge(v, u, w));  //for undirected graph
	}

	//printing edge list
	/*cout << "\nThe edges and weight: " << endl;
	for (Edge edge : edge_list) {
		cout << edge.u << " " << edge.v << " " << edge.w << endl;
	}*/
	
	vector<int>distance(nodes, INT_MAX);

	bellman_ford(edge_list, distance, nodes);

	return 0;
}

//normal graph -- answer exists
/*
nodes 5, edges 5
0 1 4
1 2 8
3 2 1
1 3 5
2 4 6
*/


//Graph with negative weighted cycle  -- no answer
/*
nodes 5
edges 5
0 1 4
2 1 -8
3 2 1
1 3 5
2 4 6
*/

//Graph with negative weight but no cycle -- anser exists
/*
nodes 5, edges 5
0 1 4
1 2 -8
3 2 1
1 3 5
2 4 6

*/

//Graph with cycle but positive weighted cycle --answer exists
/*
nodes 5, edges 5
0 1 4
2 1 8
3 2 1
1 3 -5
2 4 6
*/
