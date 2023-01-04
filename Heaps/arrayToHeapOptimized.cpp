#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool compare(int a , int b,  bool minHeap ){
    if(minHeap){
        return a<b;
    }else{
        return a>b;
    }
}

void heapify(int index, vector<int>&v, bool minHeap){
    int idx = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left <v.size() && compare(v[left],v[idx], false)){
        idx = left;
    }

    if(right<v.size() && compare(v[right],v[idx],false)){
        idx = right;
    }

    if(idx!=index){
        swap(v[index],v[idx]);
        heapify(idx,v,false);
    }

}

void buildHeap(vector<int> &v, bool minHeap){

    int N = ((v.size())/2)-1;
    for(int i=N;i>=0;i--){
        heapify(i,v,minHeap);
    }
}


int main(){
    vector <int> v = {3,4,5,2,6,7};

    buildHeap(v,false);

    for(int i = 0;i <v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}