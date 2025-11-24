#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        priority_queue<pair<int,int>>pq;
        
        int n;
        cin>>n;

        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<n;i++){
            int value, idx;
            value = arr[i];
            idx = i;

            pq.push({value,idx});
        }

        int idx_1 = pq.top().second;
        pq.pop();
        int idx_2 = pq.top().second;

        if(idx_1 < idx_2){
            cout<<idx_1<<" "<<idx_2<<endl;
        }
        else{
            cout<<idx_2<<" "<<idx_1<<endl;
        }
    }

    return 0;
}