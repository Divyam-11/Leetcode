class Solution
{
public:
    bool isBeautiful(int n)
    {
        vector<int> freq(10);
        while (n != 0)
        {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        for (int i = 0; i < 10; i++)
        {
            if (freq[i])
            {
                if (freq[i] != i)
                    return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i < 1224444; i++)
        {
            if (isBeautiful(i))
                return i;   
                }
        return 1224444;
    }
};