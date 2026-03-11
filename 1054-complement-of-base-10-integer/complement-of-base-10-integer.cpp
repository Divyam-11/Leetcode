class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if(n == 0) return 1;
        int bitCount = (int)log2(n) + 1;
        
        int num = 1 << bitCount;
        num--;
        
        return num - n;
    }
};