class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        vector<int> dp(energy.size());
        for (int i = 0; i < k; i++)
        {
            dp[i] = energy[i];
        }
        for (int i = k; i < energy.size(); i++)
        {
            // can take prev or kinda new start
            dp[i] = max(energy[i], energy[i] + dp[i - k]);
        }
        int res = INT_MIN;
        for (int i = energy.size() - 1; k>0; i--)
        {   
            res = max(res, dp[i]);
            k--;
        }
        return res;
    }
};