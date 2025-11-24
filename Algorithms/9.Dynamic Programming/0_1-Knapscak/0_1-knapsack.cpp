#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//Time complexity O(n*max_weight) ... n = number of items
//Space complexity O(n*max_weight) ... n = number of items

vector<int>values;
vector<int>weight;

int knapsack(int itemIndex, int current_weight, vector<vector<int>>& memo) {
    if (itemIndex < 0 || current_weight <= 0) {
        return 0;
    }

    if (memo[itemIndex][current_weight] != -1) {
        return memo[itemIndex][current_weight];
    }

    if (weight[itemIndex] <= current_weight) {
        int chosen = knapsack(itemIndex - 1, current_weight - weight[itemIndex], memo) + values[itemIndex];

        int notChosen = knapsack(itemIndex - 1, current_weight, memo);
        //choose na korle to remaining weight kombe na, value o add hobe na 

        memo[itemIndex][current_weight] = max(chosen, notChosen);

        return memo[itemIndex][current_weight];
    }
    else {
        memo[itemIndex][current_weight] = knapsack(itemIndex - 1, current_weight, memo); //notChosen
        return memo[itemIndex][current_weight];
    }
}

int main() {

    int nItems, max_weight;
    
    cout << "Number of items: ";
    cin >> nItems;

    cout << "Maximum weight of the sack: ";
    cin >> max_weight;

    for (int i = 0; i < nItems; i++) {
        int value, w;

        cout << "Value of item " << i + 1 << ": ";
        cin >> value;

        cout << "Weight of item " << i + 1 << ": ";
        cin >> w;

        values.push_back(value);
        weight.push_back(w);

        cout << endl;
    }

    vector<vector<int>>memo(nItems, vector<int>(max_weight+1, -1));

    int maxValue = knapsack(nItems - 1, max_weight, memo);
    //nItems - 1, because it is starting from the last item

    cout << "Maximum possible value: " << maxValue << endl;


    return 0;
}
