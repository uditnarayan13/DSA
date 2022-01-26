#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void mergeArray(int arr1[], int arr2[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);

            int first = arr2[0];
            int k;
            for (k = 1; k < m; k++)
            {
                if (arr2[k] < first)
                {
                    arr2[k - 1] = arr2[k];
                }
                else
                {
                    break;
                }
            }
            arr2[k - 1] = first;
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of two array : ";
    cin >> n >> m;
    int arr1[n], arr2[m];
    cout << "Enter the elements of first array";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of second array";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    mergeArray(arr1, arr2, n, m);
    cout<<"Array 1 : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n";
    cout<<"Array 2 : ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}