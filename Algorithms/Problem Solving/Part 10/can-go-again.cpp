#include<iostream>
#include<vector>

using namespace std;

class Edge{
public:
    int a;
    int b;
    long long int w;

    Edge(int a, int b, long long int w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

void bellman_ford(int src, vector<Edge>&edge_list, vector<long long int>&distance, int nodes, int testCase){
    distance[src] = 0;

    for(int i=1;i<=nodes-1;i++){
        for(auto edge : edge_list){
            int a, b;
            long long int w;
            a = edge.a;
            b = edge.b;
            w = edge.w;

            if(distance[a] != LLONG_MAX && distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
            }
        }
    }

    bool cycle = false;
    for(auto edge : edge_list){
        int a, b;
        long long int w;
        a = edge.a;
        b = edge.b;
        w = edge.w;

        if(distance[a] != LLONG_MAX && distance[a] + w < distance[b]){
            cycle = true;
            break;
        }
    }

    if(cycle == true){
        cout<<"Negative Cycle Detected"<<endl;
        return;
    }
    
    for(int t=0;t<testCase;t++){
        int d;
        cin>>d;

        if(distance[d] == LLONG_MAX){
            cout<<"Not Possible"<<endl;
        }
        else{
            cout<<distance[d]<<endl;
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    vector<Edge>edge_list;

    for(int i=0;i<edges;i++){
        int a,b;
        long long int w;
        cin>>a>>b>>w;

        edge_list.push_back(Edge(a,b,w));
    }

    vector<long long int>distance(nodes+1, LLONG_MAX);

    int src, t;
    cin>>src;
    cin>>t;

    bellman_ford(src,edge_list,distance,nodes,t);

    return 0;
}