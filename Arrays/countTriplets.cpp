#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countTriplet(int arr[], int n)
{
    // Your code goes here
    int ct = 0;
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (arr[i] == arr[j] + arr[k])
            {
                ct++;
                j++;
                k--;
            }
            else if (arr[i] > arr[j] + arr[k])
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ct;
}
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count = countTriplet(arr,n);
    cout<<"Count : "<<count<<"\n";
}