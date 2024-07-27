class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int result = nums[0]+nums[1]+nums[nums.size()-1];
       sort(nums.begin(),nums.end());

       for(int i=0;i<nums.size()-2;i++){
        int j = i+1;
        int k=nums.size()-1;
        while(j<k){
            int currentSum = nums[i]+nums[j]+nums[k];
            if(currentSum>target){
                k--;
            }else{
                j++;
            }

            if(abs(currentSum-target)<abs(result-target)){
                result=currentSum;
            }
        }
       }

       return result;

    }
};