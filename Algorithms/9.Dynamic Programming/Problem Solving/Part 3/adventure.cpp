#include<iostream>
#include<vector>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/adventure-1

int knapSack(int item, int current_weight,vector<int>&values,vector<int>&weight, vector<vector<int>>&memo){
    if(item < 0 || current_weight <= 0){
        return 0;
    }

    if(memo[item][current_weight] != -1){
        return memo[item][current_weight];
    }

    if(weight[item] <= current_weight){
        int chosen = values[item] + knapSack(item-1,current_weight - weight[item],values, weight,memo);
        int notChosen = knapSack(item-1,current_weight,values, weight, memo);
        memo[item][current_weight] = max(chosen, notChosen);
        return memo[item][current_weight];
    }
    else{
        memo[item][current_weight] = knapSack(item-1,current_weight,values, weight,memo);
        return memo[item][current_weight];
    }
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int nItems, max_weight;
        cin>>nItems>>max_weight;

        vector<int>values(nItems);
        vector<int>weight(nItems);

        for(int i=0;i<nItems;i++){
            cin>>weight[i];
        }

        for(int i=0;i<nItems;i++){
            cin>>values[i];
        }

        vector<vector<int>>memo(nItems,vector<int>(max_weight+1,-1));

        int maxValue = knapSack(nItems - 1, max_weight,values,weight, memo);

        cout<<maxValue<<endl;
    }

    return 0;
}