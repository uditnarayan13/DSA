#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n,int m , vector<vector<int>>&dp){
if(n==0 || m==0){
    return dp[n][m]=0;
}
if(dp[n][m]!=-1){
    return dp[n][m];
}
int ans=INT_MIN;

if(x[n-1]==y[m-1]){
     ans=1+LCS(x,y,n-1,m-1,dp);
}else{
     ans=0;
     LCS(x,y,n-1,m,dp);
LCS(x,y,n,m-1,dp);
}

return dp[n][m]=ans;

}

int main(){
    string x="abcdxyz";
    string y="xyzabcd";
    /* cin>>x;
    cin>>y; */
    int n = x.length();
    int m = y.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<LCS(x,y,n,m,dp)<<"\n";

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}