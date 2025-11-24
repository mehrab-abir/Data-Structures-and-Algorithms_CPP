#include<iostream>
#include<vector>

using namespace std;

//https://codeforces.com/problemset/problem/25/D

vector<int>leaderArr(1005,-1);
vector<int>groupSize(1005, 1);

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
        groupSize[leader1] += groupSize[leader2];
    }
    else{
        leaderArr[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
    }
}

int main(){
    int cities;
    cin>>cities;

    vector<pair<int,int>>closeRoads;

    for(int i=0;i<cities-1;i++){
        int a,b;
        cin>>a>>b;

        int leaderA = find_leader(a);
        int leaderB = find_leader(b);

        if(leaderA != leaderB){
            dsu_union(a,b);
        }
        else{
            closeRoads.push_back({a,b});
        }
    }

    
    vector<pair<int,int>>newRoads;
    int day = 0;

    for(int node=1;node<=cities;node++){
        int leader_1 = find_leader(1);
        int leader_node = find_leader(node);

        if(leader_1 != leader_node){
            dsu_union(1,node);
            newRoads.push_back({1,node});
            day++;
        }
    }

    cout<<day<<endl;

   for(int i=0;i<day;i++){
        cout<<closeRoads[i].first<<" "<<closeRoads[i].second<<" ";
        cout<<newRoads[i].first<<" "<<newRoads[i].second<<" ";
   }
    return 0;
}