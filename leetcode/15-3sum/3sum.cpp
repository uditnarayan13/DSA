class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

      int n =nums.size();
        vector<vector<int>>res;
        set<vector<int>> uniqueRes;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]==-nums[k]){
                    uniqueRes.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[i]+nums[j]<-nums[k]){
                    j++;
                }else{
                    k--;
                }
            }
        }
        for(auto it : uniqueRes){
            res.push_back(it);
        }
        return res;
    }
};