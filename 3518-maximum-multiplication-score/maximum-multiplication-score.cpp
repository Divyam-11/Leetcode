class Solution
{
public:
    // a -> i
    // b -> j
    long long solve(int i, int j, vector<int> &a, vector<int> &b, vector<vector<long long>> &dp)
    {

        if (i < 0)
            return 0;
        if (j < 0)
            return LLONG_MIN;

        if (dp[i][j] != LLONG_MIN)
            return dp[i][j];
        long long pick = LLONG_MIN;
        long long temp = solve(i - 1, j - 1, a, b, dp);
        if (temp != LLONG_MIN)
            pick = a[i] * 1LL * b[j] + temp;
        long long not_pick = solve(i, j - 1, a, b, dp);
        return dp[i][j] = max(pick, not_pick);
    }
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        vector<vector<long long>> dp(a.size(), vector<long long>(b.size(), LLONG_MIN));
        return solve(a.size() - 1, b.size() - 1, a, b, dp);
    }
};