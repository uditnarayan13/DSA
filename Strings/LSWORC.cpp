/* Longest Substring Without Repeating Characters */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s){
    int i=0;
    int j=0;

    map<char,int>mp;
    int ans=INT_MIN;
    while(j<s.length()){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            ans=max(ans,j-i+1);
        }else if(mp.size()<j-i+1){
            /* The window has some duplicate characters.
            * We need to remove them until the unique char count becomes less or equal to window length */
            while(mp.size()<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter any string: ";
    cin>>s;

    cout<<"The length of Longest substring without any repeating character is : "<<lengthOfLongestSubstring(s);
}