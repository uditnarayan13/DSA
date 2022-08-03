#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string LCS(string s1,string s2){
string str="";

int m=s1.length();
int n=s2.length();
int dp[m+1][n+1];
for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
        if(i==0||j==0){
            dp[i][j]=0;
        }
    }
}
for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            
        }else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int i=m;
int j=n;
while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
        str+=s1[i-1];
        i--;
        j--;
    }else{
        if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
}
return str;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    string result=LCS(s1,s2);
    cout<<result<<" ";
}