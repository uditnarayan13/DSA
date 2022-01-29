#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin>>n;
   int dp[n+1];
   memset(dp,0,sizeof(dp));
   dp[0]=1;
   for(int i=2;i<=n;i+=2){
       for(int j=0;j<i;j+=2){ 
           dp[i]+=dp[j]*dp[i-j-2];
       }
   }
cout<<dp[n];
}
