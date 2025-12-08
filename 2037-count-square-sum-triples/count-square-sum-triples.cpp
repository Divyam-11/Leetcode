class Solution
{
public:
    int countTriples(int n)
    {
        int res = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                int c_square = a * a + b * b;
                int c = sqrt(c_square);
                if (c <= n)
                {
                    if (c_square == c * c)
                        res++;
                }
            }
        }
        return res;
    }
};