class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if (i < s.size() && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < s.size() && s[i] == '+')
        {
            sign = 1;
            i++;
        }
        long long res = 0;
        while (i < s.size())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                res = res * 10;
                res += s[i] - '0';
            }
            else
                break;
            if (res >= INT_MAX)
                break;
            if (res <= INT_MIN)
                break;
            i++;
        }
        res = res * sign;
        if (res >= INT_MAX)
            return INT_MAX;
        if (res <= INT_MIN)
            return INT_MIN;
        return res;
    }
};