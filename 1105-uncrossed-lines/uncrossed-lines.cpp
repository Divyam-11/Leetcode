class Solution
{
public:
    int DP[501][501];
    int solve(int m, int n, vector<int> &nums1, vector<int> &nums2)
    {
        if (m < 0 || n < 0)
            return 0;
        if (DP[m][n] != -1)
        {
            return DP[m][n];
        }
        int take = 0;

        if (nums1[m] == nums2[n])
        {
            take = 1 + solve(m - 1, n - 1, nums1, nums2);
        }
        int left = solve(m - 1, n, nums1, nums2);
        int right = solve(m, n - 1, nums1, nums2);
        return DP[m][n] = max({take, left, right});
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        memset(DP, -1, sizeof(DP));
        return solve(m - 1, n - 1, nums1, nums2);
    }
};