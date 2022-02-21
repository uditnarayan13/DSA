#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void rearrangeArray(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
            }
            j++;
        }
    }

}

int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrangeArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
}