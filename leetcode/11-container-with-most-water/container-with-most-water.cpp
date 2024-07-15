class Solution {
public:
    int maxArea(vector<int>& height) {
      int start=0;
      int end=height.size()-1; 
        int maxStorage=0;
      while(start<end){
        int currentStorage = min(height[end],height[start])*(end-start);
        maxStorage = max(maxStorage,currentStorage);
        if(height[end]<=height[start]){
            end--;
        }else{
            start++;
        }
      } 
      return maxStorage;
    }
};