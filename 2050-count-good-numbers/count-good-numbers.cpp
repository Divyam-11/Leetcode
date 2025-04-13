class Solution
{
    const int MOD = 1e9 + 7;

public:
    long long myPow(long long x, long long n)
    {
        if (n == 0)
            return 1;
        long long half = myPow(x, n / 2);
        long long result = (half * half) % MOD;
        if (n % 2 == 1)
        {
            result = (result * x) % MOD;
        }
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long result = (myPow(5, even) * myPow(4, odd)) % MOD;
        return (int)(result);
    }
};
