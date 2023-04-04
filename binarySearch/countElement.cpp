#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int leftOccurence(int arr[],int n,int element){

    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int middle = (start)+(end-start)/2;

       if(element==arr[middle]){
            res= middle;
            end=middle-1;
       }else if(element<arr[middle]){
        end=middle-1;
       }else{
        start=middle+1;
       }
    }
    return res;

}
int rightOccurence(int arr[],int n, int element){
     int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int middle = (start)+(end-start)/2;

       if(element==arr[middle]){
            res= middle;
            start=middle+1;
       }else if(element<arr[middle]){
        end=middle-1;
       }else{
        start=middle+1;
       }
    }
    return res;
}

int countElement(int arr[], int n,int element){
    int ls=leftOccurence(arr,n,element);
    int rs=rightOccurence(arr,n,element);
    return (rs-ls+1);
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int element;
    cout<<"Element whose frequency is to be found : ";
    cin>>element;

    int arr[n];
    cout<<"Enter the element of array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int count = countElement(arr,n,element);
    if(count<0){
        count=0;
    }

    cout<<"Element has frequency : "<<count;
}