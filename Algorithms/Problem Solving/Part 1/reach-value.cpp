#include<iostream>
#include<vector>

using namespace std;

bool reachValue(long long int current, long long int target){
    if(current == target){
        return true;
    }
    if(current > target){
        return false;
    }

    return reachValue(current * 10, target) || reachValue(current*20, target);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n;
        cin>>n;

        bool result = reachValue(1,n);

        if(result == true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}