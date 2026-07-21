class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int prev_zero_count = -1;
        int freq = 0;
        int ones_count = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                freq++;
            if (s[i] == '1' && freq != 0)
            {
                if (prev_zero_count == -1)
                {
                    prev_zero_count = freq;
                }
                else
                {
                    res = max(res, freq + prev_zero_count);
                    prev_zero_count = freq;
                }
                freq = 0;
            }
            if (s[i] == '1')
                ones_count++;
        }
        if (freq != 0 && prev_zero_count != -1)
        {
            res = max(res, freq + prev_zero_count);
        }
        return res + ones_count;
    }
};