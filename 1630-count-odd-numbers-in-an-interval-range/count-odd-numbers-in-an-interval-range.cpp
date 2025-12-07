class Solution
{
public:
    int countOdds(int low, int high)
    {   if(low == high)
        return high % 2 == 1;
    
        int gap = high - low - 1;
        if (high % 2 != low % 2)
        {
            return gap / 2 + 1;
        }
        if (high % 2 == 1)
        {
            return gap / 2 + 2;
        }
        else
        {
            return gap / 2 + 1;
        }
    }
};