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

int partition(vector<int>& arr,int rendah,int tinggi){
    int pivot=arr[tinggi];
    int i=rendah-1;
    for(int j=rendah; j<tinggi; j++){
        if(arr[j]<pivot){ i++;
            swap(arr[i],arr[j]);
        }
    }swap(arr[i+1],arr[tinggi]);
    return i+1;
}

void Quick(vector<int>& arr,int rendah,int tinggi){
    if(rendah<tinggi){
        int pi=partition(arr,rendah,tinggi);
        Quick(arr,rendah,pi-1);
        Quick(arr,pi+1,tinggi);
    }
}

long long ukurWaktunya(void(*fungsiSort)(vector<int>&),vector<int>& arr){
    auto mulai=chrono::high_resolution_clock::now();
    fungsiSort(arr);
    auto selesai=chrono::high_resolution_clock::now();
    chrono::duration<double,micro> durasi=selesai-mulai;
    return durasi.count();
}

vector<int> buatDataAcak(int n){
    vector<int> data(n);
    generate(data.begin(),data.end(),rand);
    return data;
}

vector<int> buatDataTerurut(int n){
    vector<int> data(n);
    iota(data.begin(),data.end(),1);
    return data;
}

