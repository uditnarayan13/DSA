#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Algorithm : 
1) Initializing the base case 
2) Now in iteration we are creating a frequency string*/

string countAndSay(int n)
{
    string s = "1";
    int k = 1;

    for(int i=2;i<=n;i++){
        string t="";
        int count=1;
        for(int j=0;j<s.length();j++){
           
            if(j<s.length()-1 && s[j]==s[j+1]){
                count++;
            }else{
                t+=to_string(count)+s[j];
                count=1;
            }
        }
          s=t;
    }

    return s;
    /* We have count the occursence of the character and return the string of integer */
}

int main()
{
    string res = countAndSay(5);
    cout << res;
}