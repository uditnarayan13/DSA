#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>subArraySum(int arr[],int n, long long s){
int start=0;
int end=0;
vector<int>pos;
int tempSum=0;
while(start<n && start<=end){
    if(tempSum==s){
        pos.push_back(start+1);
        pos.push_back(end+1);
        break;
    }
    else if(tempSum<s){
        tempSum+=arr[end];
        end++;

    }else{
        tempSum-=arr[start];
        start++;
    }
}
return pos;
}
int main(){
    int n;
    cout<<"Enter the size of array element";
    cin>>n;
    int sum;
    cout<<"Enter the desired sum : ";
    cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result=subArraySum(arr,n,sum);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}
