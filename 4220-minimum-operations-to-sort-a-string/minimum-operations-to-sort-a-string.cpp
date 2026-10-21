class Solution
{
public:
    int minOperations(string s)
    {
        
        if (is_sorted(s.begin(), s.end()))
            return 0;
        if(s.size() == 2) return -1;
        char minChar = 'z';
        int minIdx = -1;
        char maxChar = 'a';
        int maxIdx = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < minChar)
            {
                minIdx = i;
                minChar = s[i];
            }
            if (s[i] >= maxChar)
            {
                maxIdx = i;
                maxChar = s[i];
            }
        }
        if (s[0] == minChar || s.back() == maxChar)
            return 1;
        if (minIdx == s.size() - 1 && maxIdx == 0)
            return 3;
        return 2;
    }
};