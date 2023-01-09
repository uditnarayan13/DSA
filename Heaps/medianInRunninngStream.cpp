#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* Approach : 
1) Use two heaps : maxHeap {two store elements less than the median} and minHeap {to store the elements more than the median}. 
2) If the size of maxHeap is larger than minHeap, and the entering element is less than median, then you have to pop one element from maxHeap to create balance betwwen number of elements. 
3) If the size of minHeap is larger than minHeap, and the entering element is greater than median, then you have to pop one element from minHeap to create balance betwwen number of elements. 
4) enter the elements till we enter -1.
*/


int main(){
    int d;
    cin>>d;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    cout<<"the median is: "<<d<<"\n";
    float median = d;
    maxHeap.push(d);
    cin>>d;
    while(d!=-1){
        if(maxHeap.size()>minHeap.size()){

            if(d<median){
                int d1 = maxHeap.top();
                maxHeap.pop();
                minHeap.push(d1);
                maxHeap.push(d);
                
            }else{
                minHeap.push(d);
            }
            median = (maxHeap.top()+minHeap.top())/2.0;
        }else if(maxHeap.size()==minHeap.size()){
            if(d<median){
                maxHeap.push(d);
                median = maxHeap.top();
            }else{
                minHeap.push(d);
                 median = minHeap.top();
            }
            

        }else{
             if(d<median){
                maxHeap.push(d);
              
            }else{
                int d2 = minHeap.top();
                minHeap.pop();
                maxHeap.push(d2);
                minHeap.push(d);
            }
              median = (maxHeap.top()+minHeap.top())/2.0;
        }

        cout<<"the median is  "<<median<<"\n";
         cin>>d;
    }

}
