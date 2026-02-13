class Solution {
public:
    long long solve(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2,int k, vector<vector<vector<long long>>>& dp) {
        if (k == 0) return 0;
        if (idx1 >= nums1.size() || idx2 >= nums2.size()) return -1e15;
        if (dp[idx1][idx2][k] != -2e18) return dp[idx1][idx2][k];
        long long take = 1LL * nums1[idx1] * nums2[idx2] + solve(idx1 + 1, idx2 + 1, nums1, nums2, k - 1, dp);
        long long skip1 = solve(idx1 + 1, idx2, nums1, nums2, k, dp);
        long long skip2 = solve(idx1, idx2 + 1, nums1, nums2, k, dp);
        return dp[idx1][idx2][k] = max({take, skip1, skip2});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<long long>>> dp(nums1.size(), vector<vector<long long>>(nums2.size(), vector<long long>(k+1, -2e18)));
        return solve(0, 0, nums1, nums2, k, dp);
    }
};