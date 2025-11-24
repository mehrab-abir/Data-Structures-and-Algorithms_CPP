#include<iostream>
#include<vector>

using namespace std;

vector<int>leaderArr(100005, -1);
vector<int>groupSize(100005, 1);

int find(int node){
    if(leaderArr[node] == -1){
        return node;
    }
    int leader = find(leaderArr[node]);
    leaderArr[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(groupSize[leader1] >= groupSize[leader2]){
        leaderArr[leader2] = leader1;
        groupSize[leader1] += groupSize[leader2];
    }
    else{
        leaderArr[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    int cycle = 0;

    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;

        int leaderA = find(a);
        int leaderB = find(b);

        if(leaderA == leaderB){
            cycle++;
        }
        else{
            dsu_union(a,b);
        }
    }

    cout<<cycle;


    return 0;
}