class Solution
{
public:
    int dp[100000 + 1][2];
    bool solve(int n, bool turn)
    {
        if (n == 0)
        {
            return !turn;
        }
        if (dp[n][turn] != -1)
            return dp[n][turn];
        for (int i = 1; i * i <= n; i++)
        {
            if (turn)
            {
                if (solve(n - i * i, !turn))
                    return dp[n][turn] = true;
            }
            else
            {
                if (!solve(n - i * i, !turn))
                    return dp[n][turn] = false;
            }
        }
        return dp[n][turn] = !turn;
    }
    bool winnerSquareGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, true);
    }
};