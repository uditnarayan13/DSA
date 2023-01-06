#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*Approach 1 :  
1. Merge two arrays.
2. Perform a heapify operation in complete array 

Approach 2: 
From second array push elements one by one in vector and perform heapify operation on the new element*/

bool compare(int a,int b, bool minHeap=false){
    if(minHeap){
        return a<b;
    }else{
        return a>b;
    }
}
void heapify(vector<int>&combinedResult,int index){
    int leftIndex=2*index+1;
    int rightIndex=2*index+2;

    int idx = index;

    if(leftIndex<=combinedResult.size()-1 && compare(combinedResult[leftIndex],combinedResult[idx],false)){
        idx = leftIndex;
    }

    if(rightIndex<=combinedResult.size()-1 && compare(combinedResult[rightIndex],combinedResult[idx],false)){
        idx = rightIndex;
    }

    if(idx!=index){
        cout<<"swapping "<<combinedResult[idx]<<" "<<combinedResult[index]<<"\n";
        swap(combinedResult[idx],combinedResult[index]);
        heapify(combinedResult,idx);
    }
}

void buildHeap(vector<int>&combinedResult, int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(combinedResult,i);
    }
}

vector<int> mergeHeaps(vector<int>&a,vector<int>&b,int n, int m){
    vector<int> combinedResult;

    for(int i=0;i<n;i++){
        combinedResult.push_back(a[i]);
    }

     for(int i=0;i<m;i++){
        combinedResult.push_back(b[i]);
    }
   
    buildHeap(combinedResult,n+m);
    return combinedResult;
}

int main(){

    vector<int>a{10, 5, 6, 2};
    vector<int>b{12, 7, 9};
    int n = a.size();
    int m=b.size();

   vector<int> result = mergeHeaps(a,b,n,m);

   for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
   }

    return 0;
}