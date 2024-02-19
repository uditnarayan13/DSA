class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            int toFindNumber = target-nums[i];
            if(mp.find(toFindNumber)!=mp.end()){
                if(mp[toFindNumber]!=i){
                    res.push_back(i);
                      res.push_back(mp[toFindNumber]);
                       break;
                }
            }
            
        }
        return res;
    }
};