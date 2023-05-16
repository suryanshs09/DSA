#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(vector<int> arr, int n){
    int range = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = vector<bool>(range+1, false);
        dp[i][0] = true;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=range; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = range+1;
    for(int i=0; i<=range/2; i++){
        if(dp[n][i]){
            ans = min(ans, range-2*i);
        }
    }
    return ans;
}