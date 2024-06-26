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

void Selection(vector<int>& arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        int indexMin=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[indexMin]){
                indexMin=j;
            }
        }swap(arr[i],arr[indexMin]);
    }
}

void merge(vector<int>& arr,int kiri,int tengah,int kanan){
    int n1=tengah-kiri+1;
    int n2=kanan-tengah;
    vector<int> Kiri(n1),Kanan(n2);
    for(int i=0; i<n1; i++) Kiri[i]=arr[kiri+i];
    for(int i=0; i<n2; i++) Kanan[i]=arr[tengah+1+i];
    int i=0,j=0,k=kiri;
    while(i<n1 && j<n2){
        if(Kiri[i] <= Kanan[j]){
            arr[k]=Kiri[i]; i++;
        }else{
            arr[k]=Kanan[j]; j++;
        }k++;
    }while(i<n1){
        arr[k]=Kiri[i]; i++; k++;
    }while(j<n2){
        arr[k]=Kanan[j]; j++; k++;
    }
}

void Merge(vector<int>& arr,int kiri,int kanan){
    if(kiri>=kanan) return;
    int tengah=kiri+(kanan-kiri)/2;
    Merge(arr,kiri,tengah);
    Merge(arr,tengah+1,kanan);
    merge(arr,kiri,tengah,kanan);
}

