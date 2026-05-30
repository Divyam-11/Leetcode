class Solution
{
public:
    int minFlips(string s)
    {   if(s.size() == 1) return 0;
        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zero_count++;
            else
                one_count++;
        }
        int res = s.size();
        res = min(res, zero_count);
        res = min(res, one_count);
        if (one_count)
            res = min(res, one_count - 1);
        int cost = 0;
        if (s[0] == '0')
            one_count++;
        if (s.back() == '0')
            one_count++;
        res = min(res, one_count - 2);
        return res;
    }
};