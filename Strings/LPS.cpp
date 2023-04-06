
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int,int> isPallindrome(int left, int right, string s)
{   pair<int,int> res;
    if (left > right || s.empty())
    {
        res.first = 0;
        res.second = 0;
        return res;
    }
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    cout << "right " << right << " left : " << left << "\n";
    res.first = left;
    res.second = right;
    return res;
}

string longestPalindrome(string s)
{
    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {

        pair<int,int> oddIndex = isPallindrome(i, i + 1, s);
        pair<int,int> rightIndex = isPallindrome(i, i, s);
        
        int oddLength = oddIndex.right
        /* if (len > end - start + 1)
        {
            start = (i - (len - 1) / 2);
            end = (i + (len * 0.5));
            cout << "start " << start << " end : " << end << " len " << len << "\n";
        } */
    }
    string result;
    result = s.substr(start, end - start + 1);
    return result;
}

int main(){
    longestPalindrome("babd");
}