#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool compare(int a , int b, bool minHeap){
    if(minHeap){
        return a<b;
    }else{
        return a>b;
    }
}

void heapify(int index, vector<int>&v,int n){
    int idx = index;
    int leftIndex=2*idx;
    int rightIndex=2*idx+1;

    if(leftIndex<=n-1 && compare(v[leftIndex],v[idx],false)){
        idx = leftIndex;
    }

    if(rightIndex<=n-1 && compare(v[rightIndex],v[idx],false)){
        idx = rightIndex;
    }

    if(idx!=index){
        swap(v[idx],v[index]);
        heapify(idx,v,n);
    }

}

void buildHeap(vector<int>&v){
    int n = (v.size()-1)/2;

    for(int i=n; i>0;i--){
        heapify(i,v,v.size());
    }
}


void heapSort(vector<int>&v){
    buildHeap(v);
    int n = v.size();

    while(n>1){
        swap(v[1],v[n-1]);
        n--;
        for(auto i : v){
        cout<<i<<" ";
        }
        cout<<"\n";
        heapify(1,v,n);
    }
}



int main(){

    vector<int> v = {-1,3,4,5,2,6,7};
    heapSort(v);
    return 0;
}