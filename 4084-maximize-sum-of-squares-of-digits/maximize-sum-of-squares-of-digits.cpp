class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if (num < (int)log10(sum) + 1)
            return "";
        string s(num, '0');
        for (int i = 0; i < s.size(); i++)
        {
            if (sum >= 9)
            {
                sum -= 9;
                s[i] = '9';
            }
            else
            {
                s[i] = sum + '0';
                sum = 0;
            }
        }
        if (sum != 0)
            return "";
        return s;
    }
};