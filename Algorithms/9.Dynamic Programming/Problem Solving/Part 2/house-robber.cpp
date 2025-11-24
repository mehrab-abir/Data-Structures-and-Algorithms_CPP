#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/house-robber/description/

int getMoney(int currentHouse, vector<int>&arr,vector<int>&memo){
    if(currentHouse >= arr.size()){
        return 0;
    }

    if(memo[currentHouse] != -1){
        return memo[currentHouse];
    }

    int robCurrentHouse = getMoney(currentHouse+2, arr, memo) + arr[currentHouse];
    int skipCurrentHouse = getMoney(currentHouse+1,arr,memo);

    memo[currentHouse] = max(robCurrentHouse, skipCurrentHouse);
    return memo[currentHouse];
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    vector<int>memo(n,-1);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxMoney = getMoney(0,arr,memo);

    cout<<maxMoney;

    return 0;
}