#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void insert(vector<int>&v,int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();

    insert(v,temp);
    v.push_back(val);
}

void sortMethod(vector<int>&v){
    if(v.size()==1){
        return;
    }

    int temp = v[v.size()-1];
    v.pop_back();
    sortMethod(v);

    insert(v,temp);
}

int main(){
    vector<int>v{0,1,5,2,4,3};
    sortMethod(v);

    for(auto i : v ){
        cout<<i<<" ";
    }
}