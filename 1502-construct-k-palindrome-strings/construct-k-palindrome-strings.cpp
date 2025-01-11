class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (s.size() < k)
            return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        int odd_freq = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
                odd_freq++;
        }
        if (odd_freq > k)
            return false;
        return true;
    }
};