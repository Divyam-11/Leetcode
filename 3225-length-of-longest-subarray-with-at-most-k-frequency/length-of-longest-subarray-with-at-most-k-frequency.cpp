class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int,int> m;
        int l =0;
        for(int r = 0 ; r<nums.size();r++){
            m[nums[r]]++;
            while(m[nums[r]]>k){
                m[nums[l]]--;
                l++;
            }
            result = max(result,r-l+1);
        }




        return result;
    }
};