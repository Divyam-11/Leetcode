class Solution
{
public:
    int dp[500][500];
    int solve(int l, int r, vector<int> &prefix)
    {
        if (l == r)
            return 0;

        int res = 0;
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
        for (int i = l + 1; i <= r; i++)
        {
            int leftSum = prefix[i - 1] - (l == 0 ? 0 : prefix[l - 1]);
            int rightSum = prefix[r] - prefix[i - 1];
            if (leftSum == rightSum)
            {
                res = max({res,
                           leftSum + solve(l, i - 1, prefix),
                           rightSum + solve(i, r, prefix)});
            }
            else if (leftSum < rightSum)
            {
                res = max(leftSum + solve(l, i - 1, prefix), res);
            }
            else
            {
                res = max(res, rightSum + solve(i, r, prefix));
            }
        }
        return dp[l][r] = res;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        vector<int> prefix(stoneValue.size());
        prefix[0] = stoneValue[0];
        for (int i = 1; i < stoneValue.size(); i++)
        {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, prefix.size() - 1, prefix);
    }
};