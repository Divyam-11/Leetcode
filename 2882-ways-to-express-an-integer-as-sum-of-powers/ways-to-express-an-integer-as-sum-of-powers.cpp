class Solution
{
public:
    int MOD = 1e9+7;
    int helper(int n, int x, int num, vector<vector<int>> &dp)
    {

        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        int current = pow(num, x);
        if (current > n)
            return 0;
        if (dp[n][num] != -1)
            return dp[n][num];
        // pick

        int pick = helper(n - current, x, num + 1, dp);
        // notpick
        int not_pick = helper(n, x, num + 1, dp);
        return dp[n][num] = (pick + not_pick)%MOD;
    }

    int numberOfWays(int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(n, x, 1, dp);
    }
};