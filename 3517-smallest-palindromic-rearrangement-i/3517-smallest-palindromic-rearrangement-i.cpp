class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        string res;
        char odd = '*';
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
                {
                    odd = i + 'a';
                    freq[i]--;
                }
            
            res += string(freq[i] / 2, i + 'a');
        }
        string res2 = res;
        if (odd != '*')
            res.push_back(odd);
        reverse(res2.begin(), res2.end());
        return res + res2;
    }
};