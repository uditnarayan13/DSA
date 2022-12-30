#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Heap {
    vector <int> heap;
    bool minHeap=true;

    public : 
    
    Heap(int defaultSize = 10 , bool minHeap = true){
        heap.reserve(defaultSize);
        heap.push_back(-1);
        this->minHeap = minHeap;
    }

    bool compare(int a, int b){
        if(minHeap){
            return a<b;
        }else{
            return a>b ;
        }
    }
    void push(int data){
        heap.push_back(data);
        int lastIndex = heap.size()-1;
        int parentIndex = lastIndex/2;
        while(lastIndex>1 && compare(heap[lastIndex],heap[parentIndex])){
            swap(heap[lastIndex],heap[parentIndex]);
            lastIndex = parentIndex;
            parentIndex = parentIndex/2;
        }
    }

    int get(){
        return heap[1];
    }
    void heapify(int index){

        int leftChildIdx = 2*index;
        int rightChildIdx= 2*index+1;

        int idx = index;

        int heapSize = heap.size()-1;
        if((leftChildIdx<=heapSize) and compare(heap[leftChildIdx],heap[idx])){
            idx = leftChildIdx;
        }

        if((rightChildIdx <= heapSize) and (compare(heap[rightChildIdx],heap[idx]))){
            idx = rightChildIdx;
        }

        if(idx!=index){
            swap(heap[index],heap[idx]);
            heapify(idx);
        }
    }

    void pop(){
        int heapSize = heap.size()-1;
        swap(heap[1],heap[heapSize]);
        heap.pop_back();
        heapify(1);

    }

    bool empty(){
        return heap.size()==1;
    }
};

int main(){
    Heap h (5) ;

    int n;
    cout<<"Enter the number of elements to be pushed in heap : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        h.push(number);
    }

    while(!h.empty()){
        cout<<h.get()<<" ";
        h.pop();
    }

    return 0;
}