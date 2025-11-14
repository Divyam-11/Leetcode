class Solution
{
public:
    int solve(int index, string s, vector<int> &dp)
    {
        if (index > s.size())
            return 0;
        if (index == s.size())
            return 1;
        if (s[index] == '0')
            return dp[index] = 0;
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int one_pick = solve(index + 1, s,dp);
        int two_pick_count = 0;
        if (index + 1 < s.size())
        {
            string two_pick;
            two_pick.push_back(s[index]);
            two_pick.push_back(s[index + 1]);
            if (stoi(two_pick) <= 26 && stoi(two_pick) > 9)
            {
                two_pick_count = solve(index + 2, s,dp);
            }
        }
        return dp[index] = one_pick + two_pick_count;
    }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s, dp);
    }
};