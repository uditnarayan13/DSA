class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     vector<vector<int>>res;
      int n = nums.size();
      if(n<4)  return res;
      long long int result=0;
     sort(nums.begin(),nums.end());
      for(long long int i=0;i<nums.size();i++){
        if(i && nums[i] == nums[i-1]) continue;
          for(long long int j=i+1;j<nums.size();j++){
             if(j>i+1 && nums[j] == nums[j-1]) continue;
             long long int l=j+1;
             long long int k=nums.size()-1;
              while(l<k){
                     long long currentSum = (long long)nums[i] + nums[j] + nums[l] + nums[k];
                    if(currentSum<target){
                        l++;
                    }else if(currentSum>target){
                        k--;
                    }else{
                        vector<int>v={nums[i],nums[j],nums[l],nums[k]};
                                //if new quads then push to main vector
                                if(find(res.begin(),res.end(),v)==res.end())
                                {
                                    res.push_back(v);
                                }
                        while (l < k && nums[l] == nums[l + 1]) l++;
                        while (l < k && nums[k] == nums[k - 1]) k--;
                        l++;
                        k--;
                    }
                }
            }

        }
   return res;
    }
};