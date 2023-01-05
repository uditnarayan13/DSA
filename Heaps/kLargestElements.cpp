#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Approach :
1. Insert all elements in a Max Heap and
2. Pop the element once one by one and insert it in array.
 */

vector<int> kLargest(vector<int>&arr, int k)
{
    // code here

    vector<int> result;

    priority_queue<int> pq;

    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }

    for(int i=0;i<k;i++){
        int maxElement = pq.top();
        result.push_back(maxElement);
        pq.pop();
    }

    return result;
}

int main()
{

    int n; int k;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {   int ele;
        cin>>ele;
        arr.push_back(ele);
    }

     cout<< "Enter the number of largest elements you want print : ";
     cin>>k;

    vector<int>resArray =  kLargest(arr,k);

    for(auto i : resArray){
        cout<<i<<" ";
    }
}