class Solution {
public:
    bool checkInclusion(string p, string s) {
        int i=0,j=0;

       int n=s.length();
       map<char,int>mp;
       vector<int>response;

       for (int i=0;i<p.length();i++){
           mp[p[i]]++;
       }
        int k= p.length();
       int count = mp.size();
       while(j<n)
        {
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count --;
                }
            }
                if(j-i+1<k){
                    j++;
                }else if(j-i+1==k){
                    if(count==0){
                        response.push_back(i);
                        return true;
                    }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                        }
                    }
                    i++;
                    j++;
                }
            
        }
        if(response.size()>0){
            return true ;
        }else{
            return false;
        }
    }
};