class Solution {
public:
    int trap(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int leftMax=height[start];
        int rightMax=height[end];
        int res=0;
        while(start<=end){
            if(leftMax<rightMax){
                leftMax=max(leftMax,height[start]);
                res+=(leftMax-height[start]);
                start++;
            }else{
                rightMax=max(rightMax,height[end]);
                res+=(rightMax-height[end]);
                end--;
            }
        }
        return res;
    }
};