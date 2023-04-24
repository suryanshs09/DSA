#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct item{
    int weight;
    int value;
};

int knapsack_recursive(item arr[], int n, int w){
    if(n == 0 || w == 0){
        return 0;
    }
    if(arr[n-1].weight <= w){
        return max(arr[n-1].value + knapsack_recursive(arr, n-1, w-arr[n-1].weight), knapsack_recursive(arr, n-1, w));
    }
    return knapsack_recursive(arr, n-1, w);
}


int knapsack_memoized(item arr[], int n, int w, int **dp){
    if(n == 0 || w == 0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(arr[n-1].weight <= w){
        dp[n][w] = max(arr[n-1].value + knapsack_memoized(arr, n-1, w-arr[n-1].weight, dp), knapsack_memoized(arr, n-1, w, dp));
        return dp[n][w];
    }
    dp[n][w] = knapsack_memoized(arr, n-1, w, dp);
    return dp[n][w];
}

int knapsack_tabular(item arr[], int n, int w){
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[w+1];
        for(int j=0; j<=w; j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(arr[i-1].weight <= j){
                dp[i][j] = max(arr[i-1].value + dp[i-1][j-arr[i-1].weight], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

void test_recursive(int testCases, string filePath){
    for(int i=1; i<=testCases; i++){
        ifstream fin(filePath + "input" + to_string(i) + ".txt");
        ifstream fout(filePath + "output" + to_string(i) + ".txt");
        if(fin && fout){
            int n, w;
            fin >> n >> w;
            item arr[n];
            for(int i=0; i<n; i++){
                fin >> arr[i].weight >> arr[i].value;
            }
            fin.close();
            int expectedAns;
            fout >> expectedAns;
            fout.close();

            auto start = high_resolution_clock::now();
            int ans = knapsack_recursive(arr, n, w);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            if(ans == expectedAns){
                cout << "Testcase " << i << " passed \t";
            }
            else{
                cout << "Testcase " << i << " failed \t";
            }
            cout << "Time taken: " << duration.count() << " ms" << endl;
        }
    }
}

void test_memoized(int testCases, string filePath){
    for(int i=1; i<=testCases; i++){
        ifstream fin(filePath + "input" + to_string(i) + ".txt");
        ifstream fout(filePath + "output" + to_string(i) + ".txt");
        if(fin && fout){
            int n, w;
            fin >> n >> w;
            item arr[n];
            int **dp = new int*[n+1];
            for(int i=0; i<=n; i++){
                dp[i] = new int[w+1];
                for(int j=0; j<=w; j++){
                    dp[i][j] = -1;
                }
            }
            for(int i=0; i<n; i++){
                fin >> arr[i].weight >> arr[i].value;
            }
            fin.close();
            int expectedAns;
            fout >> expectedAns;
            fout.close();

            auto start = high_resolution_clock::now();
            int ans = knapsack_memoized(arr, n, w, dp);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            if(ans == expectedAns){
                cout << "Testcase " << i << " passed \t";
            }
            else{
                cout << "Testcase " << i << " failed \t";
            }
            cout << "Time taken: " << duration.count() << " ms" << endl;
        }
    }
}

void test_tabular(int testCases, string filePath){
    for(int i=1; i<=testCases; i++){
        ifstream fin(filePath + "input" + to_string(i) + ".txt");
        ifstream fout(filePath + "output" + to_string(i) + ".txt");
        if(fin && fout){
            int n, w;
            fin >> n >> w;
            item arr[n];
            for(int i=0; i<n; i++){
                fin >> arr[i].weight >> arr[i].value;
            }
            fin.close();
            int expectedAns;
            fout >> expectedAns;
            fout.close();

            auto start = high_resolution_clock::now();
            int ans = knapsack_tabular(arr, n, w);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            if(ans == expectedAns){
                cout << "Testcase " << i << " passed \t";
            }
            else{
                cout << "Testcase " << i << " failed \t";
            }
            cout << "Time taken: " << duration.count() << " ms" << endl;
        }
    }
}

int main(){
    int testCases = 6;
    string filePath = "../../testcases/algo/dp/knapsack_01/";

    // test_recursive(testCases, filePath);
    // test_memoized(testCases, filePath);
    test_tabular(testCases, filePath);


    return 0;
}
