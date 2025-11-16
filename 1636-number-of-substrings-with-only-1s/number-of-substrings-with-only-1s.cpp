class Solution
{
public:
    const int MOD = 1e9 + 7;
    int numSub(string s)
    {
        long long res = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                len++;
            }
            if (s[i] == '0')
            {
                res += (len *1LL* (len + 1)) / 2;
                
                len = 0;
            }
        }
            res += (len * (len + 1)) / 2;
                
                len = 0;
        return res % MOD;
    }
};