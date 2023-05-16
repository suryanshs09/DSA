#include<bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int value;
};

// same code for rod cutting problem

int unboundedKnapsack(item arr[], int n, int w){
    vector<vector<int>> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = vector<int>(w+1, 0);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i-1].weight <= j){
                dp[i][j] = max(arr[i-1].value + dp[i][j-arr[i-1].weight], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}