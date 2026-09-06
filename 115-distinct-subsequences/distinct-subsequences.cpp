class Solution
{
public:
    int dp[1001][1001];
    int solve(int m, int n, string &s, string &t)
    {
        if (n == -1)
            return 1;
        if (m == -1)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int take = 0;
        if (s[m] == t[n])
            take = solve(m - 1, n - 1, s, t);
        int notTake = solve(m - 1, n, s, t);
        return dp[m][n] = take + notTake;
    }
    int numDistinct(string s, string t)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s.size() - 1, t.size() - 1, s, t);
    }
};