class Solution
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        int mark = 60;
        if (n <= target)
            return 0;
        string temp = to_string(n);
        temp = "0" + temp;
        string res(temp.size(), '0');
        long long sum = 0;
        for (int i = 1; i < temp.size(); i++)
        {
            int digit = temp[i] - '0';
            if (sum + digit < target)
            {
                res[i] = temp[i];
            }
            else
            {
                mark = min(mark, i - 1);
                
            }
            sum += digit;
        }
        if (sum <= target)
            return 0;
        // res[mark]++;/
        int mark_from_back = temp.size() - mark-1;
        long long x = stoll(res);
        x += pow(10, mark_from_back);
        return x - n;
    }
};