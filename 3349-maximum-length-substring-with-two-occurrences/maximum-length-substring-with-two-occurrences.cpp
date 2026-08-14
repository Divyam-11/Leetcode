class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int res = 1;
        
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> freq(26);
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'a']++;
                bool flag = true;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 2)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};