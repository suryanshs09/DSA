#include<bits/stdc++.h>
using namespace std;

void radixSort(int arr[], int n){
    int maxElement = *max_element(arr, arr+n);
    int exp = 1;
    while(maxElement/exp > 0){
        int count[10] = {0};
        for(int i=0; i<n; i++){
            count[(arr[i]/exp)%10]++;
        }
        for(int i=1; i<10; i++){
            count[i] += count[i-1];
        }
        int output[n];
        for(int i=n-1; i>=0; i--){
            output[--count[(arr[i]/exp)%10]] = arr[i];
        }
        for(int i=0; i<n; i++){
            arr[i] = output[i];
        }
        exp *= 10;
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
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}