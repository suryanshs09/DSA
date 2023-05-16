#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

bool equalSumPartition(vector<int> arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    sum /= 2;
    vector<vector<bool>> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = vector<bool>(sum+1, false);
        dp[i][0] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

void test(int testCases, string filePath){
    for(int i=1; i<=testCases; i++){
        ifstream fin(filePath + "input" + to_string(i) + ".txt");
        ifstream fout(filePath + "output" + to_string(i) + ".txt");
        
        int n;
        fin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            fin >> arr[i];
        }
        bool expected, actual;
        fout >> expected;
        fin.close();
        fout.close();

        auto start = high_resolution_clock::now();
        actual = equalSumPartition(arr, n);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        if(expected == actual){
            cout << "Testcase " << i << " Passed\t";
            cout << "Time taken: "
            << duration.count() << " ms" << endl;
        }else{
            cout << "Testcase " << i << " Failed\t";
            cout << "Time taken: "
            << duration.count() << " ms" << endl;
            cout << "Expected: " << expected << "\tActual: " << actual << endl;
        }
    }
}

int main(){
    int testCases = 5;
    string filePath = "../../testcases/algo/dp/equalSumPartition/";
    test(testCases, filePath);
    return 0;
}