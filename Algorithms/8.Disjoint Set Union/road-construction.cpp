#include<iostream>
#include<vector>

using namespace std;

//https://cses.fi/problemset/task/1676

vector<int>leaderArr(100000+5,-1);
vector<int>groupSize(100000+5,1);

int maxGroupSize = 1;

int find_leader(int node){
    if(leaderArr[node] == -1){
        return node;
    }
    int leader = find_leader(leaderArr[node]);
    leaderArr[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find_leader(node1);
    int leader2 = find_leader(node2);

    if(groupSize[leader1] >= groupSize[leader2]){
        leaderArr[leader2] = leader1;
        groupSize[leader1] = groupSize[leader1] + groupSize[leader2];
        maxGroupSize = max(maxGroupSize, groupSize[leader1]);
    }
    else{
        leaderArr[leader1] = leader2;
        groupSize[leader2] = groupSize[leader2] + groupSize[leader1];
        maxGroupSize = max(maxGroupSize, groupSize[leader2]);
    }
}

int main(){
    int cities, roads;
    cin>>cities>>roads;

    int maxComponents = cities;

    for(int i=0;i<roads;i++){
        int a,b;
        cin>>a>>b;

        int leaderA = find_leader(a);
        int leaderB = find_leader(b);

        if(leaderA != leaderB){
            dsu_union(a,b);
            maxComponents--;
        }

        cout<<maxComponents<<" "<<maxGroupSize<<endl;
    }

}