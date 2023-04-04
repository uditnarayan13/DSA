#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
     cout << "1" << "\n";
    vector<int> res;
    if (nums.empty())
    {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }

    int FO = -1;
    int LO = -1;
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int middle = (start + (end - start) / 2);
        cout<<"Start : "<<start<<" Middle : "<<middle<<" end: "<<end<<"\n";
        if (nums[middle] == target)
        {
            FO = middle;
            end = middle - 1;
        }
        else if (nums[middle] < target)
        {
            start=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }

    start = 0;
    end = nums.size() - 1;
     cout << "2" << "\n";
    while (start <= end)
    {
        int middle = (start + (end - start) / 2);
        cout<<"Start : "<<start<<" Middle : "<<middle<<" end: "<<end<<"\n";
        if (nums[middle] == target)
        {
            LO = middle;
            start = middle + 1;
        }
        else if (nums[middle] < target)
        {
            start=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }

    res.push_back(FO);
    res.push_back(LO);

    return res;
}

int main()
{
    vector<int> nums{5,7,7,8,8,10};
    searchRange(nums,8);
}