class Solution
{
public:
    long long calculateScore(string s)
    {
        long long score = 0;
        vector<vector<int>> freq(26);
        for (int i = 0; i < s.size(); i++)
        {
            int mirror = ('z' - s[i]);
            if (freq[mirror].size() > 0)
            {
                score += i - freq[mirror].back() ;
                freq[mirror].pop_back();
            }
            else
            {
                freq[s[i]-'a'].push_back(i);
            }
        }
        return score;
    }
};