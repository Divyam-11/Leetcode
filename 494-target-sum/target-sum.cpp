class Solution {
public:
    int perfectSum(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                int pick = 0;
                if (j >= arr[i - 1])
                    pick = dp[i - 1][j - arr[i - 1]];
                int not_pick = dp[i - 1][j];
                dp[i][j] = pick + not_pick;
            }
        }

        return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if ((target + totalSum) % 2 != 0 || totalSum < abs(target))
            return 0;

        int s1 = (target + totalSum) / 2;

        return perfectSum(nums, s1);
    }
};
