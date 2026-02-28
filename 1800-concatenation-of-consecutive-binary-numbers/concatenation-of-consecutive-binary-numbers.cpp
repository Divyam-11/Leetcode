class Solution
{
public:
    const int MOD = 1e9 + 7;
    int concatenatedBinary(int n)
    {
        long long res = 0;
        for (int i = 1; i <= n; i++)
        {
            int numBits = (int)log2(i)+1;
            res = res << numBits;
            res = res | i;
            res = res % MOD;
        }
        return res;
    }
};