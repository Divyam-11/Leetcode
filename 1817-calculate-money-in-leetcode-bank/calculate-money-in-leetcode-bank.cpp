    class Solution
    {
    public:
        int totalMoney(int n)
        {
            int x = n / 7;
            int a = x + 3;
            int res = 7 * (((a * (a + 1)) / 2) - 6);
            int rem = n % 7;
            x++;
            while (rem)
            {
                res += x;
                x++;
                rem--;
            }
            return res;
        }
    };