#include<bits/stdc++.h>
using namespace std;

// same code can be used for target sum problem 

int countSubsetSumDiff(vector<int> arr, int n, int diff){
    int total = accumulate(arr.begin(), arr.end(), 0);
    int sum = (diff + total) / 2;

    vector<vector<int>> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = vector<int>(sum+1, 0);
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}