#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// https://codeforces.com/problemset/problem/20/C

void dijkstra(int src, vector<vector<pair<int, int>>> &adj_list, vector<long long int> &distance, vector<int> &parent) {

    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, src});
    distance[src] = 0;

    while (!pq.empty()) {
        pair<long long int,int> current = pq.top();
        pq.pop();

        long long int cur_dist = current.first;
        int cur_node = current.second;

        for (auto [adj_node, adj_weight] : adj_list[cur_node]) {
            if (cur_dist + adj_weight < distance[adj_node]) {
                distance[adj_node] = cur_dist + adj_weight;
                pq.push({distance[adj_node], adj_node});
                parent[adj_node] = cur_node;
            }
        }
    }
}

int main() {
    int nodes, edges;
    // cout<<"Number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<pair<int, int>>> adj_list(nodes + 1);
    
    for (int i = 0; i < edges; i++) {
        int a, b, w;
        // cout<<"Enter nodes and weight (a,b,w): ";
        cin >> a >> b >> w;
        adj_list[a].push_back({b,w});
        adj_list[b].push_back({a,w});
    }

    vector<long long int> distance(nodes + 1, LLONG_MAX);
    vector<int> parent(nodes + 1, -1);

    dijkstra(1, adj_list, distance, parent);

    if (distance[nodes] == LLONG_MAX) {
        cout << "-1\n";
        //no path found
        return 0;
    }

    vector<int> path;
    int node = nodes;  //the last node is the destination

    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }
    
    reverse(path.begin(), path.end());

    // cout<<"\nShortest path: ";
    for (int point : path){
        cout << point << " ";
    } 
    cout<<endl;

    return 0;
}
