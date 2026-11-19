class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        res = min(res,nums.back()-nums[2]);
        res = min(nums[(int)nums.size() - 3] - nums[0], res);
        res = min(nums[nums.size()-2]-nums[1],res);
        return res;
    }
};