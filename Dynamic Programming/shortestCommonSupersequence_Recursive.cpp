#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int SCS(string s1, string s2,int n,int m){
   

    //Base condition 
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    //and Recursive call
    if(s1[n-1]==s2[m-1]){
        return 1+SCS(s1,s2,n-1,m-1);
    }else{
        return 1+min(SCS(s1,s2,n,m-1),SCS(s1,s2,n-1,m));
    }
    
}

//Approach two : Using Longest Common Subsequence 
int LCS(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=m;
    int j=n;
    string str="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            str+=s1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            str+=s1[i-1];
            i--;
        }else{
            str+=s2[j-1];
            j--;
        }
    }
    while(i>0){
        str+=s1[i-1];
        i--;
    }

    while(j>0){
        str+=s2[j-1];
        j--;
    }
    reverse(str.begin(),str.end());
    cout<<str<<"\n";
    return (m+n-dp[m][n]);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
     int n=s1.length();
    int m=s2.length();
    //Using Recursion
    cout<<SCS(s1,s2,n,m)<<"\n";
    //Using Longest common Substring;
    cout<<LCS(s1,s2);


}