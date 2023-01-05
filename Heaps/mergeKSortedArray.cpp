#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/* Approach :
1. We will declare a minHeap for this piece.
2. We will design a custom data-structure, we want to store the element of array and its position (i.e its index and which array it belongs to).
3. We will push the first element of each array in minHeap;
4. We will pop the result one by one from Heap and push the new element from the array which popped element belonged to previously.
5. Push each popped element in the array in vector one by one.
 */


typedef pair<int,pair<int,int>> node;

vector<int>mergeSortedArray(vector<vector<int>> arr){

    vector<int> result;
    priority_queue<node,vector<node>,greater<node>> pq;

    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }

    while(!pq.empty()){
        node element = pq.top();
        pq.pop();
        int eleValue = element.first;
        result.push_back(eleValue);
        int x = element.second.first; //row in which element is present
        int y = element.second.second;//column in which element is present

        if(y+1<arr[x].size()){
            pq.push({arr[x][y+1],{x,y+1}});
        }

    }
     for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    } 
    return result;
}

int main(){
    vector<vector<int>>arr= {{2,3,5},{1,4,9},{6,7,8}};
    vector<int> res = mergeSortedArray(arr);
   /*  for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    } */
}