class Solution
{
const int mod = 1e9+7;
public:
    int solve(int curr, int delay, int forget, int n,vector<int> &dp)
    {
        if (curr > n)
            return 0;
        if(dp[curr] != -1) return dp[curr];
        long long ans = 0;
        for (int i = curr + delay; i <curr+ forget; i++)
        {
            ans += solve(i, delay, forget, n,dp)%mod;
        }
        if(n < curr+forget) ans++;
        ans = ans % mod;
        return dp[curr] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {   vector<int> dp(n+1,-1);
        return solve(1, delay, forget, n,dp);
    }
};