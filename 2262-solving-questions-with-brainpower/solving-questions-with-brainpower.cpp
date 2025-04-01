class Solution
{
    long long helper(int index, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (index >= questions.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        long long pick = questions[index][0] + helper(index + questions[index][1] + 1, questions, dp);
        long long not_pick = helper(index + 1, questions, dp);
        
        return dp[index] = max(pick, not_pick);
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size(),-1);
        return helper(0, questions, dp);
    }
};