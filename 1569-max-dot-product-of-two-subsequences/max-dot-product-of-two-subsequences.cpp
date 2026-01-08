class Solution
{
public:
    int solve(int m, int n, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (m < 0 || n < 0)
        {
            return -100000000;
        }
        if (dp[m][n] != INT_MIN)
        {
            return dp[m][n];
        }
        int score = nums1[m] * nums2[n] + solve(m - 1, n - 1, nums1, nums2, dp);
        int scor2 = nums1[m] * nums2[n];
        int left = solve(m - 1, n, nums1, nums2, dp);
        int right = solve(m, n - 1, nums1, nums2, dp);
        return dp[m][n] = max({scor2, score, left, right});
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),INT_MIN));
        int m = nums1.size();
        int n = nums2.size();
        return solve(m - 1, n - 1, nums1, nums2, dp);
    }
};