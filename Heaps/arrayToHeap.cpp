#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare (int a , int b, bool minHeap){
    if(minHeap){
        return a<b;
    }
    else{
        return a>b;
    }
}

void arrayToHeap(vector<int>&v,bool minHeap=true){
    for(int i=1;i<v.size();i++){
        int index = i;
        int parent = (i-1)/2;

        while(index>0 && v[index]>v[parent]){
            cout<<" child "<<v[index]<<" parent "<<v[parent]<<"\n";
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
}

int main(){
    vector<int> v = {4,3,6,10};
    arrayToHeap(v,false);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}