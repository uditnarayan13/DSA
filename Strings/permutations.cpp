#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void permutations(string s , int l ,int r){
    if(l==r){
        cout<<s<<endl;
    }else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permutations(a, l + 1, r);
            swap(a[l],a[i]);

        }
    }
}

int main(){
    string s;
    cin>>s;
    int n= s.size();
    permutations(s,0,n-1);
}