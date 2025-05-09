class Solution {
    public:
        int helper(int target, vector<int>& nums, vector<int>& dp) {
            if (target == 0) return 1;
            if (target < 0) return 0;
            if (dp[target] != -1) return dp[target];
    
            int ways = 0;
            for (int i = 0; i < nums.size(); i++) {
                ways += helper(target - nums[i], nums, dp);
            }
            return dp[target] = ways;
        }
    
        int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target + 1, -1);
            return helper(target, nums, dp);
        }
    };
    