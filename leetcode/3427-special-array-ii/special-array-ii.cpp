class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> parityArray(nums.size(), 0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                parityArray[i]=1;
            }
        }
       for(int i=1;i<parityArray.size();i++){
          parityArray[i]=  parityArray[i] + parityArray[i-1];
        }
       vector<bool>res;
        for(int i=0;i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int val = parityArray[end]-parityArray[start];
            if(val==0){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
   
};