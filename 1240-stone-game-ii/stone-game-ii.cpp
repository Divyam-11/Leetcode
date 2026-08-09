class Solution
{
public:
    int dp[2][101][202];
    int solve(bool turn, int index, int M, vector<int> &piles)
    {
        if (index >= piles.size())
            return 0;
        int temp = 0;
        int res;
        if (turn)
            res = INT_MIN;
        else
            res = INT_MAX;
        if (dp[turn][index][M] != -1)
            return dp[turn][index][M];
        for (int i = 0; i < 2 * M; i++)
        {
            if (index + i >= piles.size())
                break;
            temp += piles[index + i];
            if (turn)
            {
                res = max(res, temp + solve(!turn, i + index + 1, max(i + 1, M), piles));
            }
            else
            {
                res = min(res, solve(!turn, i + index + 1, max(i + 1, M), piles));
            }
        }
        return dp[turn][index][M] = res;
    }
    int stoneGameII(vector<int> &piles)
    {
        memset(dp, -1, sizeof(dp));
        return solve(true, 0, 1, piles);
    }
};