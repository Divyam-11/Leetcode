class Solution
{
public:
    long long solve(int i, int j, int k, vector<int> &nums1, vector<int> &nums2, vector<vector<vector<long long>>> &dp)
    {
        if (k == 0)
            return 0;
        if (i >= nums1.size() || j >= nums2.size())
            return -1e15;
        if (dp[i][j][k] != LLONG_MIN)
            return dp[i][j][k];
        long long pick = nums1[i] *1LL *nums2[j] + solve(i + 1, j + 1, k - 1, nums1, nums2, dp);
        long long pick2 = solve(i + 1, j, k, nums1, nums2, dp);
        long long pick3 = solve(i, j + 1, k, nums1, nums2, dp);
        return dp[i][j][k] = max({pick, pick2, pick3});
    }
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)

    {
        vector<vector<vector<long long>>> dp(nums1.size(), vector<vector<long long>>(nums2.size(), vector<long long>(k + 1, LLONG_MIN)));
        return solve(0, 0, k, nums1, nums2, dp);
    }
};