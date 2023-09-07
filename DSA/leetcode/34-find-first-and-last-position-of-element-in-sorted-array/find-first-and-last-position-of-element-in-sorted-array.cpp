class Solution {
public:

    int lowerBound(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=nums.size();

        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]>=target){
                ans=min(ans,mid);
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=nums.size();

        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]>target){
                ans=min(ans,mid);
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        int ub =  upperBound(nums,target);
        if(lb==nums.size() || nums[lb]!=target){
            return {-1,-1};
        }else{
            return {lb,ub-1};
        }
    }
};