#include<iostream>
#include<vector>

using namespace std;

// https://cses.fi/problemset/task/1666/

vector<int>groupSize(100000+5,1);

int findLeader(int node, vector<int>&leaderArr){
    if(leaderArr[node] == -1){
        return node;
    }
    int leader = findLeader(leaderArr[node], leaderArr);
    leaderArr[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2, vector<int>&leaderArr){
    int leader1 = findLeader(node1, leaderArr);
    int leader2 = findLeader(node2, leaderArr);

    if(groupSize[leader1] >= groupSize[leader2]){
        leaderArr[leader2] = leader1;
        groupSize[leader1] = groupSize[leader1] + groupSize[leader2];
    }
    else{
        leaderArr[leader1] = leader2;
        groupSize[leader2] = groupSize[leader2] + groupSize[leader1];
    }
}

int main(){

    int cities, roads;
    cin>>cities>>roads;

    vector<int>leaderArr(cities + 1,-1);

    for(int i=0;i<roads;i++){
        int a,b;
        cin>>a>>b;

        int leaderA = findLeader(a, leaderArr);
        int leaderB = findLeader(b, leaderArr);

        if(leaderA != leaderB){
            dsu_union(a,b, leaderArr);
        }
    }

    int countRoad = 0;
    vector<int>cityRepresentative;

    for(int city=1; city<=cities; city++){
        /*leader_1 is fixed, all roads will be connected with this city, we will keep track of how many times the dsu_union is called, which will be the number of roads required*/
        int leader_1 = findLeader(1, leaderArr);
        int leader_city = findLeader(city, leaderArr);

        //i represents a city
        if(leader_1 != leader_city){
            dsu_union(1,city,leaderArr);
            countRoad++;
            cityRepresentative.push_back(city);
        }
    }

    cout<<countRoad<<endl;

    for(int city : cityRepresentative){
        cout<<"1"<<" "<<city<<endl;  //we connected all cities with city "1", that's why
    }

    return 0;
}