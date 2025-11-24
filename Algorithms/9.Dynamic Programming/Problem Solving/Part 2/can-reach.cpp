#include<iostream>
#include<vector>

using namespace std;

vector<int>memo;

bool reachTarget(int current, int target){
    if(current == target){
        return true;
    }

    if(current > target){
        return false;
    }

    if(memo[current] != -1){
        return memo[current];
    }

    memo[current] = reachTarget(current+5,target) || reachTarget(current*4,target);
    return memo[current];
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        memo.assign(n+1,-1);

        if(reachTarget(1,n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
