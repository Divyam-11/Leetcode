class Solution
{
public:
    int minOperations(string s1, string s2)
    {
        if (s1.size() == 1 && s1[0] == '1' && s2[0] == '0')
            return -1;
        int ops = 0;
        int i;
        for (i = 0; i < s1.size() - 1; i++)
        {
            if (s1[i] == '0' && s2[i] == '1')
                ops++;
            if (s1[i] == '1' && s2[i] == '0')
            {
                i++;
                if (s1[i] == s2[i])
                    ops += 2;
                else if (s1[i] == '1' && s2[i] == '0')
                    ops++;
                else
                    ops += 3;
            }
        }
        if (i < s1.size())
        {
                        if (s1.back() == '1' && s2.back() == '0')
                ops += 2;
                if(s1.back() == '0' && s2.back() == '1') ops++;
        }
        return ops;
    }
};