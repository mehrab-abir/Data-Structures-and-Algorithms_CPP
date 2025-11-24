#include<iostream>
#include<vector>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-

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

    memo[current] = reachTarget(current + 3, target) || reachTarget(current * 2 , target);
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
