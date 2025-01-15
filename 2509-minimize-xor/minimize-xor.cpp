class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int n = __builtin_popcount(num2); 
        bitset<32> num1_bits(num1);
        bitset<32> ans_bits;

        
        for (int i = 31; i >= 0 && n > 0; i--)
        {
            if (num1_bits[i])
            {
                ans_bits[i] = 1;
                n--;
            }
        }

        
        for (int i = 0; i < 32 && n > 0; i++)
        {
            if (!ans_bits[i])
            {
                ans_bits[i] = 1;
                n--;
            }
        }

        return (int)ans_bits.to_ulong();
    }
};