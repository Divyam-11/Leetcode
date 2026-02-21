class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int setBits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right)
    {
        int res = 0;
        for (int i = left; i <= right; i++)
        {
            res += isPrime(setBits(i));
        }
        return res;
    }
};