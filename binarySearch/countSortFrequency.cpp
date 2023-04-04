#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]= {12,15, 18, 2, 3, 6};

    int n =sizeof(arr)/sizeof(arr[0]);

    int start=0;
    int end=n-1;

    int minIdx=-1;
    while(start<=end){
     int middle = start + (end-start)/2;
     int prevMiddle = (middle-1+n)%n;
     int nextMiddle = (middle+1-n)%n;
     if(arr[middle]<=arr[prevMiddle] && arr[middle]<=arr[nextMiddle]){
        minIdx = middle;
        break;
     }else if(arr[middle]<=arr[end]){
        end=middle-1;
     }else if(arr[start]<=arr[middle]){
        start=middle+1;
     }

    }
    cout<<"Frequency of array : "<<minIdx<<"\n";
}