#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

void Bubble(vector<int>& arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void Insertion(vector<int>& arr){
    int n=arr.size();
    for(int i=1; i<n; i++){
        int kunci=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>kunci){
            arr[j+1]=arr[j]; j--;
        }arr[j+1]=kunci;
    }
}

