class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int start, int end, bool turn)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        if (turn)
        {
            int rr1 = solve(piles, start + 1, end, false) + piles[start];
            int rr2 = solve(piles, start, end - 1, false) + piles[end];
            return dp[start][end] = max(rr1, rr2);
        }

        int rr1 = solve(piles, start + 1, end, true) - piles[start];
        int rr2 = solve(piles, start, end - 1, true) - piles[end];
        return dp[start][end] = min(rr1, rr2);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(piles, 0, n - 1, true) > 0;
    }
};