#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
    int maxElement = *max_element(arr, arr+n);
    int minElement = *min_element(arr, arr+n);
    int range = maxElement - minElement + 1;
    int count[range] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]-minElement]++;
    }
    for(int i=1; i<range; i++){
        count[i] += count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]-minElement]] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}