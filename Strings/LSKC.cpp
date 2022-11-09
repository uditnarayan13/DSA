#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void LongestSubstringWithKUniqueCharacters(string str, int k)
{
    map<char, int> mp;
    int maxWindowSize = INT_MIN;

    int start = 0;
    int end = 0;
    int i = 0;
    int j = 0;

    while (j < str.length())
    {
        mp[str[j]]++;

        if (mp.size() == k)
        {
            /* Distinct character count in window equal to K */
            if (j - i + 1 > maxWindowSize)
            {
                maxWindowSize = max(maxWindowSize, j - i + 1);
                start = i;
                end = j;
            }
        }
        else if (mp.size() > k)
        {
            /* Distinct charcater count in Window is more than K */
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {
                    mp.erase(str[i]);
                }
                i++;
                if (mp.size() == k)
                {
                    if (j - i + 1 > maxWindowSize)
                    {
                        maxWindowSize = max(maxWindowSize, j - i + 1);
                        start = i;
                        end = j;
                    }
                }
            }
        }
        j++;
    }
    
    cout << "endIndex : " << end << " startIndex: " << start << "\n";
    while (start < end)
    {
        cout << str[start];
        start++;
    }
    cout<<"\n"<< "Max window size : " << maxWindowSize << "\n";
   
}

int main()
{
    string str = "aabacbebebe";
    // cin >> str;
    int k = 3;
    // cin>>k;
    LongestSubstringWithKUniqueCharacters(str, k);
}