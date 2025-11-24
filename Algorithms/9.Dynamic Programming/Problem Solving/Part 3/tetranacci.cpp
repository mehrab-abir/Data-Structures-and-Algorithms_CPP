#include<iostream>
#include<vector>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number-a-easy-version

int getTetranacci(int n, vector<int>&memo){
    if(n == 0 || n == 1){
        return n;
    }
    else if(n == 2){
        return 1;
    }
    else if(n == 3){
        return 2;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = getTetranacci(n-1,memo) + getTetranacci(n-2,memo) + getTetranacci(n-3,memo) + getTetranacci(n-4,memo);
    return memo[n]; 
}

int main(){

    int n;
    cin>>n;

    vector<int>memo(n+1,-1);

    int tetranacci = getTetranacci(n,memo);

    cout<<tetranacci;

    return 0;
}