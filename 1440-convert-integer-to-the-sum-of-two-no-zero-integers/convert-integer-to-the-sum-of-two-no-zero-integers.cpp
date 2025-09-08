class Solution
{
public:
    bool hasZero(int num)
    {   
        while (num != 0)
        {
            int dig = num % 10;
            num /= 10;
            if (dig == 0)
                return true;
        }
        
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        int i = 1;
        while (i<=n)
        {
            if (!hasZero(i) && !hasZero(n-i))
                return {i, n-i};
            i++;
        }
        return {-1, -1};
    }
};