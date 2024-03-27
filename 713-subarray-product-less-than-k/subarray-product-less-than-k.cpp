class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        int l = 0;
        int r;
        int product = 1;
        for(int r = 0 ; r<nums.size();r++){
          product *=nums[r];
          while (product>=k && l<=r)
          {
            product = product / nums[l];
            l++;
          }
          
        result+=(r-l+1);
        }




        return result;
    }
};