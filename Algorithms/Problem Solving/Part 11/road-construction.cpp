#include<iostream>
#include<vector>

using namespace std;

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

void dsu_union(int node1, int node2, int &components){
    int leader1 = find_leader(node1);
    int leader2 = find_leader(node2);

    if(leader1 == leader2){
        return;
    }

    if(groupSize[leader1] >= groupSize[leader2]){
        leaderArr[leader2] = leader1;
        groupSize[leader1] += groupSize[leader2];
        maxGroupSize = max(maxGroupSize, groupSize[leader1]);
    }
    else{
        leaderArr[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
        maxGroupSize = max(maxGroupSize, groupSize[leader2]);
    }
    components--;
}

int main(){

    int cities, roads;
    cin>>cities>>roads;

    int components = cities;

    for(int i=1;i<=roads;i++){
        int a,b;
        cin>>a>>b;

        dsu_union(a,b,components);  //whether they are already in same component or not, will be checked inside dsu function
        cout<<components<<" "<<maxGroupSize<<endl;
    }

    return 0;
}