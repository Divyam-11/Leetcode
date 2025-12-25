class Solution
{
public:
    bool isPrime(int x)
    {
        for (int d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
                return false;
        }
        return x >= 2;
    }
    int largestPrime(int n)
    {
        int res = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isPrime(i))
            {
                sum += i;
            }
            if (isPrime(sum))
            {
                if (sum > n)
                    break;
                res = sum;
            }
        }
        return res;
    }
};