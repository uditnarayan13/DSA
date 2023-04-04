#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void binarySearch(int arr[], int element,int size){
    int start=0;
    int end=size-1;
    while(start<=end){
        int middle = (start+(end-start)/2);

        if(arr[middle]==element){
            cout<<"Element is "<<arr[middle]<<" found at index: "<<middle<<"\n";
            return;
        }else if(arr[middle]>element){
            end=middle-1;
        }else{
            start=middle+1;
        }


    }
    cout<<"Element not found"<<"\n";
    return;
}

int main(){
int element;
cin>>element;
int arr[]={1,2,4,5,7,8,9,20};
int n = sizeof(arr)/sizeof(arr[0]);
binarySearch(arr,element,n);
}