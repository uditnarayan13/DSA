#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isPallindrome(string s, int left, int right){
    if(left>right || s.empty()){
        return 0;
    }

    while(left>=0 && right<=s.length()-1 && s[left]==s[right]){
        left--;
        right++;
    }
    return right -left-1;
}

string longestPallindrome (string s){
    string result;

    /* Pallindrome can have odd or even number of elements */
    int start = 0;
    int end=0;
    for(int i=0;i<s.length();i++){
        int oddLength = isPallindrome(s,i,i);
        int rightLength = isPallindrome(s,i,i+1);
        int maxLen = max(oddLength,rightLength);
        if(maxLen>end-start+1){
           if(maxLen%2!=0){
            start = i-(maxLen/2);
           }else{
            start=i-(maxLen/2)+1;
           }
           end=i+(maxLen)/2;
        }
    }
    result = s.substr(start,end-start+1);
    return result;
}

int main(){
    string s;
    cin>>s;

    cout<<"Result:"<<longestPallindrome(s);
}