class Solution
{
public:
    int binaryGap(int n)
    {
        int gap = 0;
        int idx = -1;

        for (int i = 0; i < 32; i++)
        {
            int bit = n & 1;
            n = n >> 1;
            if (bit == 1)
            {
                if (idx == -1)
                {
                    idx = i;
                }
                else
                {
                    gap = max(gap, abs(i - idx));
                    idx = i;
                }
            }
        }
        return gap;
    }
};