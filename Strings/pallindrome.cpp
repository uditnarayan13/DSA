#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the value of string : ";
    cin>>s;
    int flag=0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1]){
            flag=1;
            break;
        }
    }
    if(flag){
          cout<<"Given string is not a pallindorme";
    }else{
        cout<<"Given string is  a pallindorme"; 
    }
  

}