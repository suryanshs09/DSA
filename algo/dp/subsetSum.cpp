#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

bool subsetSum(vector<int> arr, int n, int sum){
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
        
        int n, sum;
        fin >> n >> sum;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            fin >> arr[i];
        }
        bool expected, actual;
        fout >> expected;
        fin.close();
        fout.close();

        auto start = high_resolution_clock::now();
        actual = subsetSum(arr, n, sum);
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
    string filePath = "../../testcases/algo/dp/subsetSum/";
    test(testCases, filePath);
    return 0;
}