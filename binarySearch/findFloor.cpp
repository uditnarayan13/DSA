#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int element;
    cout<<"Element whose floor we need to find : \n";
    cin>>element;
    int arr[]= {1,2,3,4,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);

    int res=INT_MIN;

    int start=0;
    int end=n-1;

    while(start<=end){
        int middle = start + (end-start)/2;
        cout<<"Start : "<<start<<" Middle : "<<middle<<" end: "<<end<<"\n";
        if(arr[middle]<=element){
            res= max(res,arr[middle]);
            start=middle+1;
        }else if(element<arr[middle]){
            end=middle-1;
        }
    }

    cout<<"Floor of element is "<<res<<"\n";

}