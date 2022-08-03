#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool subset (int n , int sum, int arr[]){
    bool dp[n+1][sum+1];
    cout<<"\n";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            //Initialization
            if(i==0){
                dp[i][j]=false;
            }

            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            //Initialization
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }else if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return dp[n][sum];
}
int main(){
    int arr[]={ 3, 34, 4, 12, 5, 2};
    int n =sizeof(arr)/sizeof(arr[0]);
    int sum = 30;
    cout<<" Subset has some elements whose sum is equal to "<<sum<<" : "<<subset(n,sum,arr);
}
