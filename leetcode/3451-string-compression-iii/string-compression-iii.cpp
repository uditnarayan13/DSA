class Solution {
public:
    string compressedString(string word) {
        map<char,int>mp;
        string res="";

        for(int i=0;i<word.length();i++){
                mp[word[i]]++;
                if(mp[word[i]]>=9){
                    res+=to_string(mp[word[i]])+word[i];
                    mp[word[i]]=mp[word[i]]-9;
                }else if(word[i]!=word[i+1]){
                   res+=to_string(mp[word[i]])+word[i]; 
                   mp[word[i]]=0;
                }
        }
        return res;
    }
};