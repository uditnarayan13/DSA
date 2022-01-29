#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string S)
{
    // code here 
    string str = "";
    string result = "";
    string word;
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == '.')
        {
            word = S[i] + str;
            str = "";
        }
        else
        {
            str += S[i];
        }
        result = word + result;
        word = "";
    }
    if (str != "")
        result = str + result;
    return result;
}
int main()
{
    string s;
    cin >> s;
    cout << reverseWords(s);
}
